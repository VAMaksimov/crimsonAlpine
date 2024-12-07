#include "s21_sprintf.h"

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
