
#include "test_me.h"
void assert_memcmp(const char *s1, const char *s2, s21_size_t n) {
  ck_assert_int_eq(memcmp(s1, s2, n), s21_memcmp(s1, s2, n));
}

START_TEST(memcmp_equal) { assert_memcmp("Hello", "Hello", 5); }
END_TEST

START_TEST(memcmp_unequal) { assert_memcmp("Hello", "World", 3); }
END_TEST

START_TEST(memcmp_empty_strings) { assert_memcmp("", "", 0); }
END_TEST

START_TEST(memcmp_partial) { assert_memcmp("Hello", "Helxo", 3); }
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCMP=-\033[0m");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, memcmp_equal);
  tcase_add_test(tc, memcmp_unequal);
  tcase_add_test(tc, memcmp_empty_strings);
  tcase_add_test(tc, memcmp_partial);

  suite_add_tcase(s, tc);
  return s;
}
