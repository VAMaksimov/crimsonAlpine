#include "test_me.h"

void assert_strstr(const char *haystack, const char *needle) {
  const char *expected = strstr(haystack, needle);
  const char *result = s21_strstr(haystack, needle);
  ck_assert_pstr_eq(expected, result);
}

START_TEST(standard_1) { assert_strstr("Hello, world!", "Hello, world!"); }
END_TEST

START_TEST(standard_2) { assert_strstr("Hello, world!", "world"); }
END_TEST

START_TEST(standard_3) { assert_strstr("Hello, world!", "!"); }
END_TEST

START_TEST(standard_4) { assert_strstr("This is a test string", "test"); }
END_TEST

START_TEST(standard_5) { assert_strstr("1   345 345 345 345 345", "345"); }
END_TEST

START_TEST(border_1) { assert_strstr("", ""); }
END_TEST

START_TEST(border_2) { assert_strstr("Hello, world!", ""); }
END_TEST

START_TEST(border_3) { assert_strstr("", "Hello"); }
END_TEST

START_TEST(border_4) { assert_strstr("Hello", "\0"); }
END_TEST

START_TEST(border_5) { assert_strstr("sus", "suspi"); }
END_TEST

START_TEST(irregular_1) { assert_strstr("69917020", "0"); }
END_TEST

START_TEST(irregular_2) {
  assert_strstr("69917020", "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw");
}
END_TEST

START_TEST(irregular_3) {
  assert_strstr("sususususpicioussusususpicious", "susp");
}
END_TEST

START_TEST(irregular_4) { assert_strstr("!@#$%^&*()_+", "^&"); }
END_TEST

START_TEST(irregular_5) { assert_strstr("     ", " "); }
END_TEST

START_TEST(irregular_6) {
  assert_strstr("Hello, world!Hello, world!Hello, world!Hello, world!",
                "world");
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("\033[47;30mstrstr\033[0m");
  TCase *tc = tcase_create("strstr_tc");

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
  tcase_add_test(tc, irregular_3);
  tcase_add_test(tc, irregular_4);
  tcase_add_test(tc, irregular_5);
  tcase_add_test(tc, irregular_6);

  suite_add_tcase(s, tc);
  return s;
}
