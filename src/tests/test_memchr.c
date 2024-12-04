#include "test_me.h"

void assert_memchr(const char *s, int c, s21_size_t n) {
  ck_assert_ptr_eq(memchr(s, c, n), s21_memchr(s, c, n));
}

START_TEST(memchr_found) {
  assert_memchr("Hello, world!", 'w', strlen("Hello, world!"));
}
END_TEST

START_TEST(memchr_not_found) {
  assert_memchr("Hello, world!", 'z', strlen("Hello, world!"));
}
END_TEST

START_TEST(memchr_first_char) {
  assert_memchr("Hello, world!", 'H', strlen("Hello, world!"));
}
END_TEST

START_TEST(memchr_last_char) {
  assert_memchr("Hello, world!", '!', strlen("Hello, world!"));
}
END_TEST

Suite *test_memchr(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCHR=-\033[0m");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, memchr_found);
  tcase_add_test(tc, memchr_not_found);
  tcase_add_test(tc, memchr_first_char);
  tcase_add_test(tc, memchr_last_char);

  suite_add_tcase(s, tc);
  return s;
}
