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