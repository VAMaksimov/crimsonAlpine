#include "../s21_string.h"

/**
 * @brief This function searches for the first occurrence of the character c (an
 * unsigned char) in the first n bytes of the string pointed to by the
 * argument str.
 *
 * @param str a pointer to the string to be searched
 * @param c the character to be searched for
 * @param n the number of bytes to be searched
 *
 * @return a pointer to the first occurrence of c in the string, or NULL if c is
 * not found
 */
void *s21_memchr(const void *str, int c, size_t n) {
  if (str == NULL || n == 0) return NULL;
  char *p = (char *)str;
  while (n-- && *p != (char)c && *p != '\0') p++;
  return *p == c ? p : NULL;
}
