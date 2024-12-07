#include "test_me.h"

void assert_trim(const char *input, const char *trim_chars,
                 const char *expected) {
  char *result = s21_trim(input, trim_chars);
  ck_assert_pstr_eq(expected, result);
  if (result) free(result);
}

START_TEST(standart_1) {
  assert_trim("-?hello, world!", "!?-", "hello, world");
}
END_TEST

START_TEST(standart_2) { assert_trim("!!!abcdefghij!?!", "!?", "abcdefghij"); }
END_TEST

START_TEST(standart_3) { assert_trim("abc", "333", "abc"); }
END_TEST

START_TEST(border_1) { assert_trim("", "", ""); }
END_TEST

START_TEST(border_2) { assert_trim(S21_NULL, "", S21_NULL); }
END_TEST

START_TEST(border_3) { assert_trim(" wtf ", "", " wtf "); }
END_TEST

START_TEST(irregular_1) { assert_trim("hello, world!", "?!", "hello, world"); }
END_TEST

START_TEST(irregular_2) { assert_trim("hello!!!", "!", "hello"); }
END_TEST

START_TEST(irregular_3) { assert_trim("??hello??", "?", "hello"); }
END_TEST

START_TEST(irregular_4) { assert_trim("   hello   ", " ", "hello"); }
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("\033[47;30mtrim\033[0m");
  TCase *tc = tcase_create("trim_tc");

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
