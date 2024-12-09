#include "test_me.h"

void assert_insert(const char *s1, const char *s3, size_t num,
                   const char *expected) {
  char *result = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(expected, result);
  if (result) free(result);
}

START_TEST(standart_1) {
  assert_insert("hello, world!", "hELLO, WORLD!", 7,
                "hello, hELLO, WORLD!world!");
}
END_TEST

START_TEST(standart_2) {
  assert_insert("abcdefghij", "'I WAS HERE'", 3, "abc'I WAS HERE'defghij");
}
END_TEST

START_TEST(standart_3) { assert_insert("abc", "333", 10, NULL); }
END_TEST

START_TEST(border_1) { assert_insert("", "", 0, ""); }
END_TEST

START_TEST(border_2) {
  assert_insert("hello, world!", "hELLO, WORLD!", -1, NULL);
}
END_TEST

START_TEST(border_3) { assert_insert(NULL, "", 0, NULL); }
END_TEST

START_TEST(border_4) { assert_insert("", NULL, 0, NULL); }
END_TEST

START_TEST(irregular_1) { assert_insert("wtf", NULL, 0, NULL); }
END_TEST

START_TEST(irregular_2) { assert_insert(NULL, NULL, 0, NULL); }
END_TEST

START_TEST(irregular_3) { assert_insert("", "", 7, NULL); }
END_TEST

START_TEST(irregular_4) { assert_insert("non-empty", "insert", 20, NULL); }
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[47;30minsert\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, standart_1);
  tcase_add_test(tc, standart_2);
  tcase_add_test(tc, standart_3);

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
