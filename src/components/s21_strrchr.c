#include "../s21_string.h"
/**
 * @brief Finds the last occurrence of the character c in the string str.
 *
 * @param  str The string to be searched.
 * @param  c The character to be searched for.
 * @return A pointer to the last occurrence of c in the string, or NULL if c is
 * not found.
 */
char *s21_strrchr(const char *str, int c) {
  if (str == NULL) return NULL;
  const char *last_occurrence = NULL;
  while (*str) {
    if (*str == c) last_occurrence = str;
    str++;
  }
  return (char *)last_occurrence;
}
