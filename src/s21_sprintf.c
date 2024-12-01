#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  char specifiers_stack[100] = {0};
  int spec_count = 0;

  va_list args;
  va_start(args, format);  // Initialize args to point to additional arguments
  char object_to_insert[100] = {0};
  char ch;
  for (size_t i = 0; format[i] != '\0'; i++) {
    ch = format[i];
    if (ch == '%') {
      if (is_valid_specifier(format[++i])) {
        specifiers_stack[spec_count++] = format[i];
      }
    }
  }
  size_t char_count;
  char_count =
      change_in_place(str, format, args, object_to_insert, specifiers_stack);

  va_end(args);  // Clear the va_list
  return char_count;
}

size_t change_in_place(char *str, const char *format, va_list args,
                       char *object_to_insert, const char *specifiers_stack) {
  size_t output_ind = 0;
  for (size_t format_ind = 0, spec_ind = 0; format[format_ind] != '\0';
       format_ind++) {
    char ch = format[format_ind];
    if (ch == '%') {
      format_ind++;
      if (specifiers_stack[spec_ind] != '\0') {
        variable_to_string(specifiers_stack[spec_ind++], args,
                           object_to_insert);
        insert_object(str, object_to_insert, &output_ind);
        reset_object(object_to_insert);
      }
    } else {
      str[output_ind++] = ch;
    }
  }
  return output_ind;
}

void reset_object(char *object_to_insert) {
  for (int i = 0; object_to_insert[i] != '\0'; i++) {
    object_to_insert[i] = '\0';
  }
}

void insert_object(char *str, const char *object_to_insert,
                   size_t *output_ind) {
  for (int i = 0; object_to_insert[i] != '\0'; i++) {
    str[(*output_ind)++] = object_to_insert[i];
  }
}

size_t get_integer_size(int num, int base) {
  size_t size = 0;
  while (num > 0) {
    num /= base;
    size++;
  }
  return size;
}

size_t get_float_size(double num, int base) {
  int integer_part = (int)num;
  double fractional_part = num - integer_part;
  size_t size = 0;
  if (integer_part != 0) {
    size = get_integer_size(integer_part, base);
  }
  if (fractional_part != 0) {
    size += 1 + get_integer_size((int)(fractional_part * FLOAT_FORMAT), base);
  }
  return size;
}

char *itoa(int num, char *object_to_insert, int base) {
  // size_t num_size = get_integer_size(num, base);
  bool is_negative = false;
  size_t i = 0;
  if (num < 0) {
    is_negative = true;
    num *= -1;
  }

  do {
    int rem = num % base;
    num /= base;
    object_to_insert[i++] = rem > 9 ? rem - 10 + 'a' : rem + '0';
  } while (num > 0);

  if (is_negative) {
    object_to_insert[i++] = '-';
  }
  s21_reverse_str(object_to_insert, i);
  return &object_to_insert[i];
}

// char *float_to_string(double num, char *object_to_insert) {
//   // size_t num_size = get_float_size(num, DECIMAL_BASE);
//   bool is_negative = false;
//   if (num < 0) {
//     is_negative = true;
//     num *= -1;
//   }
//   double integer_part = (int)num;
//   double fractional_part = num - integer_part;
//   char *temp = itoa((int)integer_part, object_to_insert, DECIMAL_BASE);
//   temp[0] = '.';
//   fractional_part *= FLOAT_FORMAT;
//   int fractional_int = (int)fractional_part;
//   fractional_int %= 1000000;  // Cut off all digits after 6th
//   itoa(fractional_int, temp + 1, DECIMAL_BASE);

//   if (is_negative) {
//     object_to_insert[0] = '-';
//   }

//   s21_reverse_str(object_to_insert, strlen(object_to_insert));

//   return object_to_insert;
// }

// void exp_to_string(double num, char *object_to_insert) {
//   int power = 0;
//   double temp = num;
//   while (temp > 1) {
//     temp /= 10;
//     power++;
//   }
//   object_to_insert[0] = 'e';
//   object_to_insert[1] = '+';
//   object_to_insert[2] = '\0';
//   itoa(power, object_to_insert + 2, DECIMAL_BASE);
// }

void s21_reverse_str(char *str, size_t len) {
  for (size_t i = 0, j = len - 1; i < j; i++, j--) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

/**
 * 1 c Character
 *
 * 2 d Signed decimal integer
 *
 * 4 e Scientific notation (mantissa/exponent) using e character (the output of
 * the numbers must match up to e-6)
 *
 * 5 E Scientific notation (mantissa/exponent) using E character
 *
 * 6 f Decimal floating point
 *
 * 7 g Uses the shortest representation of decimal floating point
 *
 * 8 G Uses the shortest representation of decimal floating point
 *
 * 9 o Unsigned octal
 *
 * 10 s String of characters
 *
 * 11 u Unsigned decimal integer
 *
 * 12 x Unsigned hexadecimal integer
 *
 * 13 X Unsigned hexadecimal integer (capital letters)
 *
 * 14 p Pointer address
 *
 * 15 n Number of characters printed until %n occurs
 *
 * 16 % Character %
 */
bool is_valid_specifier(const char retrieved_char) {
  bool valid = false;
  if (retrieved_char == 'c' || retrieved_char == 'd' || retrieved_char == 'i' ||
      retrieved_char == 'e' || retrieved_char == 'E' || retrieved_char == 'f' ||
      retrieved_char == 'g' || retrieved_char == 'G' || retrieved_char == 'o' ||
      retrieved_char == 's' || retrieved_char == 'u' || retrieved_char == 'x' ||
      retrieved_char == 'X' || retrieved_char == 'p' || retrieved_char == 'n' ||
      retrieved_char == '%') {
    valid = true;
  }
  return valid;
}

void variable_to_string(const char specifier, va_list args,
                        char *object_to_insert) {
  switch (specifier) {
    case 'c':
      itoa(va_arg(args, int), object_to_insert, DECIMAL_BASE);
      break;

    case 'd':
      itoa(va_arg(args, int), object_to_insert, DECIMAL_BASE);
      break;

    case 'e':
      *object_to_insert = va_arg(args, double);
      break;

    case 'E':
      *object_to_insert = va_arg(args, double);
      break;

    case 'f':
      *object_to_insert = va_arg(args, double);
      break;

    case 'g':
      *object_to_insert = va_arg(args, double);
      break;

    case 'G':
      *object_to_insert = va_arg(args, double);
      break;

    case 'o':
      *object_to_insert = va_arg(args, unsigned int);
      break;

      // case 's':
      //   *object_to_insert = (char *)va_arg(args, char *);
      //   break;

    case 'u':
      *object_to_insert = va_arg(args, unsigned int);
      break;

    case 'x':
      *object_to_insert = va_arg(args, unsigned int);
      break;

    case 'X':
      *object_to_insert = va_arg(args, unsigned int);
      break;

      // case 'p':
      //   *object_to_insert = (char *)va_arg(args, void *);
      //   break;

      // case 'n':
      //   *object_to_insert = (char *)va_arg(args, int *);
      //   break;

    case '%':
      *object_to_insert = '%';
      break;

    default:
      break;
  }
}

int main() {
  double my_num = 1.99999999;
  int count = 0;
  char str[100];
  count = sprintf(str, "Hello, %d, %d %f", 123, 'a', my_num);
  printf("%s\ncount = %d\n", str, count);

  char my_str[100];
  count = s21_sprintf(my_str, "Hello, %d, %d", 123, 'a');
  printf("%s\ncount = %d\n", my_str, count);
  return 0;
}
