#include "test_me.h"

void assert_strncat_func(char *expected_s1, char *expected_s2, char *s3, s21_size_t n) {
  char s1[100] = {0};
  char s2[100] = {0};

  strncpy(s1, expected_s1, sizeof(s1) - 1);
  strncpy(s2, expected_s2, sizeof(s2) - 1);

  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}

START_TEST(standart_1) {
  assert_strncat_func("Hello, world!", "Hello, world!", "Hello, world!", 1);
}
END_TEST

START_TEST(standart_2) {
  assert_strncat_func("Hello, world!", "Hello, world!", "\0", 1);
}
END_TEST

START_TEST(standart_3) {
  assert_strncat_func("Hello, world!", "Hello, world!", "\n\0\\d\f\\g\7", 3);
}
END_TEST

START_TEST(border_1) {
  assert_strncat_func("Hello, world!", "Hello, world!", "", 0);
}
END_TEST

START_TEST(border_2) {
  assert_strncat_func("", "", "Hello, world!", 13);
}
END_TEST

START_TEST(border_3) {
  assert_strncat_func("Hello, world!My name is Polina. I hate this, maybe I'm not supposed for this.",
                      "Hello, world!My name is Polina. I hate this, maybe I'm not supposed for this.",
                      "My name is Polina. I hate this, maybe I'm not supposed for this.", 6);
}
END_TEST

START_TEST(irregular_1) {
  assert_strncat_func("", "", "Hello, world!", 3);
}
END_TEST

START_TEST(irregular_2) {
  assert_strncat_func("Hello, world!My name is Polina.", "Hello, world!My name is Polina.", "My name is Polina.", 2);
}
END_TEST

START_TEST(irregular_3) {
  assert_strncat_func("", "", "", 10);
}
END_TEST

START_TEST(irregular_4) {
  assert_strncat_func("Hello\0, world!", "Hello\0, world!", "My name is\0 Polina.", 15);
}
END_TEST

START_TEST(irregular_5) {
  assert_strncat_func("Hello, world!", "Hello, world!", "\0", 1);
}
END_TEST

START_TEST(irregular_6) {
  assert_strncat_func("Hello, world!", "Hello, world!", "\0", 0);
}
END_TEST

START_TEST(irregular_7) {
  assert_strncat_func("Hello, world!\0\0\0", "Hello, world!\0\0\0", "\0\0\0\0", 4);
}
END_TEST

START_TEST(irregular_8) {
  assert_strncat_func("Hello, world!", "Hello, world!", "", 2);
}
END_TEST

START_TEST(irregular_9) {
  assert_strncat_func("Hello, world!", "Hello, world!", "My name is Polina.", 0);
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCAT=-\033[0m");
  TCase *tc = tcase_create("strncat_tc");

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
  tcase_add_test(tc, irregular_5);
  tcase_add_test(tc, irregular_6);
  tcase_add_test(tc, irregular_7);
  tcase_add_test(tc, irregular_8);
  tcase_add_test(tc, irregular_9);

  suite_add_tcase(s, tc);
  return s;
}
