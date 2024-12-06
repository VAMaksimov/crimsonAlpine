#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
      test_memchr(), test_memcmp(), test_memcpy(),
      // test_memmove(),
      test_memset(), test_strncat(), test_strchr(), test_strncmp(),
      test_strncpy(), test_strcspn(), test_strerror(), test_strlen(),
      test_strpbrk(), test_strrchr(), test_sprintf_c(), test_sprintf_e(),
      test_sprintf_f(), test_sprintf_g(), test_strstr(), test_strtok(),
      test_sprintf_octal(), test_sprintf_percent(), test_sprintf_n(),
      test_sprintf_string(), test_sprintf_unsigned(), test_sprintf_HEX(),
      test_sprintf_hex(), test_sprintf_pointer(), test_sprintf_signed(),
      test_sprintf_signed_i(),
      // test_sscanf_empty(),
      // test_sscanf_c(),
      // test_sscanf_d(),
      // test_sscanf_i(),
      // test_sscanf_o(),
      // test_sscanf_x(),
      // test_sscanf_p(),
      // test_sscanf_real(),
      // test_sscanf_n(),
       test_to_upper(),
       test_to_lower(),
       test_insert(),
       test_trim(),
      NULL};

    for (int i = 0; s21_string_test[i] != NULL; i++) {
        Suite *s = s21_string_test[i];
        
        // Создаем новый тестовый набор
        SRunner *sr = srunner_create(s);

        srunner_set_fork_status(sr, CK_NOFORK); // Не использовать fork для запуска тестов
        srunner_run_all(sr, CK_NORMAL); // Запуск всех тестов

        int suite_failed = srunner_ntests_failed(sr); // Получаем количество неудачных тестов
        failed += suite_failed; // Суммируем общее количество неудачных тестов

        // Изменение цвета названия в зависимости от результатов
        if (suite_failed > 0) {
            printf("\033[31mFAILED_FAILED_FAILED_FAILED_FAILED_FAILED\033[0m\n"); // Красный текст при ошибках
        } else {
            printf("\033[32mPASSED_PASSED_PASSED_PASSED_PASSED_PASSED\033[0m\n"); // Зеленый текст при успехе
        }

        srunner_free(sr); // Освобождаем ресурсы для текущего набора тестов
    }

    // Вывод общего результата
    if (failed > 0) {
        printf("\033[31m========= FAILED: %d =========\033[0m\n", failed); // Красный текст при ошибках
    } else {
        printf("\033[32m========= ALL TESTS PASSED! =========\033[0m\n"); // Зеленый текст при успехе
    }

    return failed == 0 ? 0 : 1; // Возвращаем 0 при успехе, иначе 1
}