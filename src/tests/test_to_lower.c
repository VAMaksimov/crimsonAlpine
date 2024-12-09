#include "test_me.h"

void assert_to_lower(const char *input, const char *expected) {
  char *result = s21_to_lower(input);
  ck_assert_pstr_eq(expected, result);
  if (result) free(result);
}

START_TEST(standart_1) { assert_to_lower("HELLO, WORLD!", "hello, world!"); }
END_TEST

START_TEST(standart_2) { assert_to_lower("\nH\t\\G123123", "\nh\t\\g123123"); }
END_TEST

START_TEST(standart_3) {
  assert_to_lower("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz");
}
END_TEST

START_TEST(border_1) { assert_to_lower("", ""); }
END_TEST

START_TEST(border_2) { assert_to_lower("already lower", "already lower"); }
END_TEST

START_TEST(border_3) { assert_to_lower(NULL, NULL); }
END_TEST

START_TEST(irregular_1) { assert_to_lower("_?};!234", "_?};!234"); }
END_TEST

START_TEST(irregular_2) { assert_to_lower("123ABCdef", "123abcdef"); }
END_TEST

START_TEST(irregular_3) { assert_to_lower("!!!HELLO!!!", "!!!hello!!!"); }
END_TEST

START_TEST(irregular_4) {
  assert_to_lower("MiXeD CaSe StRiNg", "mixed case string");
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("\033[47;30mto_lower\033[0m");
  TCase *tc = tcase_create("to_lower_tc");

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
