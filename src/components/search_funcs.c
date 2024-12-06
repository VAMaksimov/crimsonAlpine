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

/**
 * @brief Locates the first occurrence of any of the characters in the string
 * pointed to by str2 in the string pointed to by str1.
 *
 * @param str1 The string to be searched.
 * @param str2 The string containing the characters to match.
 *
 * @return A pointer to the character in str1 that matches one of the characters
 * in str2, or a null pointer if no such character is found.
 */
char *s21_strpbrk(const char *str1, const char *str2) {
  if (str1 == NULL || str2 == NULL) return NULL;
  size_t i = 0;
  while (str1[i] != '\0' && !s21_strchr(str2, str1[i])) i++;
  return i == s21_strlen(str1) ? NULL : (char *)(str1 + i);
}

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
  if (*str == c) last_occurrence = str;
  return (char *)last_occurrence;
}

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

/**
 * @brief Tokenizes a string with a given delimiter.
 *
 * @param str The string to be tokenized.
 * @param delim The delimiter string.
 * @return The next token in the string, or NULL if there are no more tokens.
 */
char *s21_strtok(char *str, const char *delim) {
  char *s = NULL;
  static char *p = NULL;
  bool flag = false;
  if (str != NULL) {
    s = str;
  } else {
    if (p == NULL)
      flag = true;
    else {
      s = p + 1;
      if (*s == '\0') flag = true;
    }
  }
  if (!flag) {
    while (*s != '\0' && s21_strchr(delim, *s) != NULL) ++s;
    p = s21_strpbrk(s, delim);
    if (p != NULL) *p = '\0';
    if (*s == '\0') flag = true;
  }
  return flag ? NULL : s;
}
