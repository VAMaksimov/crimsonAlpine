#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#define size_t long unsigned int
#define NULL ((void *)0)
#define bool _Bool
#define true 1
#define false 0
#define ll 'd'

#define LEFT_JUSTIFY_FLAG (1 << 0)
#define SIGN_PRECEDENCE_FLAG (1 << 1)
#define NO_SIGN_FLAG (1 << 2)
#define HASH_FLAG (1 << 3)
#define ZERO_PADDING_FLAG (1 << 4)

#define SHORT_INT_LENGTH (1 << 0)
#define LONG_INT_LENGTH (1 << 1)
#define LONG_DOUBLE_LENGTH (1 << 2)

#define CHAR_SPEC (1 << 0)
#define DECIMAL_INT_SPEC (1 << 1)
#define MULTI_BASE_INT_SPEC (1 << 2)
#define e_SPEC (1 << 3)
#define E_SPEC (1 << 4)
#define FLOAT_SPEC (1 << 5)
#define g_SPEC (1 << 6)
#define G_SPEC (1 << 7)
#define OCTAL_SPEC (1 << 8)
#define STRING_SPEC (1 << 9)
#define UNSIGNED_DECIMAL_SPEC (1 << 10)
#define x_SPEC (1 << 11)
#define X_SPEC (1 << 12)
#define POINTER_SPEC (1 << 13)
#define COUNT_OF_CHARS_INSIDE_SPEC (1 << 14)
#define PERCENT_CHAR_SPEC (1 << 15)

typedef struct {
  int flag_value;
  int width_value;
  bool precision_exist;
  size_t precision_value;
  int length_value;
  int specifier_value;
} format_value;

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

#endif  // S21_STRING_H