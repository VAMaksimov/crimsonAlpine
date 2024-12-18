#include "test_me.h"

START_TEST(sprintf_1_signed) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "Word %d Word";
  int val = -12;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed) {
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

START_TEST(sprintf_3_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%d Word %d Word %d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%ld Word %ld Word %hd Word %hd";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%3d Word %5d Word %10d";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.5d Word %.23d Word %3.d Word %.d %.6d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -400;
  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%-10.5d Word %-.8d Word %-7d Word %-.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%0d Word %0.d Word %0.0d Word %0d Word %.d";
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

START_TEST(sprintf_9_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%+d Word %+3.d Word %+5.7d Word %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%d Word %3.d Word %5.7d Word %10d %#d %-d %+d %.d % .d";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "% d Word % 3.d Word % 5.7d Word % 10d Word %.d";
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

START_TEST(sprintf_12_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%+d Word %+3.d Word %+5.7d Word %+10d Word %+.d";
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

START_TEST(sprintf_13_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%#d Word %#3d Word %#5.7d Word %#.7d Word %#.d";
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

START_TEST(sprintf_14_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%0d Word %06d Word %05.7d Word %0.7d Word %0.d";
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

START_TEST(sprintf_15_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%*d Word %-*d Word %*.*d Word %.*d";
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

START_TEST(sprintf_16_signed) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "%d";
  int val = 12;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_signed) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = -75;
  sprintf(str1, "Hi %d %023d", val, val);
  s21_sprintf(str2, "Hi %d %023d", val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%ld Word %ld Word %hd Word %hd Word %d word %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  sprintf(str1, str3, val, val2, val3, val4, val5, val6);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_signed) {
  char str1[400];
  char str2[400];
  char *str3 = "%- d Word %- 15d Word %- 15d Word %- d";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_signed(void) {
  Suite *s = suite_create("\033[47;30msprintf_d\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_signed);
  tcase_add_test(tc, sprintf_2_signed);
  tcase_add_test(tc, sprintf_3_signed);
  tcase_add_test(tc, sprintf_4_signed);
  tcase_add_test(tc, sprintf_5_signed);
  tcase_add_test(tc, sprintf_6_signed);
  tcase_add_test(tc, sprintf_7_signed);
  tcase_add_test(tc, sprintf_8_signed);
  tcase_add_test(tc, sprintf_9_signed);
  tcase_add_test(tc, sprintf_10_signed);
  tcase_add_test(tc, sprintf_11_signed);
  tcase_add_test(tc, sprintf_12_signed);
  tcase_add_test(tc, sprintf_13_signed);
  tcase_add_test(tc, sprintf_14_signed);
  tcase_add_test(tc, sprintf_15_signed);
  tcase_add_test(tc, sprintf_16_signed);
  tcase_add_test(tc, sprintf_17_signed);
  tcase_add_test(tc, sprintf_18_signed);
  tcase_add_test(tc, sprintf_19_signed);

  suite_add_tcase(s, tc);
  return s;
}
