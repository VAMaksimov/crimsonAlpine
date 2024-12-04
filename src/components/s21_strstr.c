#include "../s21_string.h"

/**
 * @brief Locates the first occurrence of the null-terminated string needle in
 * the null-terminated string haystack.
 *
 * @param haystack The string to be searched.
 * @param needle The string to search for.
 *
 * @return A pointer to the first occurrence of needle in haystack, or NULL if
 * needle is not found.
 */
char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == NULL || needle == NULL) return NULL;
  if (*needle == '\0') return (char *)haystack;
  int len_n = s21_strlen(needle);
  int len_h = s21_strlen(haystack);
  bool found = false;
  const char *p = haystack;
  if (len_n <= len_h) {
    while (*p != '\0' && !found) {
      if (*p == *needle && s21_strncmp(p, needle, len_n) == 0) {
        found = true;
      } else
        ++p;
    }
  }
  return found ? (char *)p : NULL;
}
