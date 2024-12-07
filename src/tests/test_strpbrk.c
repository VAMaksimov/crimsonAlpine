#include "test_me.h"

void assert_strpbrk(const char *s1, const char *s2) {
  const char *expected = strpbrk(s1, s2);
  const char *result = s21_strpbrk(s1, s2);
  ck_assert_pstr_eq(expected, result);
}

START_TEST(standard_1) { assert_strpbrk("Hello, world!", "Hello, world!"); }
END_TEST

START_TEST(standard_2) { assert_strpbrk("Hello, world!", "!"); }
END_TEST

START_TEST(standard_3) { assert_strpbrk("abcdef12345", "35"); }
END_TEST

START_TEST(standard_4) { assert_strpbrk("123", "abcdefgh123456"); }
END_TEST

START_TEST(standard_5) { assert_strpbrk("1242434246364377659", "364377659"); }
END_TEST

START_TEST(border_1) { assert_strpbrk("", "He"); }
END_TEST

START_TEST(border_2) { assert_strpbrk("\0", ""); }
END_TEST

START_TEST(border_3) { assert_strpbrk("", ""); }
END_TEST

START_TEST(border_4) { assert_strpbrk("abcdef", "12345"); }
END_TEST

START_TEST(irregular_1) { assert_strpbrk("@#$%^&*", "!@#$"); }
END_TEST

START_TEST(irregular_2) { assert_strpbrk("abcdef\0hidden", "hidden"); }
END_TEST

START_TEST(irregular_3) { assert_strpbrk("abc\tdef\n", "\n\t"); }
END_TEST

START_TEST(irregular_4) { assert_strpbrk("123456", " 123"); }
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("\033[47;30mstrpbrk\033[0m");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, standard_1);
  tcase_add_test(tc, standard_2);
  tcase_add_test(tc, standard_3);
  tcase_add_test(tc, standard_4);
  tcase_add_test(tc, standard_5);

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
