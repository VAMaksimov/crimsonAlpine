#include "../s21_string.h"

/**
 * @brief Sets the first n bytes of the memory area pointed to by str
 * to the specified value (converted to a char).
 *
 * @param str Pointer to the memory area.
 * @param c Value to be set.
 * @param n Number of bytes to be set to the value.
 *
 * @return Pointer to the memory area str.
 */
void *s21_memset(void *str, int c, size_t n) {
  if (str == NULL) return NULL;
  char *p = (char *)str;
  while (n--) *p++ = (char)c;
  return str;
}
