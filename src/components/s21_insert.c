#include "../s21_string.h"

void *insert(const char *src, const char *str, size_t start_index) {
    if (src == NULL || str == NULL || start_index > s21_strlen(src)) {
        return NULL;
    }
    size_t src_len = s21_strlen(src);
    size_t str_len = s21_strlen(str);

    char *new_str = (char *)malloc(src_len + str_len + 1);
    if (new_str == NULL) {
        return NULL; 
    }

    s21_strncpy(new_str, src, start_index);
    new_str[start_index] = '\0';
    s21_strncat(new_str, str, str_len);
    s21_strncat(new_str, src + start_index, src_len - start_index);

    return new_str;
}