#include "../s21_string.h"

/**
 * @brief Inserts a string into another string at a specified index position.
 *
 * @param src The string into which the other string is inserted.
 * @param str The string to be inserted.
 * @param start_index The index position at which the other string is inserted.
 *
 * @return A pointer to the resulting string, or NULL on failure.
 */
void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == NULL || str == NULL || start_index > s21_strlen(src)) {
    return NULL;
  }
  size_t src_len = s21_strlen(src);
  size_t str_len = s21_strlen(str);

  char *new_str = (char *)malloc(src_len + str_len + 1);
  if (new_str == NULL) {
    return NULL;
  }

  s21_strncpy(new_str, src, start_index);
  new_str[start_index] = '\0';
  s21_strncat(new_str, str, str_len);
  s21_strncat(new_str, src + start_index, src_len - start_index);

  return new_str;
}

/**
 * @brief Converts a string to lower case.
 *
 * @param str The string to convert.
 *
 * @return A pointer to the converted string, or NULL on failure.
 */
void *s21_to_lower(const char *str) {
  char *result = NULL;
  if (str == NULL) return NULL;
  result = (char *)malloc(s21_strlen(str) + 1);
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      result[i] = str[i] + 32;
    } else {
      result[i] = str[i];
    }
  }
  return result;
}

/**
 * @brief Converts a string to upper case.
 *
 * @param str The string to convert.
 *
 * @return A pointer to the converted string, or NULL on failure.
 */
void *s21_to_upper(const char *str) {
  char *result = NULL;
  if (str == NULL) return NULL;
  result = (char *)malloc(s21_strlen(str) + 1);
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - 32;
    } else {
      result[i] = str[i];
    }
  }
  return result;
}

int is_trim_char(char c, const char *trim_chars) {
  int flag = 0;
  while (*trim_chars && !flag) {
    if (c == *trim_chars) flag = 1;
    trim_chars++;
  }
  return flag;
}

/**
 * @brief Trims leading and trailing characters from a string.
 *
 * This function creates a new string by removing all leading and trailing
 * occurrences of specified characters from the given string.
 *
 * @param src The source string to be trimmed.
 * @param trim_chars A string containing characters to be trimmed from both
 *                   ends of the source string.
 *
 * @return A pointer to the newly allocated trimmed string. Returns NULL if
 *         memory allocation fails or if either src or trim_chars is NULL.
 */
void *s21_trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) {
    return NULL;
  }

  const char *start = src;
  while (*start && is_trim_char(*start, trim_chars)) {
    start++;
  }

  const char *end = src + s21_strlen(src) - 1;
  while (end > start && is_trim_char(*end, trim_chars)) {
    end--;
  }

  size_t new_length = end - start + 1;
  char *new_str = (char *)malloc(new_length + 1);
  if (new_str == NULL) {
    return NULL;
  }

  s21_strncpy(new_str, start, new_length);
  new_str[new_length] = '\0';

  return new_str;
}
