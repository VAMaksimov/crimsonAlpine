#include "../s21_string.h"

/**
 * @brief Locates the first occurrence of any of the characters in the string
 * pointed to by str2 in the string pointed to by str1.
 *
 * @param str1 The string to be searched.
 * @param str2 The string containing the characters to match.
 *
 * @return A pointer to the character in str1 that matches one of the characters
 * in str2, or a null pointer if no such character is found.
 */
char *s21_strpbrk(const char *str1, const char *str2) {
  if (str1 == NULL || str2 == NULL) return NULL;
  size_t i = 0;
  while (str1[i] != '\0' && !s21_strchr(str2, str1[i])) i++;
  return i == s21_strlen(str1) ? NULL : (char *)(str1 + i);
}
