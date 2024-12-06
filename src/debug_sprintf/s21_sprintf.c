#include "../s21_string.h"
#include "test_me.h"

int number_parser(const char **p) {
  int res = 0;
  while (s21_strchr("0123456789", **p)) {
    res = res * 10 + (**p - '0');
    ++(*p);
  }
  --(*p);
  return res;
}

void width_parser(const char **p, format_value *values, va_list factor) {
  if (**p == '*')
    values->width_value = va_arg(factor, int);
  else
    values->width_value = number_parser(p);
}

void precision_parser(const char **p, format_value *values, va_list factor) {
  values->precision_exist = true;
  if (**p == '*')
    values->precision_value = va_arg(factor, int);
  else
    values->precision_value = number_parser(p);
}

void length_parser(const char **p, format_value *values) {
  if (**p == 'l' && *(*p + 1) == 'l') {
    ++(*p);
    values->length_value = LONG_LONG_INT_LENGTH;
  } else
    values->length_value = **p;
}

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
  if (values.length_value != LONG_INT_LENGTH) {
    unsigned long int *i = (unsigned long int *)c;
    buffer[(*index)++] = *i;
  } else {
    unsigned long int n = *(unsigned long int *)c;
    for (int j = 7; j >= 0; --j)
      if ((n >> (j * 8)) & 0xFF) buffer[(*index)++] = (n >> (j * 8)) & 0xFF;
  }
}

void integer_ftoa(const long double *c, char *buffer, size_t *index) {
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

void round_ftoa(const long double *c, char *buffer, size_t *index,
                size_t old_index) {
  if ((*c) * 10 > 5) {
    int i = (*index) - 1;
    while (buffer[i] == '9' && i >= old_index) {
      buffer[i--] = '0';
    }
    if (buffer[i--] == '.') {
      while (buffer[i] == '9' && i >= 0) {
        buffer[i--] = '0';
      }
      if (i == old_index - 1) {
        s21_memmove(&buffer[i + 2], &buffer[i + 1], i);
        buffer[i + 1] = '1';
        ++(*index);
      } else
        buffer[i]++;
    } else {
      if (i == old_index - 2) {
        s21_memmove(&buffer[i + 2], &buffer[i + 1], i);
        buffer[i + 2] = '1';
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

int trim_zeros(char *buffer, size_t *index, size_t old_index) {
  int i = (*index) - 1, r = 0;
  while (( buffer[i] == '.' || buffer[i] == '0') && i >= old_index) {
    bool f = buffer[i] == '.';
    (*index)--, ++r, buffer[i--] = ' ';
    if (f) i = -1;
  }
  return r;
}

void ftoa(void *c, char *buffer, size_t *index, format_value values) {
  // if (values.precision_exist && values.precision_value == 0) return buffer;
  long double v = *((long double *)c);
  // if ((int)log10l(v) + 1 < 16) {
  long double integer_value = 0;
  long double fractional_value = modfl(v, &integer_value);
  size_t old_index = *index;
  integer_ftoa(&integer_value, buffer, index);
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
    buffer[(*index)++] = '.';
  fractional_ftoa(&fractional_value, buffer, index, values.precision_value);
  round_ftoa(&fractional_value, buffer, index, old_index);
  if ((values.specifier_value == g_SPEC || values.specifier_value == G_SPEC) && !(values.flag_value & HASH_FLAG)) {
      int r = 0;
      if(values.precision_value != 0)r =trim_zeros(buffer, index, old_index);
      
      if ((!(values.flag_value & LEFT_JUSTIFY_FLAG)) && values.width_value > *index - old_index + 1) {
        s21_memmove(&buffer[old_index + r - 1], &buffer[old_index - 1], *index - old_index +1);
        for (int i = 0; i < r; ++i) buffer[old_index+i-1] = ' ';
      }
        *index += r;
    }
  // } else {
  //   integer_ftoa(&v, buffer, index);
  //   if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
  //     buffer[(*index)++] = '.';
  //   s21_memset(buffer + *index, '0', values.precision_value);
  //   *index += values.precision_value;
  // }
}

int exponent(long double *v) {
  int e = 0;
  if (*v == 0)
    ;
  else if (*v >= 10) {
    while (*v >= 10) {
      *v /= 10;
      e++;
    }
  } else if (*v < 1) {
    while (*v < 1 && (int)(*v * 10) != 9) {
      *v *= 10;
      e--;
    }
  }
  return e;
}

void etoa(void *c, char *buffer, size_t *index, format_value values) {
  char local_spec = values.specifier_value;
  if (local_spec == g_SPEC) local_spec = 'e';
  if (local_spec == G_SPEC) local_spec = 'E';
  size_t old_index = *index;
  long double v = *((long double *)c);
  int e = exponent(&v);

  buffer[(*index)++] = ((int)v) + '0';
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
    buffer[(*index)++] = '.';
  v -= (int)v;
  fractional_ftoa(&v, buffer, index, values.precision_value);
  round_ftoa(&v, buffer, index, old_index);
  if ((values.specifier_value == g_SPEC || values.specifier_value == G_SPEC) && !(values.flag_value & HASH_FLAG))
    trim_zeros(buffer, index, old_index); 
  buffer[(*index)++] = local_spec;
  buffer[(*index)++] = e < 0 ? '-' : '+';
  if (e < 0) e = -e;
  buffer[(*index)++] = '0';
  buffer[(*index)] = '0';
  long double e_copy = e;
  if (e > 9) --(*index);
  integer_ftoa(&e_copy, buffer, index);
}

void stoa(void *c, char *buffer, size_t *index, format_value values) {
  char *v = (char *)c;
  size_t len = s21_strlen(v);
  if (values.precision_exist)
    len = len > values.precision_value ? values.precision_value : len;
  s21_memcpy(buffer + *index, v, len);
  *index += len;
}

void flag_hash_execusion(char *buffer, size_t *index, char specifier) {
  if (specifier == x_SPEC) {
    buffer[(*index)++] = '0';
    buffer[(*index)++] = 'x';
  } else if (specifier == X_SPEC) {
    buffer[(*index)++] = '0';
    buffer[(*index)++] = 'X';
  } else if (specifier == OCTAL_SPEC) {
    buffer[(*index)++] = '0';
  }
}

void format_flag_(char *buffer, size_t *index, format_value values, void *c,
                  size_t len, char sign,
                  void (*write_to_buffer)(void *c, char *buffer, size_t *index,
                                          format_value values)) {
  char b = ' ';
  if (sign == '-' && s21_strchr("diouxX", values.specifier_value))
    values.precision_value += 1;
  int new_len = len > values.precision_value ? len : values.precision_value;
  if (values.width_value > new_len &&
      !(values.flag_value & LEFT_JUSTIFY_FLAG) &&
      !(values.flag_value & ZERO_PADDING_FLAG)) {
    s21_memset(buffer + (*index), b, values.width_value - new_len);
    *index += values.width_value - new_len;
  }
  if (sign == '-' || values.flag_value & SIGN_PRECEDENCE_FLAG)
    buffer[(*index)++] = sign;
  else if (values.flag_value & NO_SIGN_FLAG && sign != ' ') {
    if (sign != '-') buffer[(*index)++] = ' ';
  }
  if (values.flag_value & HASH_FLAG) {
    flag_hash_execusion(buffer, index, values.specifier_value);
  }
  if (values.flag_value & ZERO_PADDING_FLAG) {
    if (values.width_value > new_len &&
        !(values.flag_value & LEFT_JUSTIFY_FLAG)) {
      s21_memset(buffer + (*index), '0', values.width_value - new_len);
      *index += values.width_value - new_len;
    }
  }
  if (values.precision_value != 0) {
    if (values.precision_value > len && values.specifier_value != FLOAT_SPEC &&
        values.specifier_value != STRING_SPEC) {
      s21_memset(buffer + (*index), '0', values.precision_value - len);
      *index += values.precision_value - len;
    }
  }
  write_to_buffer(c, buffer, index, values);
  if (values.flag_value & LEFT_JUSTIFY_FLAG && values.width_value > new_len) {
    s21_memset(buffer + (*index), b, values.width_value - new_len);
    *index += values.width_value - new_len;
  }
}

void formated_char(char *buffer, size_t *index, va_list factor,
                   format_value values) {
  unsigned long int c;
  long len = 1;
  if (values.length_value == LONG_INT_LENGTH) {
    c = va_arg(factor, unsigned long int);
    len = (int)(c / 255) + 1;
  } else
    c = (unsigned long int)va_arg(factor, int);
  if (values.flag_value & ZERO_PADDING_FLAG)
    values.flag_value -= ZERO_PADDING_FLAG;
  if (values.flag_value & SIGN_PRECEDENCE_FLAG)
    values.flag_value -= SIGN_PRECEDENCE_FLAG;
  if (values.precision_exist) values.precision_value = 0;
  format_flag_(buffer, index, values, &c, len, ' ', ctoa);
}

void formated_int(char *buffer, size_t *index, va_list factor,
                  format_value values) {
  long long v = 0;
  if (!values.length_value) v = va_arg(factor, int);
  if (values.length_value == SHORT_INT_LENGTH) v = va_arg(factor, int);
  if (values.length_value == LONG_INT_LENGTH) v = va_arg(factor, long);
  if (values.length_value == LONG_LONG_INT_LENGTH)
    v = va_arg(factor, long long);
  if (v != 0) {
    size_t len = 1;
    char sign = '+';
    if (v < 0)
      v = -v, ++len, sign = '-';
    else if (values.flag_value & NO_SIGN_FLAG)
      ++len;
    len += ((size_t)log10(v));
    unsigned long long r = v;
    format_flag_(buffer, index, values, &r, len, sign, itoa);
  } else {
    int len = 1;
    if (values.precision_exist && values.precision_value == 0) len = 0;
    format_flag_(buffer, index, values, &v, len, '+', itoa_for_zero);
  }
}

void formated_uint(char *buffer, size_t *index, va_list factor,
                   format_value values) {
  unsigned long long v = 0;
  if (!values.length_value) v = va_arg(factor, unsigned int);
  if (values.length_value == SHORT_INT_LENGTH) v = va_arg(factor, unsigned int);
  if (values.length_value == LONG_INT_LENGTH) v = va_arg(factor, unsigned long);
  if (values.length_value == LONG_LONG_INT_LENGTH)
    v = va_arg(factor, unsigned long long);
  if (values.flag_value & SIGN_PRECEDENCE_FLAG)
    values.flag_value -= SIGN_PRECEDENCE_FLAG;
  if (values.flag_value & NO_SIGN_FLAG) values.flag_value -= NO_SIGN_FLAG;
  if (v != 0) {
    size_t len = 1;
    if (values.specifier_value == OCTAL_SPEC)
      len += (size_t)((log(v) / log(8)));
    else if (values.specifier_value == x_SPEC ||
             values.specifier_value == X_SPEC)
      len += (size_t)((log(v) / log(16)));
    else
      len += ((size_t)log10(v));
    if (values.flag_value & HASH_FLAG && values.specifier_value == OCTAL_SPEC)
      ++len;
    format_flag_(buffer, index, values, &v, len, '+', itoa);
  } else {
    int len = 1;
    if (values.precision_exist && values.precision_value == 0) len = 0;
    values.flag_value = 0;
    format_flag_(buffer, index, values, &v, len, '+', itoa_for_zero);
  }
}

void formated_string(char *buffer, size_t *index, va_list factor,
                     format_value values) {
  char *v = va_arg(factor, char *);
  if (v == NULL) {
    v = "(null)";
    if (values.precision_value < 6) values.precision_value = 0;
  }
  size_t len = s21_strlen(v);
  if (values.precision_exist)
    len = len > values.precision_value ? values.precision_value : len;
  values.precision_value = len;
  values.flag_value &= LEFT_JUSTIFY_FLAG;
  format_flag_(buffer, index, values, v, len, ' ', stoa);
}

void formated_n(const size_t *index, va_list factor) {
  int *v = va_arg(factor, int *);
  *v = *index;
}

void formated_pointer(char *buffer, size_t *index, va_list factor,
                      format_value values) {
  void *v = va_arg(factor, void *);
  uintptr_t address = (uintptr_t)v;

  if (v != 0) {
    int len = 0;
    if (v != NULL) len = (logl(address) / log(16)) + 1;
    if (values.flag_value & LEFT_JUSTIFY_FLAG) len += 2;
    values.specifier_value = x_SPEC;
    values.flag_value |= HASH_FLAG;

    format_flag_(buffer, index, values, &address, len, '+', itoa);
  } else {
    values.flag_value = 0;
    values.precision_value = 0;
    values.precision_exist = 0;
    char *v = "(nil)";
    format_flag_(buffer, index, values, v, 5, '+', stoa);
  }
}

void formated_float(char *buffer, size_t *index, va_list factor,
                    format_value values) {
  long double v = 0;
  char local_spec = values.specifier_value;
  if (!values.length_value) v = va_arg(factor, double);
  if (values.length_value == LONG_DOUBLE_LENGTH)
    v = va_arg(factor, long double);
  size_t len = 1;
  if (!values.precision_exist) values.precision_value = STANDARD_PRECISION;
  if (local_spec == g_SPEC || local_spec == G_SPEC) {
    if (values.precision_value == 0) values.precision_value = 1;
    long double tmp = v;
    if (tmp < 0) tmp = -tmp;
    int x = exponent(&tmp);
    if (x > -4 && x < values.precision_value) {
      local_spec = FLOAT_SPEC;
      values.precision_value -= x + 1;
    } else {
      local_spec = g_SPEC ? e_SPEC : E_SPEC;
      values.precision_value -= 1;
    }
  }
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG )
    len += values.precision_value + 1;
  char sign = '+';
  if (v < 0) v = -v, ++len, sign = '-';
  if ((values.flag_value & SIGN_PRECEDENCE_FLAG ||
       values.flag_value & NO_SIGN_FLAG) &&
      sign != '-')
    len += 1;
  if (local_spec == FLOAT_SPEC) {
    if (roundl(v) != 0) len += ((size_t)log10l(v));
    format_flag_(buffer, index, values, &v, len, sign, ftoa);
  } else if (local_spec == e_SPEC ||
             local_spec == E_SPEC) {
    len += 4 ;
    int power = log10((long)log10l(v)) - 1;
    len += power > 0 ? power : 0;
    format_flag_(buffer, index, values, &v, len, sign, etoa);
  }
  // else if (values.specifier_value == 'g' || values.specifier_value == 'G') {}
}

// void formated_g(char *buffer, size_t *index, va_list factor,
//                 format_value values) {
//   long double v = 0;
//   if (!values.length_value) v = va_arg(factor, double);
//   if (values.length_value == LONG_LONG_INT_LENGTH) v = va_arg(factor, long double);
//   if (!values.precision_exist) values.precision_value = 1; 
//   size_t len = 1;
//   if (values.precision_value != 0 || values.flag_value == HASH_FLAG)
//     len += values.precision_value + 1;
//   char sign = '+';
//   if (v < 0) v = -v, ++len, sign = '-';
//   if (roundl(v) != 0) len += ((size_t)log10l(v));
//   format_flag_(buffer, index, values, &v, len, sign, etoa);
// }

void formated_percent(char *buffer, size_t *index, format_value values) {
  char v = '%';
  if (values.flag_value & ZERO_PADDING_FLAG)
    values.flag_value -= ZERO_PADDING_FLAG;
  if (values.flag_value & SIGN_PRECEDENCE_FLAG)
    values.flag_value -= SIGN_PRECEDENCE_FLAG;
  if (values.precision_exist) values.precision_value = 0;
  format_flag_(buffer, index, values, &v, 1, ' ', ctoa);
}

void format_execusion(char *buffer, size_t *index, format_value values,
                      va_list factor) {
  if (values.specifier_value == CHAR_SPEC)
    formated_char(buffer, index, factor, values);
  else if (values.specifier_value == DECIMAL_INT_SPEC ||
           values.specifier_value == MULTI_BASE_INT_SPEC)
    formated_int(buffer, index, factor, values);
  else if (values.specifier_value == e_SPEC ||
           values.specifier_value == E_SPEC ||
           values.specifier_value == FLOAT_SPEC ||
           values.specifier_value == g_SPEC || values.specifier_value == G_SPEC)
    formated_float(buffer, index, factor, values);
  else if (values.specifier_value == OCTAL_SPEC ||
           values.specifier_value == UNSIGNED_DECIMAL_SPEC ||
           values.specifier_value == x_SPEC || values.specifier_value == X_SPEC)
    formated_uint(buffer, index, factor, values);
  else if (values.specifier_value == STRING_SPEC)
    formated_string(buffer, index, factor, values);
  else if (values.specifier_value == POINTER_SPEC)
    formated_pointer(buffer, index, factor, values);
  else if (values.specifier_value == COUNT_OF_CHARS_INSIDE_SPEC)
    formated_n(index, factor);
  else if (values.specifier_value == PERCENT_CHAR_SPEC)
    formated_percent(buffer, index, values);
}

char flag_value(char c) {
  char r = 0;
  if (c == '-')
    r = LEFT_JUSTIFY_FLAG;
  else if (c == '+')
    r = SIGN_PRECEDENCE_FLAG;
  else if (c == ' ')
    r = NO_SIGN_FLAG;
  else if (c == '#')
    r = HASH_FLAG;
  else if (c == '0')
    r = ZERO_PADDING_FLAG;
  return r;
}

const char *format_parser(char *buffer, size_t *index, const char *p,
                          va_list factor, format_value values) {
  while (!values.specifier_value) {
    if (s21_strchr("-+ #0", *p))
      values.flag_value |= flag_value(*p);
    else if (s21_strchr("123456789*", *p))
      width_parser(&p, &values, factor);
    else if (*p == '.') {
      ++p;
      precision_parser(&p, &values, factor);
    } else if (s21_strchr("hlL", *p))
      length_parser(&p, &values);
    else if (s21_strchr("cdieEfgGosuxXpn%%", *p))
      values.specifier_value = *p;
    ++p;
  }
  format_execusion(buffer, index, values, factor);
  return p;
}

int s21_sprintf(char *buffer, const char *format, ...) {
  if (format == NULL) return 0;
  const char *p = format;
  size_t index = 0;
  va_list factor;
  va_start(factor, format);
  while (p != NULL && *p != '\0') {
    //[флаги][ширина][.точность][длина][спецификатор]
    format_value values = {0};
    while (*p != '%' && *p != '\0') {  // Переписать на s21_strncpy
      buffer[index++] = *p++;
    }
    if (*p != '\0') p = format_parser(buffer, &index, ++p, factor, values);
  }

  va_end(factor);
  buffer[index] = '\0';
  return index;  //(int)s21_strlen(buffer);
}

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
      test_sprintf_c(),       
      test_sprintf_e(),
              test_sprintf_g(),
      test_sprintf_octal(),   test_sprintf_percent(),  test_sprintf_n(),
      test_sprintf_string(),  test_sprintf_unsigned(), test_sprintf_HEX(),
      test_sprintf_hex(),     test_sprintf_signed(),   test_sprintf_signed_i(),
      test_sprintf_pointer(), test_sprintf_f(),
              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  char str1[100];
  char str2[100];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  sprintf(str1, str3, num, num, num, num, num);
  printf("%s\n\n", str1);
  s21_sprintf(str2, str3, num, num, num, num, num);
  printf("%s\n", str2);
}

/*
int main() {
#include <string.h>
  char text[100];
  s21_sprintf(text, "333%01i333", -10);
  printf("2text: %s\n\n", text);
  sprintf(text, "333%01i333", -10);
  printf("2text: %s\n\n", text);

  int result;
  char buffer[100];

  // Тест 1: Нормальное положительное число
  result = sprintf(buffer, "%.5s", "123");
  printf("Test 1: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "%.5s", "123");
  printf("Test 1: %d, Output: %s, Result: %d\n", result, buffer, result);

  // Тест 2: Нормальное отрицательное число
  result = sprintf(buffer, "%.5d", -100);
  printf("Test 2: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "%.5d", -100);
  printf("Test 2: %d, Output: %s, Result: %d\n", result, buffer, result);

  // Тест 3: Ноль
  result = sprintf(buffer, "%.0d", 0);
  printf("Test 3: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "%.0d", 0);
  printf("Test 3: %d, Output: %s, Result: %d\n", result, buffer, result);

  // Тест 6: Положительное число с ведущими нулями
  result = sprintf(buffer, "%.5d", 42);
  printf("Test 6: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "%.5d", 42);
  printf("Test 6: %d, Output: %s, Result: %d\n", result, buffer, result);

  // Тест 7: Отрицательное число с ведущими нулями
  result = sprintf(buffer, "%05d", -42);
  printf("Test 7: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "%05d", -42);
  printf("Test 7: %d, Output: %s, Result: %d\n", result, buffer, result);

  // Тест 8: Положительное число с пробелами
  result = sprintf(buffer, "% d", 42);
  printf("Test 8: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "% d", 42);
  printf("Test 8: %d, Output: %s, Result: %d\n", result, buffer, result);
  // Тест 9: Отрицательное число с пробелами
  result = sprintf(buffer, "% d", -42);
  printf("Test 9: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "% d", -42);
  printf("Test 9: %d, Output: %s, Result: %d\n", result, buffer, result);

  // Тест 10: Положительное число с шириной
  result = sprintf(buffer, "%10d", 42);
  printf("Test 10: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "%10d", 42);
  printf("Test 10: %d, Output: %s, Result: %d\n", result, buffer, result);

  result = sprintf(buffer, "%+d", 42);
  printf("Test 11: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "%+d", 42);
  printf("Test 11: %d, Output: %s, Result: %d\n", result, buffer, result);

  int p = 0;
  result = sprintf(buffer, "%+d", -42);
  printf("Test 12: %d, Output: %s, Result: %d\n", result, buffer, result);
  result = s21_sprintf(buffer, "%+d", -42);
  printf("Test 12: %d, Output: %s, Result: %d\n", result, buffer, result);
  printf("%d\n", p);

  char buffer1[50];
  float test_values[10] = {
      0,      1.2345,  -1.2345,          12345.6789,        -12345.6789,
      0.0001, -0.0001, 123456789.123456, -123456789.123456, 3.141592653589793};

  long double ld = 5;
  for (int i = 0; i != 400; ++i) ld *= 10;
  sprintf(buffer1, "%.0Lf", ld);
  printf("Test : %s\n", buffer1);
  s21_sprintf(buffer1, "%Lf", ld);
  printf("Test : %s\n", buffer1);

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
*/
