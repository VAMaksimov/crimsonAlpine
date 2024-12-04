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

START_TEST(test_strncpy_basic_copy) {
  assert_strncpy("Good", 5, "Hello, world!", "Hello, world!", 20);
}
END_TEST

START_TEST(test_strncpy_empty_source) {
  assert_strncpy("\0", 1, "Hello, world!", "Hello, world!", 20);
}
END_TEST

START_TEST(test_strncpy_partial_unicode) {
  assert_strncpy("fг-аг-аг", 1, "Hello, world!", "Hello, world!", 30);
}
END_TEST

START_TEST(test_strncpy_empty_source_empty_destination) {
  assert_strncpy("", 0, "", "", 5);
}
END_TEST

START_TEST(test_strncpy_large_copy) {
  assert_strncpy(
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!",
      strlen("I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!"),
      "", "", 70);
}
END_TEST

START_TEST(test_strncpy_null_character) {
  assert_strncpy("\0", 1, "", "", 5);
}
END_TEST

START_TEST(test_strncpy_max_length_overflow) {
  assert_strncpy("12345678901234567890", 15, "AAAAAAAAAA", "AAAAAAAAAA", 10);
}
END_TEST

START_TEST(test_strncpy_zero_length) {
  assert_strncpy("Test String", 0, "Original", "Original", 20);
}
END_TEST

START_TEST(test_strncpy_no_null_termination) {
  assert_strncpy("123456", 6, "abcdef", "abcdef", 6);
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCPY=-\033[0m");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, test_strncpy_basic_copy);
  tcase_add_test(tc, test_strncpy_empty_source);
  tcase_add_test(tc, test_strncpy_partial_unicode);
  tcase_add_test(tc, test_strncpy_empty_source_empty_destination);
  tcase_add_test(tc, test_strncpy_large_copy);
  tcase_add_test(tc, test_strncpy_null_character);
  tcase_add_test(tc, test_strncpy_max_length_overflow);
  tcase_add_test(tc, test_strncpy_zero_length);
  tcase_add_test(tc, test_strncpy_no_null_termination);

  suite_add_tcase(s, tc);
  return s;
}
