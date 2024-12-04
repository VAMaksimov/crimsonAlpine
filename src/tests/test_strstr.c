#include "test_me.h"

void assert_strstr(const char *haystack, const char *needle) {
  const char *expected = strstr(haystack, needle);
  const char *result = s21_strstr(haystack, needle);
  ck_assert_pstr_eq(expected, result);
}

START_TEST(test_strstr_full_match) {
  assert_strstr("Hello, world!", "Hello, world!");
}
END_TEST

START_TEST(test_strstr_no_match) {
  assert_strstr("Hello, world!", "Hello, P!");
}
END_TEST

START_TEST(test_strstr_substring_at_end) {
  assert_strstr("Hello, world!", "!");
}
END_TEST

START_TEST(test_strstr_repeated_pattern) {
  assert_strstr("Hello, world!Hello, world!Hello, world!Hello, world!", "world");
}
END_TEST

START_TEST(test_strstr_both_empty) {
  assert_strstr("", "");
}
END_TEST

START_TEST(test_strstr_empty_needle) {
  assert_strstr("Hello, world!", "");
}
END_TEST

START_TEST(test_strstr_empty_haystack) {
  assert_strstr("", "Hello, P!");
}
END_TEST

START_TEST(test_strstr_digit_match) {
  assert_strstr("69917020", "0");
}
END_TEST

START_TEST(test_strstr_empty_needle_in_non_empty_haystack) {
  assert_strstr("69917020", "\0");
}
END_TEST

START_TEST(test_strstr_needle_longer_than_haystack) {
  assert_strstr("69917020", "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw");
}
END_TEST

START_TEST(test_strstr_repeated_digits) {
  assert_strstr("1   345 345 345 345 345", "345");
}
END_TEST

START_TEST(test_strstr_pattern_with_overlap) {
  assert_strstr("sususususpicioussusususpicious", "susp");
}
END_TEST

START_TEST(test_strstr_pattern_larger_than_haystack) {
  assert_strstr("sus", "suspi");
}
END_TEST

START_TEST(test_strstr_special_characters) {
  assert_strstr("!@#$%^&*()_+", "^&");
}
END_TEST

START_TEST(test_strstr_whitespace_only) {
  assert_strstr("     ", " ");
}
END_TEST

START_TEST(test_strstr_substring_with_spaces) {
  assert_strstr("This is a test string", "test");
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRSTR=-\033[0m");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, test_strstr_full_match);
  tcase_add_test(tc, test_strstr_no_match);
  tcase_add_test(tc, test_strstr_substring_at_end);
  tcase_add_test(tc, test_strstr_repeated_pattern);
  tcase_add_test(tc, test_strstr_both_empty);
  tcase_add_test(tc, test_strstr_empty_needle);
  tcase_add_test(tc, test_strstr_empty_haystack);
  tcase_add_test(tc, test_strstr_digit_match);
  tcase_add_test(tc, test_strstr_empty_needle_in_non_empty_haystack);
  tcase_add_test(tc, test_strstr_needle_longer_than_haystack);
  tcase_add_test(tc, test_strstr_repeated_digits);
  tcase_add_test(tc, test_strstr_pattern_with_overlap);
  tcase_add_test(tc, test_strstr_pattern_larger_than_haystack);
  tcase_add_test(tc, test_strstr_special_characters);
  tcase_add_test(tc, test_strstr_whitespace_only);
  tcase_add_test(tc, test_strstr_substring_with_spaces);

  suite_add_tcase(s, tc);
  return s;
}
