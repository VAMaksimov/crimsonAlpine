#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s21_sprintf(char *str, const char *format, ...);
bool is_valid_specifier(const char retrieved_char);
void variable_to_string(const char specifier, va_list args,
                        char *object_to_insert);
void change_in_place(char *str, const char *format, char *args,
                     char *object_to_insert, const char *specifiers_stack);

#endif  // S21_SPRINTF