#include "test_me.h"

void assert_strncmp(const char *s1, const char *s2, s21_size_t n) {
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}

START_TEST(standard_1) { assert_strncmp("Hello, world!", "Hello, world!", 14); }
END_TEST

START_TEST(standard_2) { assert_strncmp("Hello, world!", "Hello, worldj", 14); }
END_TEST

START_TEST(standard_3) { assert_strncmp("abcdef", "abcdeg", 5); }
END_TEST

START_TEST(border_1) { assert_strncmp("", "", 1); }
END_TEST

START_TEST(border_2) { assert_strncmp("f", "", 1); }
END_TEST

START_TEST(border_3) { assert_strncmp("", "j", 1); }
END_TEST

START_TEST(border_4) { assert_strncmp("g124243425", "124243424", 0); }
END_TEST

START_TEST(irregular_1) {
  assert_strncmp("1242434246364377659", "1242434246364377659", 19);
}
END_TEST

START_TEST(irregular_2) {
  assert_strncmp("1242434246364377659", "1242434246364377659", 2);
}
END_TEST

START_TEST(irregular_3) { assert_strncmp("Hello, ", "world!", 10); }
END_TEST

START_TEST(irregular_4) {
  assert_strncmp("Hello, world!", "Hello, world!", 10000);
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s = suite_create("\033[47;30mstrncmp\033[0m");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, standard_1);
  tcase_add_test(tc, standard_2);
  tcase_add_test(tc, standard_3);

  tcase_add_test(tc, border_1);
  tcase_add_test(tc, border_2);
  tcase_add_test(tc, border_3);
  tcase_add_test(tc, border_4);

  tcase_add_test(tc, irregular_1);
  tcase_add_test(tc, irregular_2);
  tcase_add_test(tc, irregular_3);
  tcase_add_test(tc, irregular_4);

  suite_add_tcase(s, tc);
  return s;
}
