#include "s21_sprintf.h"

int get_uint_length(unsigned long long value, format_value values) {
  int len = 1;
  if (values.specifier_value == OCTAL_SPEC)
    len += exponent(value, OCTAL_BASE);
  else if (values.specifier_value == x_SPEC || values.specifier_value == X_SPEC)
    len += exponent(value, HEXADECIMAL_BASE);
  else
    len += exponent(value, DECIMAL_BASE);
  // if (values.flag_value & HASH_FLAG && values.specifier_value == OCTAL_SPEC)
  //   ++len;
  return len;
}

int define_base_System(char spec) {
  int base_System =
      spec == x_SPEC || spec == X_SPEC ? HEXADECIMAL_BASE : DECIMAL_BASE;
  base_System = spec == OCTAL_SPEC ? OCTAL_BASE : base_System;

  return base_System;
}

int exponent(long double value, int base) {
  long double temp = abs(value);
  int exp = 0;
  if (temp != 0) {
    if (temp >= base) {
      while (temp >= base) {
        temp /= base;
        exp++;
      }
    } else if (temp < 1) {
      while (temp < 1 && temp != 0) {
        temp *= base;
        exp--;
      }
    }
  }
  return exp;
}

long double round_to_precision(long double value, format_value values) {
  long double temp = roundl(value * pow(10, values.precision_value));
  return (temp * pow(0.1, values.precision_value));
}
