#include "s21_sprintf.h"

int get_uint_length(unsigned long long value, format_value values) {
  int len = 1;
  if (values.specifier_value == OCTAL_SPEC)
    len += (int)((log(value) / log(OCTAL_BASE)));
  else if (values.specifier_value == x_SPEC || values.specifier_value == X_SPEC)
    len += (int)((log(value) / log(HEXADECIMAL_BASE)));
  else
    len += ((int)log10(value));
  if (values.flag_value & HASH_FLAG && values.specifier_value == OCTAL_SPEC)
    ++len;
  return len;
}

int define_base_System(char spec) {
  int base_System =
      spec == x_SPEC || spec == X_SPEC ? HEXADECIMAL_BASE : DECIMAL_BASE;
  base_System = spec == OCTAL_SPEC ? OCTAL_BASE : base_System;

  return base_System;
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