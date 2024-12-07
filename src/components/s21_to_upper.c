#include "../s21_string.h"

void *s21_to_upper(const char *str) {
    char *result = NULL;
    if (str == NULL) return NULL;
    result = (char*)malloc(s21_strlen(str) + 1);
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            result[i] = str[i] - 32;
        } else {
            result[i] = str[i];
        }
    }
    return result;
}