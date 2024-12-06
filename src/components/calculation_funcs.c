#include "../s21_string.h"

size_t s21_strlen(const char *str) {
  size_t len = 0;
  while (str[len] != '\0') len++;
  return len;
}

/**
 * @brief Calculates the length of the initial segment of str1 which consists
 * entirely of characters not in str2.
 *
 * @param str1 The string to be scanned.
 * @param str2 The string containing the characters to match.
 * @return The number of characters in the initial segment of str1 which are not
 * in str2.
 */
size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p = str1;
  while (*p != '\0' && !s21_strchr(str2, *p)) p++;
  return (size_t)(p - str1);
}