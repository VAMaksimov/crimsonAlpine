#include "s21_sprintf.h"

/**
 * @brief Formats and stores a series of characters and values in the buffer.
 *
 * This function writes the formatted data specified by the format string to the
 * provided buffer. It uses a variable argument list to handle multiple
 * arguments and supports various format specifiers for input values.
 *
 * @param buffer A pointer to the buffer where the formatted string will be
 * stored.
 * @param format A constant character string that contains the format
 * specifiers.
 * @param va_list Additional arguments containing the data to be formatted
 * according to the format specifiers.
 * @return The number of characters written to the buffer, excluding the null
 *         terminator.
 */
int s21_sprintf(char *buffer, const char *format, ...) {
  if (format == NULL) return 0;
  const char *p = format;
  size_t index = 0;
  va_list factor;
  va_start(factor, format);

  while (p != NULL && *p != '\0') {
    format_value values = {0};
    while (*p != '%' && *p != '\0') {  // Переписать на s21_strncpy
      buffer[index++] = *p++;
    }
    if (*p != '\0') p = format_parser(buffer, &index, ++p, factor, values);
  }

  va_end(factor);
  buffer[index] = '\0';
  return index;
}

/**
 * @brief Parses the format string and stores the format specifier data in the
 *        corresponding struct.
 *
 * This function iterates through the format string and checks for the presence
 * of flags, width, precision, length, and specifier characters. If a flag,
 * width, precision, length, or specifier is found, the function calls the
 * corresponding parser to parse the respective value and store it in the
 * format_value struct. Once all the values have been parsed, this function
 * calls the format execution function to format the data according to the
 * parsed values.
 *
 * @param buffer A pointer to the buffer where the formatted string will be
 * stored.
 * @param index A pointer to the index in the buffer where the next character
 * should be written.
 * @param p A pointer to the current character in the format string.
 * @param factor A pointer to the list of variable arguments.
 * @param values A struct containing the parsed format specifier values.
 * @return A pointer to the next character in the format string after parsing
 *         the format specifier.
 */
const char *format_parser(char *buffer, size_t *index, const char *p,
                          va_list factor, format_value values) {
  while (!values.specifier_value) {
    if (!(values.flag_value & LEFT_JUSTIFY_FLAG) &&
        !(values.flag_value & SIGN_PRECEDENCE_FLAG) && s21_strchr("-+ #0", *p))
      values.flag_value = flag_value(*p);
    else if (s21_strchr("123456789*", *p))
      width_parser(&p, &values, factor);
    else if (*p == '.') {
      ++p;
      precision_parser(&p, &values, factor);
    } else if (s21_strchr("hlL", *p))
      length_parser(&p, &values);
    else if (s21_strchr("cdieEfgGosuxXpn%%", *p))
      values.specifier_value = *p;
    ++p;
  }
  format_execusion(buffer, index, values, factor);
  return p;
}

void format_execusion(char *buffer, size_t *index, format_value values,
                      va_list factor) {
  if (values.specifier_value == CHAR_SPEC)
    formated_char(buffer, index, factor, values);
  else if (values.specifier_value == DECIMAL_INT_SPEC ||
           values.specifier_value == MULTI_BASE_INT_SPEC)
    formated_int(buffer, index, factor, values);
  else if (values.specifier_value == e_SPEC ||
           values.specifier_value == E_SPEC ||
           values.specifier_value == FLOAT_SPEC ||
           values.specifier_value == g_SPEC || values.specifier_value == G_SPEC)
    formated_float(buffer, index, factor, values);
  else if (values.specifier_value == OCTAL_SPEC ||
           values.specifier_value == UNSIGNED_DECIMAL_SPEC ||
           values.specifier_value == x_SPEC || values.specifier_value == X_SPEC)
    formated_uint(buffer, index, factor, values);
  else if (values.specifier_value == STRING_SPEC)
    formated_string(buffer, index, factor, values);
  else if (values.specifier_value == POINTER_SPEC)
    formated_pointer(buffer, index, factor, values);
  else if (values.specifier_value == COUNT_OF_CHARS_INSIDE_SPEC)
    formated_n(index, factor);
}
