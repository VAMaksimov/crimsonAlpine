#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#define size_t long unsigned int
#define bool _Bool
#define true 1
#define false 0
#define ll 'd'

#define LEFT_JUSTIFY_FLAG '-'
#define SIGN_PRECEDENCE_FLAG '+'
#define NO_SIGN_FLAG ' '
#define HASH_FLAG '#'
#define ZERO_PADDING_FLAG '0'

#define SHORT_INT_LENGTH 'h'
#define LONG_INT_LENGTH 'l'
#define LONG_DOUBLE_LENGTH 'L'

#define CHAR_SPEC 'c'
#define DECIMAL_INT_SPEC 'd'
#define MULTI_BASE_INT_SPEC 'i'
#define e_SPEC 'e'
#define E_SPEC 'E'
#define FLOAT_SPEC 'f'
#define g_SPEC 'g'
#define G_SPEC 'G'
#define OCTAL_SPEC 'o'
#define STRING_SPEC 's'
#define UNSIGNED_DECIMAL_SPEC 'u'
#define x_SPEC 'x'
#define X_SPEC 'X'
#define POINTER_SPEC 'p'
#define COUNT_OF_CHARS_INSIDE_SPEC 'n'
#define PERCENT_CHAR_SPEC '%'

#define STANDARD_PRECISION 6

typedef struct {
  char flag_value;
  int width_value;
  bool precision_exist;
  size_t precision_value;
  char length_value;
  char specifier_value;
} format_value;

char *s21_strerror(int errnum);

char *s21_strstr(const char *haystack, const char *needle);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strncpy(char *dest, const char *src, size_t n);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strtok(char *str, const char *delim);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
// void *s21_to_lower(const char *str);
// void *s21_to_upper(const char *str);
// char *s21_trim(const char *src, const char *trim_chars);
// char *s21_insert(const char *src, const char *str, size_t start_index);

int number_parser(const char **p);
void width_parser(const char **p, format_value *values, va_list factor);
void precision_parser(const char **p, format_value *values, va_list factor);
void length_parser(const char **p, format_value *values);

int s21_sprintf(char *buffer, const char *format, ...);

#endif  // S21_STRING_H