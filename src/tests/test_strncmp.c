#include "test_me.h"

void assert_strncmp(const char *s1, const char *s2, s21_size_t n) {
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}

START_TEST(strncmp_identical_strings) {
  assert_strncmp("Hello, world!", "Hello, world!", 14);
}
END_TEST

START_TEST(strncmp_different_last_characters) {
  assert_strncmp("Hello, world!", "Hello, worldj", 14);
}
END_TEST

START_TEST(strncmp_empty_strings) {
  assert_strncmp("", "", 1);
}
END_TEST

START_TEST(strncmp_non_empty_vs_empty) {
  assert_strncmp("f", "", 1);
}
END_TEST

START_TEST(strncmp_empty_vs_non_empty) {
  assert_strncmp("", "j", 1);
}
END_TEST

START_TEST(strncmp_large_identical_numbers) {
  assert_strncmp("1242434246364377659", "1242434246364377659", 19);
}
END_TEST

START_TEST(strncmp_partial_string_comparison) {
  assert_strncmp("1242434246364377659", "1242434246364377659", 2);
}
END_TEST

START_TEST(strncmp_zero_length_comparison) {
  assert_strncmp("g124243425", "124243424", 0);
}
END_TEST

START_TEST(strncmp_identical_empty_strings) {
  assert_strncmp("", "", 1);
}
END_TEST

START_TEST(strncmp_edge_case_max_length) {
  assert_strncmp("Hello, world!", "Hello, world!", 10000);
}
END_TEST

START_TEST(strncmp_edge_case_overflow) {
  assert_strncmp("Hello, ", "world!", 10);
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCMP=-\033[0m");
  TCase *tc = tcase_create("strncmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncmp_identical_strings);
  tcase_add_test(tc, strncmp_different_last_characters);
  tcase_add_test(tc, strncmp_empty_strings);
  tcase_add_test(tc, strncmp_non_empty_vs_empty);
  tcase_add_test(tc, strncmp_empty_vs_non_empty);
  tcase_add_test(tc, strncmp_large_identical_numbers);
  tcase_add_test(tc, strncmp_partial_string_comparison);
  tcase_add_test(tc, strncmp_zero_length_comparison);
  tcase_add_test(tc, strncmp_identical_empty_strings);
  tcase_add_test(tc, strncmp_edge_case_max_length);
  tcase_add_test(tc, strncmp_edge_case_overflow);

  suite_add_tcase(s, tc);
  return s;
}
