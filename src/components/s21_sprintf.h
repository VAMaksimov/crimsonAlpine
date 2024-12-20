#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "../s21_string.h"

// parser functions

int number_parser(const char **p);
void width_parser(const char **p, format_value *values, va_list factor);
void precision_parser(const char **p, format_value *values, va_list factor);
void length_parser(const char **p, format_value *values);
char flag_value(char c);

// closest functions

const char *format_parser(char *buffer, size_t *index, const char *p,
                          va_list factor, format_value values);
void format_execusion(char *buffer, size_t *index, format_value values,
                      va_list factor);

// preprocessing functions

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
void precision_processing(format_value *values, char *local_spec, int power);
void formated_percent(char *buffer, size_t *index, format_value values);

void flag_hash_execusion(char *buffer, size_t *index, char specifier);
void format_flag_(char *buffer, size_t *index, format_value values, void *c,
                  size_t len, char sign,
                  void (*write_to_buffer)(void *c, char *buffer, size_t *index,
                                          format_value values));
void case_blank_padding(char *buffer, size_t *index, format_value values,
                        int new_len);
void case_zero_padding(char *buffer, size_t *index, format_value values,
                       int new_len, size_t len);
void case_left_justify(char *buffer, size_t *index, format_value values,
                       int new_len);

// output functions

int trim_zeros(char *buffer, size_t *index, size_t old_index);
void itoa(void *c, char *buffer, size_t *index, format_value values);
void ctoa(void *c, char *buffer, size_t *index, format_value values);
void stoa(void *c, char *buffer, size_t *index, format_value values);
void ftoa(void *c, char *buffer, size_t *index, format_value values);
void etoa(void *c, char *buffer, size_t *index, format_value values);
void fractional_part_handling(long double value, char *buffer, size_t *index,
                              format_value values, size_t integer_part);
void integer_part_toa(size_t number, char *buffer, size_t *index);
void write_power_toa(int power, char *buffer, size_t *index);

// minor

int get_uint_length(unsigned long long v, format_value values);
int define_base_System(char spec);
int exponent(long double value, int base);
long double round_to_precision(long double value, format_value values);

#endif  // S21_SPRINTF_H