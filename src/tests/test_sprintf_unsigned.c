#include "test_me.h"

START_TEST(sprintf_1_unsigned) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "Word %u Word";
  unsigned int val = 012;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%u Word %u Word %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%u Word %u Word %u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%lu Word %lu Word %hu Word %hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%3u Word %5u Word %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.5u Word %.23u Word %3.u Word %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%-10.5u Word %-.8u Word %-7u Word %-.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%0u Word %0.u Word %0.0u Word %0u Word %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%+u Word %+3.u Word %+5.7u Word %+10u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%u Word %3.u Word %5.7u Word %10u %#u %-u %+u %.u % .u";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "% u Word % 3.u Word % 5.7u Word % 10u Word %.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%+u Word %+3.u Word %+5.7u Word %+10u Word %+.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 3261;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%#u Word %#3u Word %#5.7u Word %#.7u Word %#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%0u Word %06u Word %05.7u Word %0.7u Word %0.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%*u Word %-*u Word %*.*u Word %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;

  sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "Wordword %lu";
  unsigned long int val = ULONG_MAX;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_unsigned) {
  char str1[400];
  char str2[400];
  char *str3 = "%- u Word %- 15u Word %- 15u Word %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
Suite *test_sprintf_unsigned(void) {
  Suite *s = suite_create("\033[47;30msprintf_unsigned\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_unsigned);
  tcase_add_test(tc, sprintf_2_unsigned);
  tcase_add_test(tc, sprintf_3_unsigned);
  tcase_add_test(tc, sprintf_4_unsigned);
  tcase_add_test(tc, sprintf_5_unsigned);
  tcase_add_test(tc, sprintf_6_unsigned);
  tcase_add_test(tc, sprintf_7_unsigned);
  tcase_add_test(tc, sprintf_8_unsigned);
  tcase_add_test(tc, sprintf_9_unsigned);
  tcase_add_test(tc, sprintf_10_unsigned);
  tcase_add_test(tc, sprintf_11_unsigned);
  tcase_add_test(tc, sprintf_12_unsigned);
  tcase_add_test(tc, sprintf_13_unsigned);
  tcase_add_test(tc, sprintf_14_unsigned);
  tcase_add_test(tc, sprintf_15_unsigned);
  tcase_add_test(tc, sprintf_16_unsigned);
  tcase_add_test(tc, sprintf_17_unsigned);

  suite_add_tcase(s, tc);
  return s;
}
