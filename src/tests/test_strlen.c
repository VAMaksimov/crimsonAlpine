#include "test_me.h"

void assert_strlen(const char *str) {
    ck_assert_int_eq(strlen(str), s21_strlen(str));
}

START_TEST(standard_1) {
    assert_strlen("Hello, world!");
}
END_TEST

START_TEST(standard_2) {
    assert_strlen("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
}
END_TEST

START_TEST(standard_3) {
    assert_strlen("          00000000           ......  ");
}
END_TEST

START_TEST(border_1) {
    assert_strlen("");
}
END_TEST

START_TEST(border_2) {
    assert_strlen("\0");
}
END_TEST

START_TEST(border_3) {
    assert_strlen("\t\t");
}
END_TEST

START_TEST(border_4) {
    assert_strlen("\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n");
}
END_TEST

START_TEST(irregular_1) {
    assert_strlen(
        "213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 "
        "21");
}
END_TEST

START_TEST(irregular_2) {
    assert_strlen("I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!");
}
END_TEST

START_TEST(irregular_3) {
    assert_strlen("wtf \0 wtf");
}
END_TEST

START_TEST(irregular_4) {
    char str[10000];
    memset(str, 'a', 9999);
    str[9999] = '\0';
    assert_strlen(str);
}
END_TEST

Suite *test_strlen(void) {
    Suite *s = suite_create("\033[47mstrlen\033[0m");
    TCase *tc = tcase_create("strlen_test_case");

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

    suite_add_tcase(s, tc);
    return s;
}
