#include "s21_sprintf.h"

int main() {
  char str[100];
  char my_str[100];
  sprintf(str, "Hello, %d, %d", 123, 'a');
  printf("%s\n", str);
  s21_sprintf(my_str, "Hello, %d, %d", 123, 'a');
  printf("%s\n", my_str);
  return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
  char specifiers_stack[100] = {0};
  int spec_count = 0;

  va_list args;
  va_start(args, format);  // Initialize args to point to additional arguments
  char object_to_insert[100];
  char ch;
  for (size_t i = 0; format[i] != '\0'; i++) {
    ch = format[i];
    if (ch == '%') {
      if (is_valid_specifier(format[++i])) {
        specifiers_stack[spec_count++] = format[i];
      }
    }
  }

  change_in_place(str, format, args, object_to_insert, specifiers_stack);

  size_t char_count;

  va_end(args);  // Clear the va_list
  return char_count;
}

void change_in_place(char *str, const char *format, char *args,
                     char *object_to_insert, const char *specifiers_stack) {
  for (size_t format_ind = 0, output_ind = 0, spec_ind = 0;
       format[format_ind] != '\0'; format_ind++) {
    char ch = format[format_ind];
    if (ch == '%') {
      format_ind++;
      if (specifiers_stack[spec_ind] != '\0') {
        variable_to_string(specifiers_stack[spec_ind++], args,
                           object_to_insert);
        str[output_ind++] = object_to_insert[0];
      }
    } else {
      str[output_ind++] = ch;
      format_ind++;
    }
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
      *object_to_insert = va_arg(args, int);
      break;

    case 'd':
      *object_to_insert = va_arg(args, int);
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
