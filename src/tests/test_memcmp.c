#include "test_me.h"

void assert_memcmp(const char *s1, const char *s2, s21_size_t n) {
    ck_assert_int_eq(memcmp(s1, s2, n), s21_memcmp(s1, s2, n));
}

START_TEST(standart_1) {
    assert_memcmp("Hello", "Hello", 5);
}
END_TEST

START_TEST(standart_2) {
    assert_memcmp("Hello", "World", 3);
}
END_TEST

START_TEST(standart_3) {
    assert_memcmp("Hello", "Hello", 3);
}
END_TEST

START_TEST(border_1) {
    assert_memcmp("", "", 0);
}
END_TEST

START_TEST(border_2) {
    assert_memcmp("Hello", "Helxo", 3);
}
END_TEST

START_TEST(border_3) {
    assert_memcmp("ABC", "ABC", 3);
}
END_TEST

START_TEST(irregular_1) {
    assert_memcmp("abcd", "abcd", 4);
}
END_TEST

START_TEST(irregular_2) {
    assert_memcmp("Hello", "World", 1);
}
END_TEST

START_TEST(irregular_3) {
    assert_memcmp("Hello", "hellO", 5);
}
END_TEST

START_TEST(irregular_4) {
    assert_memcmp("1234", "1235", 4);
}
END_TEST

Suite *test_memcmp(void) {
    Suite *s = suite_create("\033[47mmemcmp\033[0m");
    TCase *tc = tcase_create("memcmp_tc");

    tcase_add_test(tc, standart_1);
    tcase_add_test(tc, standart_2);
    tcase_add_test(tc, standart_3);

    tcase_add_test(tc, border_1);
    tcase_add_test(tc, border_2);
    tcase_add_test(tc, border_3);

    tcase_add_test(tc, irregular_1);
    tcase_add_test(tc, irregular_2);
    tcase_add_test(tc, irregular_3);
    tcase_add_test(tc, irregular_4);

    suite_add_tcase(s, tc);
    return s;
}
