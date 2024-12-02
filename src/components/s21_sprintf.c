#include "../s21_string.h"

void itoa(void *c, char *buffer, size_t *index, format_value values) {
  unsigned long long n = *(unsigned long long *)c;
  char s_v = values.specifier_value;
  int base_System = s_v == 'x' || s_v == 'X' ? 16 : 10;
  base_System = s_v == 'o' ? 8 : base_System;
  if (n > 0) {
    unsigned long long x = n % base_System;
    unsigned long long next_n = n / base_System;
    itoa(&next_n, buffer, index, values);
    buffer[(*index)++] =
        (x < 10) ? (x + '0') : (x - 10 + (s_v == 'x' ? 'a' : 'A'));
  }
}

void itoa_for_zero(void *c, char *buffer, size_t *index, format_value values) {
  if (values.precision_exist && values.precision_value == 0) return;
  unsigned int n = *(unsigned int *)c;
  buffer[(*index)] = '0' + n;
  buffer[(*index)++] = '0';
}

void ctoa(void *c, char *buffer, size_t *index, format_value values) {
  if (values.precision_exist) values.precision_value = 0;
  int *i = (int *)c;
  buffer[(*index)++] = *i;
}

void integer_ftoa(long double *c, char *buffer, size_t *index) {
  long double v = *c;
  int len_v = 0;
  if (truncl(v) != 0) len_v = ((int)log10l(v));
  for (int i = len_v; i >= 0; --i) {
    buffer[(*index) + i] = ((int)fmodl(v, 10)) + '0';
    v /= 10;
  }
  *index += len_v + 1;
}

void s21_memmove(char *dest, const char *src, size_t n) {
  if (dest < src) {
    for (size_t i = 0; i < n; i++) {
      dest[i] = src[i];
    }
  } else if (dest > src) {
    for (size_t i = n; i > 0; i--) {
      dest[i - 1] = src[i - 1];
    }
  }
}

void round_ftoa(long double *c, char *buffer, size_t *index) {
  if ((*c) * 10 > 5) {
    int i = (*index) - 1;
    while (buffer[i] == '9' && i >= 0 && buffer[i] != '.') {
      if (buffer[i] == '.') {
        --i;
      } else
        buffer[i--] = '0';
    }
    if (buffer[i--] == '.') {
      while (buffer[i] == '9' && i >= 0) {
        buffer[i--] = '0';
      }
      if (i < 0) {
        s21_memmove(&buffer[1], &buffer[0], *index);
        buffer[0] = '1';
        ++(*index);
      } else {
        buffer[i]++;
      }
    } else {
      if (i < 0) {
        s21_memmove(&buffer[1], &buffer[0], *index);
        buffer[0] = '1';
        ++(*index);

      } else {
        buffer[++i]++;
      }
    }
  }
}

void fractional_ftoa(long double *c, char *buffer, size_t *index,
                     int precision) {
  for (int i = 0; i < precision; ++i) {
    (*c) *= 10;
    int digit = (int)truncl((*c));
    buffer[(*index)++] = digit + '0';
    (*c) -= digit;
  }
}

void ftoa(void *c, char *buffer, size_t *index, format_value values) {
  // if (values.precision_exist && values.precision_value == 0) return buffer;
  long double v = *((long double *)c);
  long double integer_value = 0;
  long double fractional_value = modfl(v, &integer_value);
  integer_ftoa(&integer_value, buffer, index);
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
    buffer[(*index)++] = '.';
  fractional_ftoa(&fractional_value, buffer, index, values.precision_value);
  round_ftoa(&fractional_value, buffer, index);
}

void etoa(void *c, char *buffer, size_t *index, format_value values) {
  long double v = *((long double *)c);
  int e = 0;
  if (v == 0)
    ;
  else if (v >= 10) {
    while (v >= 10) {
      v /= 10;
      e++;
    }
  } else if (v < 1) {
    while (v < 1 && (int)(v * 10) != 9) {
      v *= 10;
      e--;
    }
  }
  buffer[(*index)++] = ((int)v) + '0';
  if (values.precision_value != 0 || values.flag_value == '#')
    buffer[(*index)++] = '.';
  v -= (int)v;
  fractional_ftoa(&v, buffer, index, values.precision_value);
  round_ftoa(&v, buffer, index);
  buffer[(*index)++] = values.specifier_value;
  buffer[(*index)++] = e < 0 ? '-' : '+';
  if (e < 0) e = -e;
  buffer[(*index)++] = '0';
  buffer[(*index)] = '0';
  long double e_copy = e;
  integer_ftoa(&e_copy, buffer, index);
}

void flag_hash_execusion(char *buffer, size_t *index, char specifier) {
  if (specifier & x_SPEC) {
    buffer[(*index)++] = '0';
    buffer[(*index)++] = 'x';
  } else if (specifier & X_SPEC) {
    buffer[(*index)++] = '0';
    buffer[(*index)++] = 'X';
  } else if (specifier & OCTAL_SPEC) {
    buffer[(*index)++] = '0';
  }
}

void format_flag_(char *buffer, size_t *index, format_value values, void *c,
                  size_t len, char sign,
                  void (*write_to_buffer)(void *c, char *buffer, size_t *index,
                                          format_value values)) {
  char b = ' ';
  if (values.width_value > (int)len &&
      !(values.flag_value & LEFT_JUSTIFY_FLAG) &&
      !(values.flag_value & ZERO_PADDING_FLAG)) {
    s21_memset(buffer + (*index), b, values.width_value - len);
    *index += values.width_value - len;
  }
  if (sign == '-' || values.flag_value & SIGN_PRECEDENCE_FLAG)
    buffer[(*index)++] = sign;
  if (values.flag_value & NO_SIGN_FLAG)
    if (sign != '-') buffer[(*index)++] = ' ';
  if (values.flag_value == '#') {
    flag_hash_execusion(buffer, index, values.specifier_value);
  }
  if (values.flag_value == '0' || values.precision_value != 0) {
    if (values.width_value > (int)len && values.specifier_value != 'f') {
      s21_memset(buffer + (*index), '0', values.width_value - len);
      *index += values.width_value - len;
    } else if (values.precision_value > len && values.specifier_value != 'f') {
      if (sign == '-') values.precision_value += 1;
      s21_memset(buffer + (*index), '0', values.precision_value - len);
      *index += values.precision_value - len;
    }
  }
  write_to_buffer(c, buffer, index, values);
  if (values.flag_value == '-' && values.width_value > (int)len) {
    s21_memset(buffer + (*index), b, values.width_value - len);
    *index += values.width_value - len;
  }
}

void formated_char(char *buffer, size_t *index, va_list factor,
                   format_value values) {
  char c = va_arg(factor, int);
  if (values.precision_exist) values.precision_value = 0;
  format_flag_(buffer, index, values, &c, 1, ' ', ctoa);
}

void formated_int(char *buffer, size_t *index, va_list factor,
                  format_value values) {
  long long v = 0;
  if (!values.length_value) v = va_arg(factor, int);
  if (values.length_value & SHORT_INT_LENGTH) v = va_arg(factor, int);
  if (values.length_value & LONG_INT_LENGTH) v = va_arg(factor, long);
  if (values.length_value & LONG_DOUBLE_LENGTH) v = va_arg(factor, long long);
  if (v != 0) {
    size_t len = 1;
    char sign = v < 0 ? '-' : '+';
    if (v != 0) len = ((size_t)log10(v < 0 ? -v : v)) + 1;
    if (v < 0) v = -v, ++len;
    unsigned long long r = v;
    format_flag_(buffer, index, values, &r, len, sign, itoa);
  } else
    format_flag_(buffer, index, values, &v, 1, '+', itoa_for_zero);
}

void formated_uint(char *buffer, size_t *index, va_list factor,
                   format_value values) {
  unsigned long long v = 0;
  if (!values.length_value) v = va_arg(factor, unsigned int);
  if (values.length_value & SHORT_INT_LENGTH) v = va_arg(factor, unsigned int);
  if (values.length_value & LONG_INT_LENGTH) v = va_arg(factor, unsigned long);
  if (values.length_value & LONG_DOUBLE_LENGTH)
    v = va_arg(factor, unsigned long long);
  if (v != 0) {
    size_t len = 1;
    char sign = '+';
    if (v != 0) len = ((size_t)log10(v)) + 1UL;
    format_flag_(buffer, index, values, &v, len, sign, itoa);
  } else
    format_flag_(buffer, index, values, &v, 1, '+', itoa_for_zero);
}

void formated_string(char *buffer, size_t *index, va_list factor,
                     format_value values) {
  char *v = va_arg(factor, char *);
  size_t len = s21_strlen(v);
  if (values.precision_exist)
    len = values.precision_value > len ? len : values.precision_value;
  s21_memcpy(buffer, v, len);
  *index += len;
}

void formated_n(size_t *index, va_list factor) {
  int *v = va_arg(factor, int *);
  *v = *index;
}

void formated_pointer(char *buffer, size_t *index, va_list factor,
                      format_value values) {
  void *v = va_arg(factor, void *);
  uintptr_t address = (uintptr_t)v;
  values.specifier_value |= OCTAL_SPEC;
  values.flag_value |= HASH_FLAG;
  format_flag_(buffer, index, values, &address, 0, '+', itoa);
}

void formated_float(char *buffer, size_t *index, va_list factor,
                    format_value values) {
  long double v = 0;
  if (!values.length_value) v = va_arg(factor, double);
  if (values.length_value & LONG_DOUBLE_LENGTH) v = va_arg(factor, long double);
  if (!values.precision_exist) values.precision_value = 6;
  size_t len = 1;
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
    len += values.precision_value + 1;
  char sign = '+';
  if (v < 0) v = -v, ++len, sign = '-';
  if (roundl(v) != 0) len += ((size_t)log10l(v));
  format_flag_(buffer, index, values, &v, len, sign, ftoa);
}

void formated_exp(char *buffer, size_t *index, va_list factor,
                  format_value values) {
  long double v = 0;
  if (!values.length_value) v = va_arg(factor, double);
  if (values.length_value & LONG_DOUBLE_LENGTH) v = va_arg(factor, long double);
  if (!values.precision_exist) values.precision_value = 6;
  size_t len = 1;
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
    len += values.precision_value + 1;
  char sign = '+';
  if (v < 0) v = -v, ++len, sign = '-';
  if (roundl(v) != 0) len += ((size_t)log10l(v));
  len += 4;
  format_flag_(buffer, index, values, &v, len, sign, etoa);
}

void formated_g(char *buffer, size_t *index, va_list factor,
                format_value values) {
  long double v = 0;
  if (!values.length_value) v = va_arg(factor, double);
  if (values.length_value & LONG_DOUBLE_LENGTH) v = va_arg(factor, long double);
  if (!values.precision_exist) values.precision_value = 1;
  size_t len = 1;
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
    len += values.precision_value + 1;
  char sign = '+';
  if (v < 0) v = -v, ++len, sign = '-';
  if (roundl(v) != 0) len += ((size_t)log10l(v));
  format_flag_(buffer, index, values, &v, len, sign, etoa);
}

// void format_execusion(char *buffer, size_t *index, format_value values,
//                       va_list factor) {
//   if (values.specifier_value & CHAR_SPEC)
//     formated_char(buffer, index, factor, values);
//   else if (values.specifier_value == 'd' || values.specifier_value == 'i')
//     formated_int(buffer, index, factor, values);
//   else if (values.specifier_value == 'e' || values.specifier_value == 'E')
//     formated_exp(buffer, index, factor, values);
//   else if (values.specifier_value == 'f')
//     formated_float(buffer, index, factor, values);
//   //   else if (values.specifier_value == 'g' || values.specifier_value ==
//   'G')
//   //     formated_g(buffer, index, factor, values);
//   else if (values.specifier_value == 'o')
//     formated_uint(buffer, index, factor, values);
//   else if (values.specifier_value == 's')
//     formated_string(buffer, index, factor, values);
//   else if (values.specifier_value == 'u')
//     formated_uint(buffer, index, factor, values);
//   else if (values.specifier_value == 'x' || values.specifier_value == 'X')
//     formated_uint(buffer, index, factor, values);
//   else if (values.specifier_value == 'p')
//     formated_pointer(buffer, index, factor, values);
//   else if (values.specifier_value == 'n')
//     formated_n(index, factor);
// }

const char *format_parser(char *buffer, size_t *index, const char *p,
                          va_list factor, format_value values) {
  while (!values.specifier_value) {
    if (*p == '%') {
      buffer[(*index)++] = '%';
    } else if (s21_strchr("-+ #0", *p))
      flag_parser(p, &values);
    else if (s21_strchr("123456789*", *p))
      width_parser(&p, &values, factor);
    else if (*p == '.') {
      ++p;
      precision_parser(&p, &values, factor);
    } else if (s21_strchr("hlL", *p))
      length_parser(p, &values);
    else
      specifier_parser(p, &values);
    ++p;
  }
  //   format_execusion(buffer, index, values, factor);
  return p;
}

int s21_sprintf(char *buffer, const char *format, ...) {
  if (format == NULL) return 0;
  const char *p = format;
  size_t index = 0;
  va_list factor;
  va_start(factor, format);
  bool flag = false;
  while (p == NULL || *p == '\0') {
    //[флаги][ширина][.точность][длина][спецификатор]
    format_value values = {0};
    while (*p != '%' && *p != '\0') {  // Переписать на s21_strncpy
      buffer[index++] = *p++;
    }
    if (*p == '\0') p = format_parser(buffer, &index, ++p, factor, values);
  }

  va_end(factor);
  buffer[index] = '\0';
  return (int)s21_strlen(buffer);
}

// char *insert(const char *src, const char *str, size_t start_index) {
//     size_t len_str = s21_strlen(str);
//     size_t len_src = s21_strlen(src);
//     char *res = malloc(len_src + len_str + 1);
//     size_t len_res = 0;
//     s21_strncpy(res, src, start_index);
//     s21_strncat(res, str, len_str);
//     s21_strncat(res, src + start_index, len_src - start_index);
//     res[len_src + len_str] = '\0';
//     return res;
// }

int main() {
#include <string.h>
  char text[100];
  s21_sprintf(text, "333%01i333", -10);
  printf("2text: %s\n\n", text);
  sprintf(text, "333%01i333", -10);
  printf("2text: %s\n\n", text);

  char buffer1[50];
  float test_values[10] = {
      0,      1.2345,  -1.2345,          12345.6789,        -12345.6789,
      0.0001, -0.0001, 123456789.123456, -123456789.123456, 3.141592653589793};

  for (int i = 0; i < 10; i++) {
    sprintf(buffer1, "%e", test_values[i]);
    printf("Test %d: %s\n", i, buffer1);
    s21_sprintf(buffer1, "%e", test_values[i]);
    printf("Test %d: %s\n", i, buffer1);
  }

  float ja = 43560.1;
  sprintf(buffer1, "%f", ja);
  printf("Test : %s\n", buffer1);
  s21_sprintf(buffer1, "%f", ja);
  printf("Test : %s\n", buffer1);

  return 0;
}

// int main(void) {
// // Тест 1: Поиск подстроки, которая есть в строке
// const char *haystack1 = "Hello, world!";
// const char *needle1 = "world";
// char *result1 = strstr(haystack1, needle1);
// // Ожидаемый результат: указатель на "world" в строке "Hello, world!"
// printf("Test 1: %s\n", result1); // Ожидается: "world!"

// // Тест 2: Поиск подстроки, которой нет в строке
// const char *haystack2 = "Hello, world!";
// const char *needle2 = "test";
// char *result2 = strstr(haystack2, needle2);
// // Ожидаемый результат: NULL, так как "test" не содержится в строке
// printf("Test 2: %s\n", result2 ? result2 : "NULL"); // Ожидается: "NULL"

// // Тест 3: Поиск подстроки в начале строки
// const char *haystack3 = "Hello, world!";
// const char *needle3 = "Hello";
// char *result3 = strstr(haystack3, needle3);
// // Ожидаемый результат: указатель на "Hello" в строке "Hello, world!"
// printf("Test 3: %s\n", result3); // Ожидается: "Hello, world!"

// // Тест 4: Поиск пустой подстроки
// const char *haystack4 = "Hello, world!";
// const char *needle4 = "";
// char *result4 = strstr(haystack4, needle4);
// // Ожидаемый результат: указатель на начало строки "Hello, world!"
// printf("Test 4: %s\n", result4); // Ожидается: "Hello, world!"

// char str[] = "---Особенности национальной рыбалки - художественный,
// комедийный фильм";
// //char str[] = "---Features of National Fishing - a feature film, comedy";

// size_t len = strlen (str);
// char * pch = strtok (str," ,.-"); // во втором параметре указаны
// разделитель (пробел, запятая, точка, тире)
// //printf ("Строка: %s\n", pch);
// while (pch != NULL)                         // пока есть лексемы
// {
//     putchar('\t');
//     for (int i = 0; i < len; i++) {
//         putchar(str[i] != 0? str[i] : '0');
//     }
//     putchar('\n');
//     printf ("%s\n", pch);
//     pch = strtok(NULL, " ,.-");
// }
// Тест 1: Вставка в пустую строку
// char str1[] = ""; // Массив размером 6 (для 5 символов + '\0')
// char *result1 = insert(str1, "A", 0);
// // Ожидаемый результат: str1 = "A", size1 = 1
// printf("Test 1: %s\n", result1); // Ожидается: "A
// // Тест 2: Вставка в начало строки
// char str2[] = "BCD";
// char *result2 = insert(str2, "A", 0);
// // Ожидаемый результат: str2 = "ABCD", size2 = 4
// printf("Test 2: %s\n", result2); // Ожидается: "ABCD
// // Тест 3: Вставка в конец строки
// char str3[] = "ABC";
// int size3 = 3;
// char *result3 = insert(str3, "D", size3);
// // Ожидаемый результат: str3 = "ABCD", size3 = 4
// printf("Test 3: %s\n", result3); // Ожидается: "ABCD
// // Тест 4: Вставка в середину строки
// char str4[] = "ABD";
// char *result4 = insert(str4, "C", 1);
// // Ожидаемый результат: str4 = "ABCD", size4 = 4
// printf("Test 4: %s\n", result4); // Ожидается: "ABCD
// free(result1);
// free(result2);
// free(result3);
// free(result4);
// #include <math.h>
// printf("Test :%d \n", ((int)log10(0)) + 1);

// char o[] = "Name: %-10c  Age: %c\n";
// s21_sprintf(text, o, 'c', '2');

// printf ("1text: %s", text);
// sprintf(text, o, 'c', '2');
// printf ("2text: %s", text);
// printf("text length: %d", charNumber);

// printf("\t%ld\n", sizeof(int));

// printf("Test :%lfd \n", (fmod(7.0, 1.0)));

// char y[] = "Hello world!";
// printf("%s\n", (char *)s21_memchr(y, 'l', 10));

// char buffer[50];
// int result;

// // Тест 1: Нормальное положительное число
// result = sprintf(buffer, "%.5s", "123");
// printf("Test 1: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "%.5s", "123");
// printf("Test 1: %d, Output: %s, Result: %d\n", result, buffer, result);

// // Тест 2: Нормальное отрицательное число
// result = sprintf(buffer, "%.5d", -100);
// printf("Test 2: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "%.5d", -100);
// printf("Test 2: %d, Output: %s, Result: %d\n", result, buffer, result);

// // Тест 3: Ноль
// result = sprintf(buffer, "%.0d", 0);
// printf("Test 3: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "%.0d", 0);
// printf("Test 3: %d, Output: %s, Result: %d\n", result, buffer, result);

// // Тест 6: Положительное число с ведущими нулями
// result = sprintf(buffer, "%.5d", 42);
// printf("Test 6: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "%.5d", 42);
// printf("Test 6: %d, Output: %s, Result: %d\n", result, buffer, result);

// // Тест 7: Отрицательное число с ведущими нулями
// result = sprintf(buffer, "%05d", -42);
// printf("Test 7: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "%05d", -42);
// printf("Test 7: %d, Output: %s, Result: %d\n", result, buffer, result);

// // Тест 8: Положительное число с пробелами
// result = sprintf(buffer, "% d", 42);
// printf("Test 8: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "% d", 42);
// printf("Test 8: %d, Output: %s, Result: %d\n", result, buffer, result);
// // Тест 9: Отрицательное число с пробелами
// result = sprintf(buffer, "% d", -42);
// printf("Test 9: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "% d", -42);
// printf("Test 9: %d, Output: %s, Result: %d\n", result, buffer, result);

// // Тест 10: Положительное число с шириной
// result = sprintf(buffer, "%10d", 42);
// printf("Test 10: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "%10d", 42);
// printf("Test 10: %d, Output: %s, Result: %d\n", result, buffer, result);

// result = sprintf(buffer, "%+d", 42);
// printf("Test 11: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "%+d", 42);
// printf("Test 11: %d, Output: %s, Result: %d\n", result, buffer, result);

// int p = 0;
// result = sprintf(buffer, "%+d", -42);
// printf("Test 12: %d, Output: %s, Result: %d\n", result, buffer, result);
// result = s21_sprintf(buffer, "%+d", -42);
// printf("Test 12: %d, Output: %s, Result: %d\n", result, buffer, result);
// printf("%d\n", p);

// long double ld = 5;
// for (int i = 0; i != 400; ++i) ld *= 10;
// sprintf(buffer1, "%.0Lf", ld);
// printf("Test : %s\n", buffer1);
// s21_sprintf(buffer1, "%Lf", ld);
// printf("Test : %s\n", buffer1);

//   return 0;
// }
