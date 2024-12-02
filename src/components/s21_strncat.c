#include "../s21_string.h"

/**
 * @brief Concatenates at most n characters of the string pointed to, by src to
 * the end of the string pointed to, by dest.
 * @param dest The destination string.
 * @param src The source string.
 * @param n The maximum number of characters to be appended.
 * @return The destination string.
 */
char *s21_strncat(char *dest, const char *src, size_t n) {
  if (dest == NULL || src == NULL) return NULL;
  // Move to the end of dest
  char *d = dest;
  while (*d) d++;

  char *p = (char *)src;
  // Copy at most n characters from src to dest
  while (n-- && *p != '\0') *d++ = *p++;

  // Null-terminate the result
  *d = '\0';
  return dest;
}
