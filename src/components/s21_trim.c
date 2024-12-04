#include "../s21_string.h"

int is_trim_char(char c, const char *trim_chars) {
    int flag = 0;
    while (*trim_chars && !flag) {
        if (c == *trim_chars) flag = 1;
        trim_chars++;
    }
    return flag;
}

void *s21_trim(const char *src, const char *trim_chars) {
    if (src == NULL || trim_chars == NULL) {
        return NULL;
    }

    const char *start = src;
    while (*start && is_trim_char(*start, trim_chars)) {
        start++;
    }

    const char *end = src + s21_strlen(src) - 1;
    while (end > start && is_trim_char(*end, trim_chars)) {
        end--;
    }

    size_t new_length = end - start + 1;
    char *new_str = (char *)malloc(new_length + 1);
    if (new_str == NULL) {
        return NULL;
    }

    s21_strncpy(new_str, start, new_length);
    new_str[new_length] = '\0';

    return new_str;
}