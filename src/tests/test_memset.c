#include "test_me.h"

void assert_memset(const char *initial, int ch, s21_size_t n) {
  char s1[100] = {0};
  char s2[100] = {0};
  strncpy(s1, initial, sizeof(s1) - 1);
  strncpy(s2, initial, sizeof(s2) - 1);
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}

START_TEST(standart_1) {
  assert_memset("Hello, world!", ' ', strlen("Hello, world!"));
}
END_TEST

START_TEST(standart_2) {
  assert_memset("Hello, world!", ' ', 5);
}
END_TEST

START_TEST(standart_3) {
  assert_memset("Hello, world!", ' ', 0);
}
END_TEST

START_TEST(border_1) {
  assert_memset("", '\0', 0);
}
END_TEST

START_TEST(border_2) {
  assert_memset("Hello", '\0', 4);
}
END_TEST

START_TEST(border_3) {
  assert_memset("Hello, world!", 80, 7);
}
END_TEST

START_TEST(irregular_1) {
  assert_memset("12345", 'x', 2);
}
END_TEST

START_TEST(irregular_2) {
  assert_memset("abc", 'z', 3);
}
END_TEST

START_TEST(irregular_3) {
  assert_memset("This is a test string!", 42, 10);
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMSET=-\033[0m");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, standart_1);
  tcase_add_test(tc, standart_2);
  tcase_add_test(tc, standart_3);

  tcase_add_test(tc, border_1);
  tcase_add_test(tc, border_2);
  tcase_add_test(tc, border_3);

  tcase_add_test(tc, irregular_1);
  tcase_add_test(tc, irregular_2);
  tcase_add_test(tc, irregular_3);

  suite_add_tcase(s, tc);
  return s;
}
