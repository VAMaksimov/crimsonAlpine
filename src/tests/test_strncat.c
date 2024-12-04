#include "test_me.h"

void assert_strncat(const char *s1, const char *s2, s21_size_t n) {
  char tmp_s1[100];
  char tmp_s2[100];
  strcpy(tmp_s1, s1);
  strcpy(tmp_s2, s2);
  ck_assert_pstr_eq(strncat(tmp_s1, s2, n), s21_strncat(tmp_s2, s2, n));
}

START_TEST(strncat_basic_test) {
  assert_strncat("Hello, world!", "Hello, world!", 1);
}
END_TEST

START_TEST(strncat_empty_append) {
  assert_strncat("Hello, world!", "\0", 1);
}
END_TEST

START_TEST(strncat_special_chars) {
  assert_strncat("Hello, world!", "\n\0\\d\f\\g\7", 3);
}
END_TEST

START_TEST(strncat_zero_append) {
  assert_strncat("Hello, world!", "", 0);
}
END_TEST

START_TEST(strncat_full_append) {
  assert_strncat("", "Hello, world!", 13);
}
END_TEST

START_TEST(strncat_large_append) {
  assert_strncat("Hello, world!", "My name is Polina. I hate this, maybe I'm not supposed for this.", 6);
}
END_TEST

START_TEST(strncat_partial_append) {
  assert_strncat("", "Hello, world!", 3);
}
END_TEST

START_TEST(strncat_small_n) {
  assert_strncat("Hello, world!", "My name is Polina.", 2);
}
END_TEST

START_TEST(strncat_zero_length) {
  assert_strncat("", "", 10);
}
END_TEST

START_TEST(strncat_null_character_in_string) {
  assert_strncat("Hello\0, world!", "My name is\0 Polina.", 15);
}
END_TEST

START_TEST(strncat_append_null) {
  assert_strncat("Hello, world!", "\0", 1);
}
END_TEST

START_TEST(strncat_zero_n) {
  assert_strncat("Hello, world!", "\0", 0);
}
END_TEST

START_TEST(strncat_multiple_nulls) {
  assert_strncat("Hello, world!", "\0\0\0\0", 4);
}
END_TEST

START_TEST(strncat_small_string_append) {
  assert_strncat("Hello, world!", "", 2);
}
END_TEST

START_TEST(strncat_zero_append_test) {
  assert_strncat("Hello, world!\0\0\0", "My name is Polina.", 0);
}
END_TEST

START_TEST(strncat_edge_max_length) {
  assert_strncat("Hello, world!", "A long string that we are appending.", 10000);
}
END_TEST

START_TEST(strncat_overflow_case) {
  assert_strncat("Hello, ", "world!", 10);
}
END_TEST

START_TEST(strncat_large_n) {
  assert_strncat("Hello, world!", "test", 100);
}
END_TEST

START_TEST(strncat_n_equals_zero) {
  assert_strncat("Hello, world!", "test", 0);
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCAT=-\033[0m");
  TCase *tc = tcase_create("strncat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncat_basic_test);
  tcase_add_test(tc, strncat_empty_append);
  tcase_add_test(tc, strncat_special_chars);
  tcase_add_test(tc, strncat_zero_append);
  tcase_add_test(tc, strncat_full_append);
  tcase_add_test(tc, strncat_large_append);
  tcase_add_test(tc, strncat_partial_append);
  tcase_add_test(tc, strncat_small_n);
  tcase_add_test(tc, strncat_zero_length);
  tcase_add_test(tc, strncat_null_character_in_string);
  tcase_add_test(tc, strncat_append_null);
  tcase_add_test(tc, strncat_zero_n);
  tcase_add_test(tc, strncat_multiple_nulls);
  tcase_add_test(tc, strncat_small_string_append);
  tcase_add_test(tc, strncat_zero_append_test);
  tcase_add_test(tc, strncat_edge_max_length);
  tcase_add_test(tc, strncat_overflow_case);
  tcase_add_test(tc, strncat_large_n);
  tcase_add_test(tc, strncat_n_equals_zero);

  suite_add_tcase(s, tc);
  return s;
}
