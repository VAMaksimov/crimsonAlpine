#include "s21_sprintf.h"

void itoa(void *c, char *buffer, size_t *index, format_value values) {
  unsigned long long n = *(unsigned long long *)c;
  if (n == 0) {
    if (!values.precision_exist || values.precision_value != 0)
      buffer[(*index)++] = '0';
  } else {
    char s_v = values.specifier_value;
    int base_System = define_base_System(s_v);
    size_t len = get_uint_length(n, values);
    for (size_t i = len; i >= 0; --i) {
      unsigned long long x = n % base_System;
      n /= base_System;
      buffer[(*index) + i] =
          (x < 10) ? (x + '0') : (x - 10 + (s_v == 'x' ? 'a' : 'A'));
    }
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

void round_ftoa(const long double *c, char *buffer, size_t *index) {
  if ((*c) * 10 > 5) {
    int i = (*index) - 1;
    while (buffer[i] == '9' && i >= 0) {
      buffer[i--] = '0';
    }
    if (buffer[i--] == '.') {
      while (buffer[i] == '9' && i >= 0) {
        buffer[i--] = '0';
      }
      if (i < 0) {
        s21_memmove(&buffer[1], &buffer[0], *index);
        buffer[0] = '1';
        ++(*index);
      } else {
        buffer[i]++;
      }
    } else {
      if (i < 0) {
        s21_memmove(&buffer[1], &buffer[0], *index);
        buffer[0] = '1';
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
  long double integer_value = 0;
  long double fractional_value = modfl(v, &integer_value);
  integer_ftoa(&integer_value, buffer, index);
  if (values.precision_value != 0 || values.flag_value == HASH_FLAG)
    buffer[(*index)++] = '.';
  fractional_ftoa(&fractional_value, buffer, index, values.precision_value);
  round_ftoa(&fractional_value, buffer, index);
}

void etoa(void *c, char *buffer, size_t *index, format_value values) {
  long double v = *((long double *)c);
  int e = 0;
  if (v == 0)
    ;
  else if (v >= 10) {
    while (v >= 10) {
      v /= 10;
      e++;
    }
  } else if (v < 1) {
    while (v < 1 && (int)(v * 10) != 9) {
      v *= 10;
      e--;
    }
  }
  buffer[(*index)++] = ((int)v) + '0';
  if (values.precision_value != 0 || values.flag_value == HASH_FLAG)
    buffer[(*index)++] = '.';
  v -= (int)v;
  fractional_ftoa(&v, buffer, index, values.precision_value);
  round_ftoa(&v, buffer, index);
  buffer[(*index)++] = values.specifier_value;
  buffer[(*index)++] = e < 0 ? '-' : '+';
  if (e < 0) e = -e;
  buffer[(*index)++] = '0';
  buffer[(*index)] = '0';
  long double e_copy = e;
  integer_ftoa(&e_copy, buffer, index);
}