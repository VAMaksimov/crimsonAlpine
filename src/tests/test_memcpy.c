#include "test_me.h"

void assert_memcpy(const char *expected, const char *actual, const char *src,
                   s21_size_t n) {
  char s1[100] = {0};
  char s2[100] = {0};
  strncpy(s1, expected, sizeof(s1) - 1);
  strncpy(s2, actual, sizeof(s2) - 1);
  ck_assert_str_eq(memcpy(s1, src, n), s21_memcpy(s2, src, n));
}

START_TEST(memcpy_basic) {
  assert_memcpy("Hello, world!", "Hello, world!", "Good", 4);
}
END_TEST

START_TEST(memcpy_empty_source) {
  assert_memcpy("Hello, world!", "Hello, world!", "\0", 1);
}
END_TEST

START_TEST(memcpy_zero_length) {
  assert_memcpy("Hello, world!", "Hello, world!", "f", 0);
}
END_TEST

START_TEST(memcpy_partial_copy) {
  assert_memcpy("Hello, world!", "Hello, world!", "Hi", 2);
}
END_TEST

START_TEST(memcpy_large_copy) {
  assert_memcpy("new_strnew_string", "new_strnew_string", "new_string",
                strlen("new_string"));
}
END_TEST

START_TEST(memcpy_non_ascii) {
  assert_memcpy("699\017020", "699\017020", "com", 3);
}
END_TEST

START_TEST(memcpy_with_null_chars) {
  assert_memcpy("ABC\0DEF", "ABC\0DEF", "XYZ\0123", 7);
}
END_TEST

START_TEST(memcpy_overlap_forward) {
  char buffer1[30] = "Overlap test data";
  char buffer2[30] = "Overlap test data";
  ck_assert_str_eq(memcpy(buffer1 + 5, buffer1, 10),
                   s21_memcpy(buffer2 + 5, buffer2, 10));
}
END_TEST

START_TEST(memcpy_overlap_backward) {
  char buffer1[30] = "Overlap test data";
  char buffer2[30] = "Overlap test data";
  ck_assert_str_eq(memcpy(buffer1, buffer1 + 5, 10),
                   s21_memcpy(buffer2, buffer2 + 5, 10));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCPY=-\033[0m");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, memcpy_basic);
  tcase_add_test(tc, memcpy_empty_source);
  tcase_add_test(tc, memcpy_zero_length);
  tcase_add_test(tc, memcpy_partial_copy);
  tcase_add_test(tc, memcpy_large_copy);
  tcase_add_test(tc, memcpy_non_ascii);
  tcase_add_test(tc, memcpy_with_null_chars);
  tcase_add_test(tc, memcpy_overlap_forward);
  tcase_add_test(tc, memcpy_overlap_backward);

  suite_add_tcase(s, tc);
  return s;
}
