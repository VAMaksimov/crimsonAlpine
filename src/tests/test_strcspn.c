#include "test_me.h"

void assert_strcspn(const char *str1, const char *str2) {
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}

START_TEST(standard_1) {
    assert_strcspn("Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!", "Hello, world!");
}
END_TEST

START_TEST(standard_2) {
    assert_strcspn("v", "vendetta");
}
END_TEST

START_TEST(standard_3) {
    assert_strcspn("69917020", "69917020");
}
END_TEST

START_TEST(border_1) {
    assert_strcspn("", "Hello, world!");
}
END_TEST

START_TEST(border_2) {
    assert_strcspn("Hello, world!", "");
}
END_TEST

START_TEST(border_3) {
    assert_strcspn("", "");
}
END_TEST

START_TEST(border_4) {
    assert_strcspn("a", ""); 
}
END_TEST

START_TEST(irregular_1) {
    assert_strcspn("69917020", "6991702H");
}
END_TEST

START_TEST(irregular_2) {
    assert_strcspn("aaaaa", "a"); 
}
END_TEST

START_TEST(irregular_3) {
    assert_strcspn("aaaaa", "b"); 
}
END_TEST

START_TEST(irregular_4) {
    assert_strcspn("abcdef", "def"); 
}
END_TEST

START_TEST(irregular_5) {
    assert_strcspn("a", "a"); 
}
END_TEST

Suite *test_strcspn(void) {
    Suite *s = suite_create("\033[47mstrcspn\033[0m");
    TCase *tc = tcase_create("strcspn_tc");

    tcase_add_test(tc, standard_1);
    tcase_add_test(tc, standard_2);
    tcase_add_test(tc, standard_3);

    tcase_add_test(tc, border_1);
    tcase_add_test(tc, border_2);
    tcase_add_test(tc, border_3);
    tcase_add_test(tc, border_4);

    tcase_add_test(tc, irregular_1);
    tcase_add_test(tc, irregular_2);
    tcase_add_test(tc, irregular_3);
    tcase_add_test(tc, irregular_4);
    tcase_add_test(tc, irregular_5);

    suite_add_tcase(s, tc);
    return s;
}
