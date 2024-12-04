#include "test_me.h"

void assert_strrchr(const char *s, int ch) {
  const char *expected = strrchr(s, ch);
  const char *result = s21_strrchr(s, ch);
  ck_assert_pstr_eq(expected, result);
}

START_TEST(test_strrchr_char_not_found) {
  assert_strrchr("Hello, world!", 'h');
}
END_TEST

START_TEST(test_strrchr_null_character) {
  assert_strrchr("Hello, world!", '\0');
}
END_TEST

START_TEST(test_strrchr_common_character) {
  assert_strrchr("Hello, world!", ',');
}
END_TEST

START_TEST(test_strrchr_ascii_character) {
  assert_strrchr("Hello, world!", 33);
}
END_TEST

START_TEST(test_strrchr_first_occurrence) {
  assert_strrchr("Hello, Polina!", 'P');
}
END_TEST

START_TEST(test_strrchr_middle_character) {
  assert_strrchr("Hello, world!", 'w');
}
END_TEST

START_TEST(test_strrchr_digit_not_in_string) {
  assert_strrchr("Hello, world!", '0');
}
END_TEST

START_TEST(test_strrchr_uncommon_character) {
  assert_strrchr("Hello, world!", 'm');
}
END_TEST

START_TEST(test_strrchr_empty_string) {
  assert_strrchr("", 'H');
}
END_TEST

START_TEST(test_strrchr_only_null_character) {
  assert_strrchr("\0", '\0');
}
END_TEST

START_TEST(test_strrchr_multiple_occurrences) {
  assert_strrchr("aaabbbccc", 'b');
}
END_TEST

START_TEST(test_strrchr_whitespace_character) {
  assert_strrchr("Hello, world!\n\t ", '\n');
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRRCHR=-\033[0m");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, test_strrchr_char_not_found);
  tcase_add_test(tc, test_strrchr_null_character);
  tcase_add_test(tc, test_strrchr_common_character);
  tcase_add_test(tc, test_strrchr_ascii_character);
  tcase_add_test(tc, test_strrchr_first_occurrence);
  tcase_add_test(tc, test_strrchr_middle_character);
  tcase_add_test(tc, test_strrchr_digit_not_in_string);
  tcase_add_test(tc, test_strrchr_uncommon_character);
  tcase_add_test(tc, test_strrchr_empty_string);
  tcase_add_test(tc, test_strrchr_only_null_character);
  tcase_add_test(tc, test_strrchr_multiple_occurrences);
  tcase_add_test(tc, test_strrchr_whitespace_character);

  suite_add_tcase(s, tc);
  return s;
}
