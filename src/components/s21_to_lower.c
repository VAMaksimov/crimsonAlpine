#include "../s21_string.h"
void *to_lower(const char *str) {
    char *result = NULL;
    if (str == NULL) return NULL;
    result = (char*)malloc(s21_strlen(str) + 1);
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            result[i] = str[i] + 32;
        } else {
            result[i] = str[i];
        }
    }
    return result;
}