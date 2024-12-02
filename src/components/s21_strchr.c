#include "../s21_string.h"

/**
 * @brief Finds the first occurrence of the character c in the string str.
 * @param  str The string to be searched.
 * @param  c The character to be searched for.
 * @return A pointer to the first occurrence of c in the string, or NULL if c is
 * not found.
 */
char *s21_strchr(const char *str, int c) {
  if (str == NULL) return NULL;
  char *p = (char *)str;
  while (*p != (char)c && *p != '\0') p++;
  return *p == c ? p : NULL;
}
