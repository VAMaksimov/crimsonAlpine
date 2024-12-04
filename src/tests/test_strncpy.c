#include "test_me.h"

void assert_strncpy(const char *src, s21_size_t n, const char *initial_dst1, const char *initial_dst2, s21_size_t dst_size) {
    char dst1[dst_size];
    char dst2[dst_size];
  
    strncpy(dst1, initial_dst1, dst_size);
    strncpy(dst2, initial_dst2, dst_size);

    const char *expected = strncpy(dst1, src, n);
    const char *result = s21_strncpy(dst2, src, n);

    ck_assert_pstr_eq(expected, result);
}

START_TEST(standard_1) {
    assert_strncpy("Good", 5, "Hello, world!", "Hello, world!", 20);
}
END_TEST

START_TEST(standard_2) {
    assert_strncpy("Hello", 5, "Initial", "Initial", 15);
}
END_TEST

START_TEST(standard_3) {
    assert_strncpy("Copy", 4, "Destination", "Destination", 20);
}
END_TEST

START_TEST(border_1) {
    assert_strncpy("", 0, "", "", 5);
}
END_TEST

START_TEST(border_2) {
    assert_strncpy("\0", 1, "Hello, world!", "Hello, world!", 20);
}
END_TEST

START_TEST(border_3) {
    assert_strncpy("12345678901234567890", 15, "AAAAAAAAAA", "AAAAAAAAAA", 10);
}
END_TEST

START_TEST(border_4) {
    assert_strncpy("Test String", 0, "Original", "Original", 20);
}
END_TEST

START_TEST(irregular_1) {
    assert_strncpy("fг-аг-аг", 5, "Hello, world!", "Hello, world!", 30);
}
END_TEST

START_TEST(irregular_2) {
    assert_strncpy(
        "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!",
        strlen("I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!"),
        "", "", 70);
}
END_TEST

START_TEST(irregular_3) {
    assert_strncpy("123456", 6, "abcdef", "abcdef", 6);
}
END_TEST

START_TEST(irregular_4) {
    assert_strncpy("\0", 1, "", "", 5);
}
END_TEST

Suite *test_strncpy(void) {
    Suite *s = suite_create("\033[45m-=S21_STRNCPY=-\033[0m");
    TCase *tc = tcase_create("strncpy_tc");

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
