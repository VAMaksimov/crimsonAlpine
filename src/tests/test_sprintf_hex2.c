#include "test_me.h"

START_TEST(sprintf_1_HEX) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "Word %X Word";
  int val = 0X32;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%X Word %X Word %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%X Word %X Word %X";
  int val = 0X3015;
  int val2 = 0X712;
  int val3 = 0X99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%lX Word %lX Word %hX Word %hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%3X Word %5X Word %10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.5X Word %.23X Word %3.X Word %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%-10.5X Word %-.8X Word %-7X Word %-.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%0X Word %0.X Word %0.0X Word %0X Word %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%+X Word %+3.X Word %+5.7X Word %+10X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%X Word %3.X Word %5.7X Word %10X %#X %-X %+X %.X % .X";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "% X Word % 3.X Word % 5.7X TEST % 10X Word %.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%+X Word %+3.X Word %+5.7X Word %+10X Word %+.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%#X Word %#3X Word %#5.7X Word %#.7X Word %#.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%0X Word %06X Word %05.7X Word %0.7X Word %0.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%*X Word %-*X Word %*.*X Word %.*X";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;

  sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_HEX) {
  char str1[400];
  char str2[400];
  char *str3 = "%- X Word %- 15X Word %- 15X Word %- X";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_HEX(void) {
  Suite *s = suite_create("\033[47;30msprintf_HEX2\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_HEX);
  tcase_add_test(tc, sprintf_2_HEX);
  tcase_add_test(tc, sprintf_3_HEX);
  tcase_add_test(tc, sprintf_4_HEX);
  tcase_add_test(tc, sprintf_5_HEX);
  tcase_add_test(tc, sprintf_6_HEX);
  tcase_add_test(tc, sprintf_7_HEX);
  tcase_add_test(tc, sprintf_8_HEX);
  tcase_add_test(tc, sprintf_9_HEX);
  tcase_add_test(tc, sprintf_10_HEX);
  tcase_add_test(tc, sprintf_11_HEX);
  tcase_add_test(tc, sprintf_12_HEX);
  tcase_add_test(tc, sprintf_13_HEX);
  tcase_add_test(tc, sprintf_14_HEX);
  tcase_add_test(tc, sprintf_15_HEX);
  tcase_add_test(tc, sprintf_16_HEX);

  suite_add_tcase(s, tc);
  return s;
}