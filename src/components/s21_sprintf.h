#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "../s21_string.h"

// closest functions

const char *format_parser(char *buffer, size_t *index, const char *p,
                          va_list factor, format_value values);
void format_execusion(char *buffer, size_t *index, format_value values,
                      va_list factor);

// preprocessing functions

void flag_hash_execusion(char *buffer, size_t *index, char specifier);
void format_flag_(char *buffer, size_t *index, format_value values, void *c,
                  size_t len, char sign,
                  void (*write_to_buffer)(void *c, char *buffer, size_t *index,
                                          format_value values));
void formated_char(char *buffer, size_t *index, va_list factor,
                   format_value values);
void formated_int(char *buffer, size_t *index, va_list factor,
                  format_value values);
void formated_uint(char *buffer, size_t *index, va_list factor,
                   format_value values);
void formated_string(char *buffer, size_t *index, va_list factor,
                     format_value values);
void formated_n(const size_t *index, va_list factor);
void formated_pointer(char *buffer, size_t *index, va_list factor,
                      format_value values);
void formated_float(char *buffer, size_t *index, va_list factor,
                    format_value values);

// output functions

void itoa(void *c, char *buffer, size_t *index, format_value values);
void ctoa(void *c, char *buffer, size_t *index, format_value values);
void integer_ftoa(const long double *c, char *buffer, size_t *index);
void round_ftoa(const long double *c, char *buffer, size_t *index);
void fractional_ftoa(long double *c, char *buffer, size_t *index,
                     int precision);
void ftoa(void *c, char *buffer, size_t *index, format_value values);
void etoa(void *c, char *buffer, size_t *index, format_value values);

// minor

size_t get_uint_length(unsigned long long v, format_value values);
int define_base_System(char spec);

#endif  // S21_SPRINTF_H