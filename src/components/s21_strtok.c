#include "../s21_string.h"

/**
 * @brief Tokenizes a string with a given delimiter.
 *
 * @param str The string to be tokenized.
 * @param delim The delimiter string.
 * @return The next token in the string, or NULL if there are no more tokens.
 */
char *s21_strtok(char *str, const char *delim) {
  if (str == NULL || delim == NULL) return NULL;
  char *src = str, *dst = str;
  // Skip over the delimiter characters at the beginning of the string.
  while (*src != '\0' && s21_strchr(delim, *src) != NULL) src++;
  if (*src == '\0') {
    dst = NULL;
  } else {
    // Find the end of the current token.
    while (*src != '\0' && s21_strchr(delim, *src) == NULL) src++;
    if (*src != '\0') {
      // Set the end of the current token to '\0', and set dst to the next
      // token.
      *src++ = '\0';
      dst = src;
    } else {  // end of source string
      dst = NULL;
    }
  }
  return dst;
}

// char *strtok(char *str, const char *delim) {
//   if (str == NULL || delim == NULL) return NULL;
//   size_t i = 0;
//   char *s = NULL;
//   static char *p = NULL;
//   static bool stop = false;
//   bool flag = false;
//   if (str != NULL) {
//     s = str;
//   } else {
//     s = p + 1;
//     if (stop || *s == '\0') flag = true;
//   }
//   if (!flag) {
//     while (s[i] != '\0' && s21_strchr(delim, s[i]) != NULL) i++;
//     p = s21_strpbrk(s + i, delim);
//     if (p != NULL) *p = '\0';
//   }
//   if (s == NULL || p == NULL) stop = true;
//   return flag ? NULL : s + i;
// }
