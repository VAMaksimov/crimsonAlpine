#include "test_me.h"

START_TEST(sprintf_1_signed_i) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "Word %d Word";
  int val = -12;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%d Word %d Word %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%i Word %i Word %i";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%li Word %li Word %hi Word %hi";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%3i Word %5i Word %10i";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.5i Word %.23i Word %3.i Word %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%-10.5i Word %-.8i Word %-7i Word %-.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%0i Word %0.i Word %0.0i Word %0i Word %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%+i Word %+3.i Word %+5.7i Word %+10i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%i Word %3.i Word %5.7i Word %10i %#i %-i %+i %.i % .i";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "% i Word % 3.i Word % 5.7i Word % 10i Word %.i";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%+i Word %+3.i Word %+5.7i Word %+10i Word %+.i";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%#i Word %#3i Word %#5.7i Word %#.7i Word %#.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%0d Word %06i Word %05.7i Word %0.7i Word %0.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%*i Word %-*i Word %*.*i Word %.*i";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
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

START_TEST(sprintf_16_signed_i) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "%i";
  int val = 12;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_signed_i) {
  char str1[400];
  char str2[400];
  char *str3 = "%- i Word %- 15i Word %- 15i Word %- i";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_signed_i(void) {
  Suite *s = suite_create("\033[47;30msprintf_signed_i\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_signed_i);
  tcase_add_test(tc, sprintf_2_signed_i);
  tcase_add_test(tc, sprintf_3_signed_i);
  tcase_add_test(tc, sprintf_4_signed_i);
  tcase_add_test(tc, sprintf_5_signed_i);
  tcase_add_test(tc, sprintf_6_signed_i);
  tcase_add_test(tc, sprintf_7_signed_i);
  tcase_add_test(tc, sprintf_8_signed_i);
  tcase_add_test(tc, sprintf_9_signed_i);
  tcase_add_test(tc, sprintf_10_signed_i);
  tcase_add_test(tc, sprintf_11_signed_i);
  tcase_add_test(tc, sprintf_12_signed_i);
  tcase_add_test(tc, sprintf_13_signed_i);
  tcase_add_test(tc, sprintf_14_signed_i);
  tcase_add_test(tc, sprintf_15_signed_i);
  tcase_add_test(tc, sprintf_16_signed_i);
  tcase_add_test(tc, sprintf_17_signed_i);

  suite_add_tcase(s, tc);
  return s;
}
