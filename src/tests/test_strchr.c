#include "test_me.h"

void assert_strchr(const char *str, int ch) {
    ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}

START_TEST(strchr_lowercase_letter) {
    assert_strchr("Hello, world!", 'h');
}
END_TEST

START_TEST(strchr_null_character) {
    assert_strchr("Hello, world!", '\0');
}
END_TEST

START_TEST(strchr_comma) {
    assert_strchr("Hello, world!", ',');
}
END_TEST

START_TEST(strchr_nonexistent_character) {
    assert_strchr("Hello, world!", 33);
}
END_TEST

START_TEST(strchr_uppercase_letter) {
    assert_strchr("Hello, Polina!", 'P');
}
END_TEST

START_TEST(strchr_existing_letter) {
    assert_strchr("Hello, world!", 'w');
}
END_TEST

START_TEST(strchr_digit) {
    assert_strchr("Hello, world!", '0');
}
END_TEST

START_TEST(strchr_last_letter) {
    assert_strchr("Hello, world!", 'm');
}
END_TEST

Suite *test_strchr(void) {
    Suite *s = suite_create("\033[45m-=S21_STRCHR=-\033[0m");
    TCase *tc = tcase_create("strchr_tc");

    tcase_add_test(tc, strchr_lowercase_letter);
    tcase_add_test(tc, strchr_null_character);
    tcase_add_test(tc, strchr_comma);
    tcase_add_test(tc, strchr_nonexistent_character);
    tcase_add_test(tc, strchr_uppercase_letter);
    tcase_add_test(tc, strchr_existing_letter);
    tcase_add_test(tc, strchr_digit);
    tcase_add_test(tc, strchr_last_letter);

    suite_add_tcase(s, tc);
    return s;
}
