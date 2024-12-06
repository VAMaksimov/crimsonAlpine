#include "s21_sprintf.h"

size_t get_uint_length(unsigned long long v, format_value values) {
  size_t len = 1;
  if (v < 0) v = -v, ++len;
  if (values.specifier_value == OCTAL_SPEC)
    len += (size_t)((log(v) / log(8)));
  else if (values.specifier_value == x_SPEC || values.specifier_value == X_SPEC)
    len += (size_t)((log(v) / log(16)));
  else
    len += ((size_t)log10(v));
  if (values.flag_value == HASH_FLAG && values.specifier_value == OCTAL_SPEC)
    ++len;
  return len;
}