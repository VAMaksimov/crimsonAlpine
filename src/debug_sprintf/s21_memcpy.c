#include "../s21_string.h"

/**
 * @brief Copy memory area.
 * The s21_memcpy() function copies n bytes from memory area src to
 * memory area dest. If the memory regions specified by src and dest overlap,
 * the results are undefined.
 * @param dest The pointer to the destination array where the content is to be
 * copied.
 * @param src The pointer to the source of data to be copied.
 * @param n The number of bytes to copy.
 * @return The s21_memcpy() function returns a pointer to dest.
 */
void *s21_memcpy(void *dest, const void *src, size_t n) {
  if (dest == NULL || src == NULL) return NULL;
  char *d = (char *)dest;
  const char *p = (const char *)src;
  while (n-- && *p != '\0') *d++ = *p++;  // the same as: *d = *s; d++; s++;
  if (n == 0) *d = '\0';
  return dest;
}
