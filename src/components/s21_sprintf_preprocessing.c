#include "s21_sprintf.h"

void formated_char(char *buffer, size_t *index, va_list factor,
                   format_value values) {
  unsigned long int c;
  long len = 1;
  if (!values.length_value || values.length_value == SHORT_INT_LENGTH)
    c = (unsigned long int)va_arg(factor, int);
  if (values.length_value == LONG_INT_LENGTH) {
    c = va_arg(factor, unsigned long int);
    len = (int)(c / 255) + 1;
  }
  if (values.flag_value & ZERO_PADDING_FLAG ||
      values.flag_value & SIGN_PRECEDENCE_FLAG)
    values.flag_value = 0;
  if (values.precision_exist) values.precision_value = 0;
  format_flag_(buffer, index, values, &c, len, ' ', ctoa);
}

void formated_int(char *buffer, size_t *index, va_list factor,
                  format_value values) {
  long long v = 0;
  if (!values.length_value) v = va_arg(factor, int);
  if (values.length_value == SHORT_INT_LENGTH) v = va_arg(factor, int);
  if (values.length_value == LONG_INT_LENGTH) v = va_arg(factor, long);
  if (values.length_value == LONG_LONG_INT_LENGTH)
    v = va_arg(factor, long long);

  size_t len = 1;
  char sign = '+';
  if (v < 0)
    v = -v, ++len, sign = '-';
  else if (values.flag_value & NO_SIGN_FLAG)
    ++len;
  len += ((size_t)log10(v));

  unsigned long long r = v;
  format_flag_(buffer, index, values, &r, len, sign, itoa);
}

void formated_uint(char *buffer, size_t *index, va_list factor,
                   format_value values) {
  unsigned long long v = 0;
  if (!values.length_value) v = va_arg(factor, unsigned int);
  if (values.length_value == SHORT_INT_LENGTH) v = va_arg(factor, unsigned int);
  if (values.length_value == LONG_INT_LENGTH) v = va_arg(factor, unsigned long);
  if (values.length_value == LONG_LONG_INT_LENGTH)
    v = va_arg(factor, unsigned long long);
  if (values.flag_value & SIGN_PRECEDENCE_FLAG ||
      values.flag_value & NO_SIGN_FLAG)
    values.flag_value = 0;
  size_t len = 1;
  if (v != 0) {
    len = get_uint_length(v, values);
  } else {
    if (values.precision_exist && values.precision_value == 0) len = 0;
    values.flag_value = 0;
  }
  format_flag_(buffer, index, values, &v, len, '+', itoa);
}

void formated_string(char *buffer, size_t *index, va_list factor,
                     format_value values) {
  char *v = va_arg(factor, char *);
  size_t len = s21_strlen(v);
  if (values.precision_exist)
    len = values.precision_value > len ? len : values.precision_value;
  s21_strncpy(buffer + *index, v, len);
  *index += len;
}

void formated_n(const size_t *index, va_list factor) {
  int *v = va_arg(factor, int *);
  *v = *index;
}

void formated_pointer(char *buffer, size_t *index, va_list factor,
                      format_value values) {
  void *v = va_arg(factor, void *);
  uintptr_t address = (uintptr_t)v;
  values.specifier_value = OCTAL_SPEC;
  values.flag_value |= HASH_FLAG;
  format_flag_(buffer, index, values, &address, 0, '+', itoa);
}

void formated_float(char *buffer, size_t *index, va_list factor,
                    format_value values) {
  long double v = 0;
  if (!values.length_value) v = va_arg(factor, double);
  if (values.length_value == LONG_LONG_INT_LENGTH)
    v = va_arg(factor, long double);
  if (!values.precision_exist) values.precision_value = STANDARD_PRECISION;
  size_t len = 1;
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG)
    len += values.precision_value + 1;
  char sign = '+';
  if (v < 0) v = -v, ++len, sign = '-';
  if (roundl(v) != 0) len += ((size_t)log10l(v));
  if (values.specifier_value == FLOAT_SPEC) {
    format_flag_(buffer, index, values, &v, len, sign, ftoa);
  } else if (values.specifier_value == e_SPEC ||
             values.specifier_value == E_SPEC) {
    len += 4;
    format_flag_(buffer, index, values, &v, len, sign, etoa);
  }
  // else if (values.specifier_value == 'g' || values.specifier_value == 'G') {}
}

/**
 * @brief Write a formatted string to the buffer according to the given
 *        format_value, sign and write_to_buffer function.
 *
 * @param buffer The buffer to write to.
 * @param index The position in the buffer to start writing at.
 * @param values The format specifications.
 * @param c The value to format.
 * @param len The length of the formatted string.
 * @param sign The sign of the formatted string.
 * @param write_to_buffer The function to use to write the formatted string.
 */
void format_flag_(char *buffer, size_t *index, format_value values, void *c,
                  size_t len, char sign,
                  void (*write_to_buffer)(void *c, char *buffer, size_t *index,
                                          format_value values)) {
  int new_len = len > values.precision_value ? len : values.precision_value;

  case_blank_padding(buffer, index, values, new_len);

  if (sign == '-' || values.flag_value & SIGN_PRECEDENCE_FLAG)
    buffer[(*index)++] = sign;
  if (sign == '+' && values.flag_value & NO_SIGN_FLAG) buffer[(*index)++] = ' ';

  if (values.flag_value & HASH_FLAG)
    flag_hash_execusion(buffer, index, values.specifier_value);

  case_zero_padding(buffer, index, values, new_len, len, sign);

  write_to_buffer(c, buffer, index, values);

  case_left_justify(buffer, index, values, new_len);
}

/**
 * @brief Function that handles a '#' flag
 * @param buffer - the string to write to
 * @param index - the position in the buffer
 * @param specifier - the type specifier
 * @note
 * Used with o, x or X specifiers the value is preceded with 0, 0x or 0X
 * respectively for values different than zero. Used with e, E and f, it forces
 * the written output to contain a decimal point even if no digits would
 * follow. By default, if no digits follow, no decimal point is written. Used
 * with g or G the result is the same as with e or E but trailing zeros are not
 * removed.
 */
void flag_hash_execusion(char *buffer, size_t *index, char specifier) {
  if (specifier == x_SPEC) {
    buffer[(*index)++] = '0';
    buffer[(*index)++] = 'x';
  } else if (specifier == X_SPEC) {
    buffer[(*index)++] = '0';
    buffer[(*index)++] = 'X';
  } else if (specifier == OCTAL_SPEC) {
    buffer[(*index)++] = '0';
  }
}

void case_blank_padding(char *buffer, size_t *index, format_value values,
                        int new_len) {
  if (values.width_value > new_len &&
      !(values.flag_value & LEFT_JUSTIFY_FLAG) &&
      !(values.flag_value & ZERO_PADDING_FLAG)) {
    s21_memset(buffer + (*index), ' ', values.width_value - new_len);
    *index += values.width_value - new_len;
  }
}

void case_zero_padding(char *buffer, size_t *index, format_value values,
                       int new_len, size_t len, char sign) {
  if (values.flag_value & ZERO_PADDING_FLAG && values.width_value > new_len &&
      values.specifier_value != FLOAT_SPEC &&
      !(values.flag_value & LEFT_JUSTIFY_FLAG)) {
    s21_memset(buffer + (*index), '0', values.width_value - new_len);
    *index += values.width_value - new_len;
  }
  if (values.precision_value != 0 && values.precision_value > len &&
      values.specifier_value != FLOAT_SPEC) {
    if (sign == '-') values.precision_value += 1;
    s21_memset(buffer + (*index), '0', values.precision_value - len);
    *index += values.precision_value - len;
  }
}

void case_left_justify(char *buffer, size_t *index, format_value values,
                       int new_len) {
  if (values.flag_value & LEFT_JUSTIFY_FLAG && values.width_value > new_len) {
    s21_memset(buffer + (*index), ' ', values.width_value - new_len);
    *index += values.width_value - new_len;
  }
}
