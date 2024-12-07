#include "s21_sprintf.h"

// void zero_ouput(char *buffer, size_t *index, format_value values) {
//   size_t len = 1;
//   if (values.precision_exist) len = max(1, values.precision_value);
//   case_zero_padding(buffer, index, values, len, 1, '+');
// }

int trim_zeros(char *buffer, size_t *index, size_t old_index) {
  size_t i = (*index) - 1, r = 0;
  while ((buffer[i] == '.' || buffer[i] == '0') && i >= old_index) {
    bool f = buffer[i] == '.';
    (*index)--, ++r, buffer[i--] = ' ';
    if (f) i = -1;
  }
  return r;
}

void itoa(void *c, char *buffer, size_t *index, format_value values) {
  unsigned long long n = *(unsigned long long *)c;
  if (n == 0) {
    if (!values.precision_exist || values.precision_value != 0)
      buffer[(*index)++] = '0';
  } else {
    char s_v = values.specifier_value;
    int base_System = define_base_System(s_v);
    int len = get_uint_length(n, values) - 1;
    for (int i = len; i >= 0; --i) {
      unsigned long long x = n % base_System;
      n /= base_System;
      buffer[(*index) + i] =
          (x < 10) ? (x + '0') : (x - 10 + (s_v == 'x' ? 'a' : 'A'));
    }
    *index += len + 1;
  }
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

void integer_ftoa(const long double *c, char *buffer, size_t *index, int precision) {
  long double v = *c;
  int len_v = 0;
  if (truncl(v) != 0) len_v = ((int)log10l(v));
  if (precision != 0 ) ++len_v;
  for (int i = len_v; i >= 0; --i) {
    buffer[(*index) + i] = ((int)fmodl(v, 10)) + '0';
    v /= 10;
    if (precision != 0 && i == len_v - precision + 1) buffer[(*index) + --i] = '.';
  }
  *index += len_v + 1;
}

void round_ftoa(const long double *c, char *buffer, size_t *index,
                size_t old_index) {
  if ((*c) * 10 > 5) {
    int i = (*index) - 1;
    while (buffer[i] == '9' && (size_t)i >= old_index) {
      buffer[i--] = '0';
    }
    if (buffer[i--] == '.') {
      while (buffer[i] == '9' && i >= 0) {
        buffer[i--] = '0';
      }
      if ((size_t)i == old_index - 1) {
        s21_memmove(&buffer[i + 2], &buffer[i + 1], i);
        buffer[i + 1] = '1';
        ++(*index);
      } else
        buffer[i]++;
    } else {
      if ((size_t)i == old_index - 2) {
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

void ftoa(void *c, char *buffer, size_t *index, format_value values) {
  // if (values.precision_exist && values.precision_value == 0) return buffer;
  long double v = *((long double *)c);
  // if ((int)log10l(v) + 1 < 16) {
  //long double integer_value = 0;
  //long double fractional_value = modfl(v, &integer_value);
  size_t old_index = *index;
  integer_ftoa(&v, buffer, index, values.precision_value);
  // if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
  //   buffer[(*index)++] = '.';
  // fractional_ftoa(&fractional_value, buffer, index, values.precision_value);
  // round_ftoa(&fractional_value, buffer, index, old_index);
  if ((values.specifier_value == g_SPEC || values.specifier_value == G_SPEC) &&
      !(values.flag_value & HASH_FLAG)) {
    int r = 0;
    if (values.precision_value != 0) r = trim_zeros(buffer, index, old_index);

    if ((!(values.flag_value & LEFT_JUSTIFY_FLAG)) &&
        (size_t)values.width_value > (*index - old_index + 1)) {
      s21_memmove(&buffer[old_index + r - 1], &buffer[old_index - 1],
                  *index - old_index + 1);
      for (int i = 0; i < r; ++i) buffer[old_index + i - 1] = ' ';
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

void etoa(void *c, char *buffer, size_t *index, format_value values) {
  char local_spec = values.specifier_value;
  if (local_spec == g_SPEC) local_spec = 'e';
  if (local_spec == G_SPEC) local_spec = 'E';
  size_t old_index = *index;
  long double v = *((long double *)c);
  int e = exponent(v);

  buffer[(*index)++] = ((int)v) + '0';
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
    buffer[(*index)++] = '.';
  v -= (int)v;
  fractional_ftoa(&v, buffer, index, values.precision_value);
  // round_ftoa(&v, buffer, index, old_index);
  if ((values.specifier_value == g_SPEC || values.specifier_value == G_SPEC) &&
      !(values.flag_value & HASH_FLAG))
    trim_zeros(buffer, index, old_index);
  buffer[(*index)++] = local_spec;
  buffer[(*index)++] = e < 0 ? '-' : '+';
  if (e < 0) e = -e;
  buffer[(*index)++] = '0';
  buffer[(*index)] = '0';
  // long double e_copy = e;
  if (e > 9) --(*index);
  // integer_ftoa(&e_copy, buffer, index);
}

void stoa(void *c, char *buffer, size_t *index, format_value values) {
  char *v = (char *)c;
  size_t len = s21_strlen(v);
  if (values.precision_exist) len = min(len, values.precision_value);
  s21_memcpy(buffer + *index, v, len);
  *index += len;
}
