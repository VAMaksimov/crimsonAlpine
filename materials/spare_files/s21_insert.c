#include "../s21_string.h"

// char *insert(const char *src, const char *str, size_t start_index) {
//     size_t len_str = s21_strlen(str);
//     size_t len_src = s21_strlen(src);
//     char *res = malloc(len_src + len_str + 1);
//     size_t len_res = 0;
//     s21_strncpy(res, src, start_index);
//     s21_strncat(res, str, len_str);
//     s21_strncat(res, src + start_index, len_src - start_index);
//     res[len_src + len_str] = '\0';
//     return res;
// }