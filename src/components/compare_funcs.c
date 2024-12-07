#include "../s21_string.h"

/**
 * @brief Compare memory areas.
 * The s21_memcmp() function compares the first n bytes of memory area
 * str1 and memory area str2. It gives back a number. If this number is less
 * than zero, it means the first n bytes of str1 are smaller than those of str2.
 * If the number is zero, it means the first n bytes of str1 and str2 are the
 * same. If the number is more than zero, it means the first n bytes of str1 are
 * bigger than those of str2.
 * @param str1 The first memory area.
 * @param str2 The second memory area.
 * @param n The number of bytes to compare.
 * @return The s21_memcmp() function returns an integer less than, equal to,
 * or greater than zero if the first n bytes of str1 is found, respectively,
 * to be less than, to match, or be greater than the first n bytes of str2.
 */
int s21_memcmp(const void *str1, const void *str2, size_t n) {
  const char *d = (const char *)str1;
  const char *s = (const char *)str2;
  int res = 0;
  for (size_t i = 0; i < n && !res; ++i) res = d[i] - s[i];
  return res;
}

/**
 * @brief Compares up to n characters of the C strings str1 and str2.
 * The s21_strncmp() function compares the first n characters of the
 * strings str1 and str2. The comparison is done lexicographically.
 *
 * @param str1 The first string to be compared.
 * @param str2 The second string to be compared.
 * @param n The maximum number of characters to compare.
 *
 * @return An integer less than, equal to, or greater than zero if the first n
 * characters of str1 is found, respectively, to be less than, to match, or be
 * greater than the first n characters of str2.
 */
int s21_strncmp(const char *str1, const char *str2, size_t n) {
  if (str1 == NULL || str2 == NULL) return 0;
  const char *d = (const char *)str1;
  const char *s = (const char *)str2;
  int res = 0;

  for (size_t i = 0; i < n && !res; ++i) {
    res = d[i] - s[i];
  }

  return res;
}