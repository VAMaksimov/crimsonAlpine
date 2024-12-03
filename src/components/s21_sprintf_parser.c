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
    values->length_value = LONG_DOUBLE_LENGTH;
  } else if (**p == 'l')
    values->length_value = LONG_INT_LENGTH;
  else if (**p == 'h')
    values->length_value = SHORT_INT_LENGTH;
}
