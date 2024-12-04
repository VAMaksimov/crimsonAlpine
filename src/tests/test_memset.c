#include "test_me.h"

void assert_memset(const char *initial, int ch, s21_size_t n) {
  char s1[100] = {0};
  char s2[100] = {0};
  strncpy(s1, initial, sizeof(s1) - 1);
  strncpy(s2, initial, sizeof(s2) - 1);
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}

START_TEST(memset_full_replace) {
  assert_memset("Hello, world!", ' ', strlen("Hello, world!"));
}
END_TEST

START_TEST(memset_partial_replace) { assert_memset("Hello, world!", ' ', 5); }
END_TEST

START_TEST(memset_zero_length) { assert_memset("Hello, world!", ' ', 0); }
END_TEST

START_TEST(memset_empty_string) { assert_memset("", '\0', 0); }
END_TEST

START_TEST(memset_null_character) { assert_memset("Hello", '\0', 4); }
END_TEST

START_TEST(memset_with_non_ascii) { assert_memset("Hello, world!", 80, 7); }
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMSET=-\033[0m");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, memset_full_replace);
  tcase_add_test(tc, memset_partial_replace);
  tcase_add_test(tc, memset_zero_length);
  tcase_add_test(tc, memset_empty_string);
  tcase_add_test(tc, memset_null_character);
  tcase_add_test(tc, memset_with_non_ascii);

  suite_add_tcase(s, tc);
  return s;
}
