#include "../s21_string.h"

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
