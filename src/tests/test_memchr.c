#include "test_me.h"

void assert_memchr(const char *s, int c, s21_size_t n) {
  ck_assert_ptr_eq(memchr(s, c, n), s21_memchr(s, c, n));
}

START_TEST(standart_1) {
  assert_memchr("Hello, world!", 'w', strlen("Hello, world!"));
}
END_TEST

START_TEST(standart_2) {
  assert_memchr("Hello, world!", 'z', strlen("Hello, world!"));
}
END_TEST

START_TEST(standart_3) {
  assert_memchr("Hello, world!", 'H', strlen("Hello, world!"));
}
END_TEST

START_TEST(border_1) {
  assert_memchr("Hello, world!", '!', strlen("Hello, world!"));
}
END_TEST

START_TEST(border_2) { assert_memchr("", 'H', 0); }
END_TEST

START_TEST(border_3) { assert_memchr("12345", '5', 5); }
END_TEST

START_TEST(irregular_1) { assert_memchr("abcdef", 'a', 6); }
END_TEST

START_TEST(irregular_2) { assert_memchr("abcdefgh", 'x', 8); }
END_TEST

START_TEST(irregular_3) { assert_memchr("1234567890", '1', 10); }
END_TEST

START_TEST(irregular_4) { assert_memchr("hello", 'e', 5); }
END_TEST

Suite *test_memchr(void) {
  Suite *s = suite_create("\033[47;30mmemchr\033[0m");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, standart_1);
  tcase_add_test(tc, standart_2);
  tcase_add_test(tc, standart_3);

  tcase_add_test(tc, border_1);
  tcase_add_test(tc, border_2);
  tcase_add_test(tc, border_3);

  tcase_add_test(tc, irregular_1);
  tcase_add_test(tc, irregular_2);
  tcase_add_test(tc, irregular_3);
  tcase_add_test(tc, irregular_4);

  suite_add_tcase(s, tc);
  return s;
}
