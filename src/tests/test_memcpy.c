#include "test_me.h"

void assert_memcpy(const char *expected, const char *actual, const char *src,
                   s21_size_t n) {
  char s1[100] = {0};
  char s2[100] = {0};
  strncpy(s1, expected, sizeof(s1) - 1);
  strncpy(s2, actual, sizeof(s2) - 1);
  ck_assert_str_eq(memcpy(s1, src, n), s21_memcpy(s2, src, n));
}

START_TEST(standart_1) {
  assert_memcpy("Hello, world!", "Hello, world!", "Good", 4);
}
END_TEST

START_TEST(standart_2) {
  assert_memcpy("Hello, world!", "Hello, world!", "Hi", 2);
}
END_TEST

START_TEST(standart_3) {
  assert_memcpy("Hello, world!", "Hello, world!", "Goodbye", 7);
}
END_TEST

START_TEST(border_1) {
  assert_memcpy("Hello, world!", "Hello, world!", "\0", 1);
}
END_TEST

START_TEST(border_2) {
  assert_memcpy("Hello, world!", "Hello, world!", "f", 0);
}
END_TEST

START_TEST(border_3) {
  assert_memcpy("new_strnew_string", "new_strnew_string", "new_string",
                strlen("new_string"));
}
END_TEST

START_TEST(irregular_1) { assert_memcpy("699\017020", "699\017020", "com", 3); }
END_TEST

START_TEST(irregular_2) {
  assert_memcpy("ABC\0DEF", "ABC\0DEF", "XYZ\0123", 7);
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("\033[47;30mmemcpy\033[0m");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, standart_1);
  tcase_add_test(tc, standart_2);
  tcase_add_test(tc, standart_3);

  tcase_add_test(tc, border_1);
  tcase_add_test(tc, border_2);
  tcase_add_test(tc, border_3);

  tcase_add_test(tc, irregular_1);
  tcase_add_test(tc, irregular_2);

  suite_add_tcase(s, tc);
  return s;
}
