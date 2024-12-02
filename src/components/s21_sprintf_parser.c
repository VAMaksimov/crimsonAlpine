#include "../s21_string.h"

int number_parser(const char **p) {
  int res = 0;
  while (s21_strchr("0123456789", **p)) {
    res = res * 10 + (**p - '0');
    ++(*p);
  }
  --(*p);
  return res;
}

void flag_parser(const char *p, format_value *values) {
  switch (*p) {
    case '-':
      values->flag_value |= LEFT_JUSTIFY_FLAG;
      break;
    case '+':
      values->flag_value |= SIGN_PRECEDENCE_FLAG;
      break;
    case ' ':
      values->flag_value |= NO_SIGN_FLAG;
      break;
    case '#':
      values->flag_value |= HASH_FLAG;
      break;
    case '0':
      values->flag_value |= ZERO_PADDING_FLAG;
      break;
    default:
      break;
  }
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

void length_parser(const char *p, format_value *values) {
  if (*p == 'l' && *(p + 1) == 'l') {
    ++p;
    values->length_value |= LONG_DOUBLE_LENGTH;
  } else if (*p == 'l')
    values->length_value |= LONG_INT_LENGTH;
  else if (*p == 'h')
    values->length_value |= SHORT_INT_LENGTH;
}

void specifier_parser(const char *p, format_value *values, char *buffer,
                      size_t *index, va_list factor) {
  switch (*p) {
    case 'c':
      values->specifier_value |= CHAR_SPEC;
      formated_char(buffer, index, factor, values);
      break;
    case 'd':
      values->specifier_value |= DECIMAL_INT_SPEC;
      formated_int(buffer, index, factor, values);
      break;
    case 'i':
      values->specifier_value |= MULTI_BASE_INT_SPEC;
      formated_int(buffer, index, factor, values);
      break;
    case 'e':
      values->specifier_value |= e_SPEC;
      formated_exp(buffer, index, factor, values);
      break;
    case 'E':
      values->specifier_value |= E_SPEC;
      formated_exp(buffer, index, factor, values);
      break;
    case 'f':
      values->specifier_value |= FLOAT_SPEC;
      formated_float(buffer, index, factor, values);
      break;
    case 'g':
      values->specifier_value |= g_SPEC;
      formated_g(buffer, index, factor, values);
      break;
    case 'G':
      values->specifier_value |= G_SPEC;
      formated_g(buffer, index, factor, values);
      break;
    case 'o':
      values->specifier_value |= OCTAL_SPEC;
      formated_uint(buffer, index, factor, values);
      break;
    case 's':
      values->specifier_value |= STRING_SPEC;
      formated_string(buffer, index, factor, values);
      break;
    case 'u':
      values->specifier_value |= UNSIGNED_DECIMAL_SPEC;
      formated_uint(buffer, index, factor, values);
      break;
    case 'x':
      values->specifier_value |= x_SPEC;
      formated_uint(buffer, index, factor, values);
      break;
    case 'X':
      values->specifier_value |= X_SPEC;
      formated_uint(buffer, index, factor, values);
      break;
    case 'p':
      values->specifier_value |= POINTER_SPEC;
      formated_pointer(buffer, index, factor, values);
      break;
    case 'n':
      values->specifier_value |= COUNT_OF_CHARS_INSIDE_SPEC;
      formated_n(index, factor);
      break;
    case '%':
      values->specifier_value |= PERCENT_CHAR_SPEC;
      break;
    default:
      break;
  }
}