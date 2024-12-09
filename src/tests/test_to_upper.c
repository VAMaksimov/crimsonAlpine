#include "test_me.h"

void assert_to_upper(const char *input, const char *expected) {
  char *result = s21_to_upper(input);
  ck_assert_pstr_eq(expected, result);
  if (result) free(result);
}

START_TEST(standart_1) { assert_to_upper("Hello, world!", "HELLO, WORLD!"); }
END_TEST

START_TEST(standart_2) { assert_to_upper("\nh\t\\g123123", "\nH\t\\G123123"); }
END_TEST

START_TEST(standart_3) {
  assert_to_upper("abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
END_TEST

START_TEST(border_1) { assert_to_upper("", ""); }
END_TEST

START_TEST(border_2) { assert_to_upper("ALREADY UPPER", "ALREADY UPPER"); }
END_TEST

START_TEST(border_3) { assert_to_upper(NULL, NULL); }
END_TEST

START_TEST(irregular_1) { assert_to_upper("_?};!234", "_?};!234"); }
END_TEST

START_TEST(irregular_2) { assert_to_upper("123456", "123456"); }
END_TEST

START_TEST(irregular_3) { assert_to_upper("mixed CASE 123", "MIXED CASE 123"); }
END_TEST

START_TEST(irregular_4) { assert_to_upper("!!!Hello!!!", "!!!HELLO!!!"); }
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("\033[47;30mto_upper\033[0m");
  TCase *tc = tcase_create("to_upper_tc");

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
