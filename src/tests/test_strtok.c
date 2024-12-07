#include "test_me.h"

void assert_strtok(char *s1, char *s2, char *delim) {
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
START_TEST(standard_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char delim[] = "!";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(standard_2) {
  char s1[] = "";
  char s2[] = "";
  char delim[] = "";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(border_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char delim[] = "\0";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(border_2) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char delim[] = "";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(border_3) {
  char *s1 = S21_NULL;
  char *s2 = S21_NULL;
  char delim[] = " ";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(irregular_1) {
  char s1[] = "tuz-tuz-tuz";
  char s2[] = "tuz-tuz-tuz";
  char delim[] = "z";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(irregular_2) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char delim[] = "R";
  strtok(s1, delim);
  strtok(NULL, delim);
  s21_strtok(s2, delim);
  s21_strtok(NULL, delim);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(irregular_3) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char delim[] = "MYPHONENUM6869";
  char *res1 = strtok(s1, delim);
  char *res2 = strtok(S21_NULL, delim);

  char *res3 = s21_strtok(s2, delim);
  char *res4 = s21_strtok(S21_NULL, delim);

  ck_assert_pstr_eq(res1, res3);
  ck_assert_pstr_eq(res2, res4);
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("\033[47;30mstrtok\033[0m");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, standard_1);
  tcase_add_test(tc, standard_2);

  tcase_add_test(tc, border_1);
  tcase_add_test(tc, border_2);
  tcase_add_test(tc, border_3);

  tcase_add_test(tc, irregular_1);
  tcase_add_test(tc, irregular_2);
  tcase_add_test(tc, irregular_3);

  suite_add_tcase(s, tc);
  return s;
}
