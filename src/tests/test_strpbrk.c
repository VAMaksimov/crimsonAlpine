#include "test_me.h"

void assert_strpbrk(const char *s1, const char *s2) {
  const char *expected = strpbrk(s1, s2);
  const char *result = s21_strpbrk(s1, s2);
  ck_assert_pstr_eq(expected, result);
}

START_TEST(test_strpbrk_identical_strings) {
  assert_strpbrk("Hello, world!", "Hello, world!");
}
END_TEST

START_TEST(test_strpbrk_single_char_in_second) {
  assert_strpbrk("Hello, world!", "!");
}
END_TEST

START_TEST(test_strpbrk_empty_first_string) {
  assert_strpbrk("", "He");
}
END_TEST

START_TEST(test_strpbrk_null_character_in_first) {
  assert_strpbrk("\0", "");
}
END_TEST

START_TEST(test_strpbrk_both_empty_strings) {
  assert_strpbrk("", "");
}
END_TEST

START_TEST(test_strpbrk_partial_match_in_numbers) {
  assert_strpbrk("1242434246364377659", "364377659");
}
END_TEST

START_TEST(test_strpbrk_no_common_characters) {
  assert_strpbrk("abcdef", "12345");
}
END_TEST

START_TEST(test_strpbrk_first_longer_than_second) {
  assert_strpbrk("abcdef12345", "35");
}
END_TEST

START_TEST(test_strpbrk_second_longer_than_first) {
  assert_strpbrk("123", "abcdefgh123456");
}
END_TEST

START_TEST(test_strpbrk_only_special_characters) {
  assert_strpbrk("@#$%^&*", "!@#$");
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("\033[45m-=S21_STRPBRK=-\033[0m");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, test_strpbrk_identical_strings);
  tcase_add_test(tc, test_strpbrk_single_char_in_second);
  tcase_add_test(tc, test_strpbrk_empty_first_string);
  tcase_add_test(tc, test_strpbrk_null_character_in_first);
  tcase_add_test(tc, test_strpbrk_both_empty_strings);
  tcase_add_test(tc, test_strpbrk_partial_match_in_numbers);
  tcase_add_test(tc, test_strpbrk_no_common_characters);
  tcase_add_test(tc, test_strpbrk_first_longer_than_second);
  tcase_add_test(tc, test_strpbrk_second_longer_than_first);
  tcase_add_test(tc, test_strpbrk_only_special_characters);

  suite_add_tcase(s, tc);
  return s;
}
