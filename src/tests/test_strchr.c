#include "test_me.h"

void assert_strchr(const char *str, int ch) {
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}

START_TEST(standart_1) { assert_strchr("Hello, world!", 'h'); }
END_TEST

START_TEST(standart_2) { assert_strchr("Hello, world!", ','); }
END_TEST

START_TEST(standart_3) { assert_strchr("Hello, Polina!", 'P'); }
END_TEST

START_TEST(border_1) { assert_strchr("Hello, world!", '\0'); }
END_TEST

START_TEST(border_2) { assert_strchr("Hello, world!", 33); }
END_TEST

START_TEST(border_3) { assert_strchr("Hello, world!", 'm'); }
END_TEST

START_TEST(irregular_1) { assert_strchr("Hello, world!", 'w'); }
END_TEST

START_TEST(irregular_2) { assert_strchr("Hello, world!", '0'); }
END_TEST

START_TEST(irregular_3) { assert_strchr("Hello, world!", 'x'); }
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("\033[47;30mstrchr\033[0m");
  TCase *tc = tcase_create("strchr_tc");

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
