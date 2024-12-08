#include "test_me.h"

void assert_strrchr(const char *s, int ch) {
  const char *expected = strrchr(s, ch);
  const char *result = s21_strrchr(s, ch);
  ck_assert_pstr_eq(expected, result);
}

START_TEST(standard_1) { assert_strrchr("Hello, world!", ','); }
END_TEST

START_TEST(standard_2) { assert_strrchr("Hello, world!", 'w'); }
END_TEST

START_TEST(standard_3) { assert_strrchr("Hello, Polina!", 'P'); }
END_TEST

START_TEST(standard_4) { assert_strrchr("Hello, world!", 33); }
END_TEST

START_TEST(standard_5) { assert_strrchr("aaabbbccc", 'b'); }
END_TEST

START_TEST(border_1) { assert_strrchr("Hello, world!", 'h'); }
END_TEST

START_TEST(border_2) { assert_strrchr("", 'H'); }
END_TEST

START_TEST(border_3) { assert_strrchr("\0", '\0'); }
END_TEST

START_TEST(border_4) { assert_strrchr("Hello, world!", '\0'); }
END_TEST

START_TEST(border_5) { assert_strrchr("Hello, world!", '0'); }
END_TEST

START_TEST(irregular_1) { assert_strrchr("Hello, world!", 'm'); }
END_TEST

START_TEST(irregular_2) { assert_strrchr("Hello, world!\n\t ", '\n'); }
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("\033[47;30mstrchr\033[0m");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, standard_1);
  tcase_add_test(tc, standard_2);
  tcase_add_test(tc, standard_3);
  tcase_add_test(tc, standard_4);
  tcase_add_test(tc, standard_5);

  tcase_add_test(tc, border_1);
  tcase_add_test(tc, border_2);
  tcase_add_test(tc, border_3);
  tcase_add_test(tc, border_4);
  tcase_add_test(tc, border_5);

  tcase_add_test(tc, irregular_1);
  tcase_add_test(tc, irregular_2);

  suite_add_tcase(s, tc);
  return s;
}
