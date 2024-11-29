#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECIMAL_BASE 10
#define HEX_BASE 16

int s21_sprintf(char *str, const char *format, ...);
size_t change_in_place(char *str, const char *format, va_list args,
                       char *object_to_insert, const char *specifiers_stack);
void reset_object(char *object_to_insert);
void insert_object(char *str, const char *object_to_insert, size_t *output_ind);
char *itoa(int num, char *object_to_insert, int base);
void s21_reverse_str(char *str, size_t len);
bool is_valid_specifier(const char retrieved_char);
void variable_to_string(const char specifier, va_list args,
                        char *object_to_insert);

#endif  // S21_SPRINTF