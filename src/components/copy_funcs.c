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
  if (n == 0) *d = '\0';
  return dest;
}

/**
 * @brief Moves n bytes from memory area src to memory area dest.
 * The s21_memmove() function copies n bytes from memory area src to
 * memory area dest. The memory areas may overlap, as the function
 * ensures that the original data in the overlapping regions is copied
 * safely before being overwritten.
 *
 * @param dest The pointer to the destination array where the content is to be
 * moved.
 * @param src The pointer to the source of data to be moved.
 * @param n The number of bytes to move.
 */
void s21_memmove(char *dest, const char *src, size_t n) {
  if (dest < src) {
    for (size_t i = 0; i < n; i++) {
      dest[i] = src[i];
    }
  } else if (dest > src) {
    for (int i = n - 1; i >= 0; i--) {
      dest[i] = src[i];
    }
  }
}