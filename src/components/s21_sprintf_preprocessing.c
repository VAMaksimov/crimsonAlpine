#include "s21_sprintf.h"

void formated_char(char *buffer, size_t *index, va_list factor,
                   format_value values) {
  unsigned long int c;
  long len = 1;

  if (values.length_value == LONG_INT_LENGTH) {
    c = va_arg(factor, unsigned long int);
    len = (int)(c / 255) + 1;
  } else
    c = (unsigned long int)va_arg(factor, int);

  if (values.flag_value & ZERO_PADDING_FLAG)
    values.flag_value -= ZERO_PADDING_FLAG;
  if (values.flag_value & SIGN_PRECEDENCE_FLAG)
    values.flag_value -= SIGN_PRECEDENCE_FLAG;
  if (values.precision_exist) values.precision_value = 0;

  format_flag_(buffer, index, values, &c, len, ' ', ctoa);
}

void formated_int(char *buffer, size_t *index, va_list factor,
                  format_value values) {
  long long value = 0;

  if (!values.length_value) value = va_arg(factor, int);
  if (values.length_value == SHORT_INT_LENGTH) value = va_arg(factor, int);
  if (values.length_value == LONG_INT_LENGTH) value = va_arg(factor, long);
  if (values.length_value == LONG_LONG_INT_LENGTH)
    value = va_arg(factor, long long);

  size_t len = 1;
  char sign = '+';

  if (value < 0)
    value = -value, ++len, sign = '-';
  else if (value != 0 && values.flag_value & NO_SIGN_FLAG)  // For %+d
    ++len;
  else if (value == 0 && values.precision_exist && values.precision_value == 0)
    len = 0;

  len += ((size_t)log10(value));

  format_flag_(buffer, index, values, &value, len, sign, itoa);
}

void formated_uint(char *buffer, size_t *index, va_list factor,
                   format_value values) {
  unsigned long long value = 0;

  if (!values.length_value) value = va_arg(factor, unsigned int);
  if (values.length_value == SHORT_INT_LENGTH)
    value = va_arg(factor, unsigned int);
  if (values.length_value == LONG_INT_LENGTH)
    value = va_arg(factor, unsigned long);
  if (values.length_value == LONG_LONG_INT_LENGTH)
    value = va_arg(factor, unsigned long long);

  if (values.flag_value & SIGN_PRECEDENCE_FLAG ||
      values.flag_value & NO_SIGN_FLAG)
    values.flag_value = 0;

  size_t len = 1;
  if (value != 0) {
    len = get_uint_length(value, values);
  } else {
    if (values.precision_exist && values.precision_value == 0) len = 0;
    values.flag_value = 0;
  }

  format_flag_(buffer, index, values, &value, len, '+', itoa);
}

void formated_string(char *buffer, size_t *index, va_list factor,
                     format_value values) {
  char *v = va_arg(factor, char *);

  if (v == NULL) {
    v = "(null)";
    if (values.precision_value < STANDARD_PRECISION) values.precision_value = 0;
  }

  size_t len = s21_strlen(v);
  if (values.precision_exist) len = min(len, values.precision_value);
  values.precision_value = len;
  values.flag_value &= LEFT_JUSTIFY_FLAG;

  format_flag_(buffer, index, values, v, len, ' ', stoa);
}

void formated_n(const size_t *index, va_list factor) {
  int *v = va_arg(factor, int *);
  *v = *index;
}

void formated_pointer(char *buffer, size_t *index, va_list factor,
                      format_value values) {
  void *pointer = va_arg(factor, void *);
  uintptr_t address = (uintptr_t)pointer;

  if (pointer != 0) {
    int len = 0;
    if (pointer != NULL) len = (logl(address) / log(HEXADECIMAL_BASE)) + 1;
    if (values.flag_value & LEFT_JUSTIFY_FLAG) len += 2;
    values.specifier_value = x_SPEC;
    values.flag_value |= HASH_FLAG;

    format_flag_(buffer, index, values, &address, len, '+', itoa);
  } else {
    values.flag_value = 0;
    values.precision_value = 0;
    values.precision_exist = 0;
    char *pointer = "(nil)";

    format_flag_(buffer, index, values, pointer, 5, '+', stoa);
  }
}

void formated_float(char *buffer, size_t *index, va_list factor,
                    format_value values) {
  long double value = 0;
  char local_spec = values.specifier_value;
  size_t len = 1;
  char sign = '+';

  // Argument extraction logging
  if (!values.length_value) {
    value = va_arg(factor, double);
  }
  if (values.length_value == LONG_DOUBLE_LENGTH) {
    value = va_arg(factor, long double);
  }

  int power = exponent(value);
  values.precision_value =
      values.precision_exist ? STANDARD_PRECISION : values.precision_value;

  // g/G specification handling
  if (local_spec == g_SPEC || local_spec == G_SPEC) {
    if (values.precision_value == 0) {
      values.precision_value = 1;
    }

    if (power > -4 && (size_t)power < values.precision_value) {
      local_spec = FLOAT_SPEC;
      values.precision_value -= power + 1;
    } else {
      local_spec = g_SPEC ? e_SPEC : E_SPEC;
      values.precision_value -= 1;
    }
  }

  // Length calculation logging
  if (values.precision_value != 0 || values.flag_value & HASH_FLAG) {
    len += values.precision_value + 1;
  }

  long double temp = roundl(value * pow(10, power));
  value = floorl(temp / pow(10, power));
  // Sign handling
  if (value < 0) {
    value = -value;
    ++len;
    sign = '-';
  }
  if ((values.flag_value & SIGN_PRECEDENCE_FLAG ||
       values.flag_value & NO_SIGN_FLAG) &&
      sign != '-') {
    len += 1;
  }

  // Format-specific processing
  if (local_spec == FLOAT_SPEC) {
    if (roundl(value) != 0) {
      len += ((size_t)log10l(value));
    }
    format_flag_(buffer, index, values, &value, len, sign, ftoa);
  } else if (local_spec == e_SPEC || local_spec == E_SPEC) {
    len += 4;
    int power_len = power < 99 ? 0 : exponent(power);
    len += min(power_len, 0);
    format_flag_(buffer, index, values, &value, len, sign, etoa);
  }
}

void formated_percent(char *buffer, size_t *index, format_value values) {
  char v = '%';

  if (values.flag_value & ZERO_PADDING_FLAG)
    values.flag_value -= ZERO_PADDING_FLAG;
  if (values.flag_value & SIGN_PRECEDENCE_FLAG)
    values.flag_value -= SIGN_PRECEDENCE_FLAG;

  if (values.precision_exist) values.precision_value = 0;

  format_flag_(buffer, index, values, &v, 1, ' ', ctoa);
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
