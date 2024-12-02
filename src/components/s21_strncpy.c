#include "../s21_string.h"
/**
 * @brief Copies at most n characters from the string pointed to, by src to
 * the character array pointed to, by dest.
 *
 * @param dest The destination character array.
 * @param src The source string.
 * @param n The maximum number of characters to be copied.
 *
 * @return The destination character array.
 */
char *s21_strncpy(char *dest, const char *src, size_t n) {
  if (dest == NULL || src == NULL) return NULL;
  char *d = dest;
  const char *p = src;
  while (n-- && *p != '\0') *d++ = *p++;  // the same as: *d = *s; d++; s++;
  return dest;
}
