#include "test_me.h"

START_TEST(sprintf_1_hex) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "Word %x Word";
  int val = 0x32;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%x Word %x Word %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%x Word %x Word %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%lx Word %lx Word %hx Word %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%3x Word %5x Word %10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.5x Word %.23x Word %3.x Word %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%-10.5x Word %-.8x Word %-7x Word %-.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%0x Word %0.x Word %0.0x Word %0x Word %.x";
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

START_TEST(sprintf_9_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%+x Word %+3.x Word %+5.7x Word %+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%x Word %3.x Word %5.7x Word %10x %#x %-x %+x %.x % .x";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "% x Word % 3.x Word % 5.7x Word % 10x Word %.x";
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

START_TEST(sprintf_12_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%+x Word %+3.x Word %+5.7x Word %+10x Word %+.x";
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

START_TEST(sprintf_13_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%#x Word %#3x Word %#5.7x Word %#.7x Word %#.x";
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

START_TEST(sprintf_14_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%0x Word %06x Word %05.7x Word %0.7x Word %0.x";
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

START_TEST(sprintf_15_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%*x Word %-*x Word %*.*x Word %.*x";
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

START_TEST(sprintf_16_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "%- x Word %- 15x Word %- 15x Word %- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_hex) {
  char str1[400];
  char str2[400];
  char *str3 = "Word %lx";
  long int val = ULONG_MAX;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_hex(void) {
  Suite *s = suite_create("\033[47;30msprintf_hex1\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_hex);
  tcase_add_test(tc, sprintf_2_hex);
  tcase_add_test(tc, sprintf_3_hex);
  tcase_add_test(tc, sprintf_4_hex);
  tcase_add_test(tc, sprintf_5_hex);
  tcase_add_test(tc, sprintf_6_hex);
  tcase_add_test(tc, sprintf_7_hex);
  tcase_add_test(tc, sprintf_8_hex);
  tcase_add_test(tc, sprintf_9_hex);
  tcase_add_test(tc, sprintf_10_hex);
  tcase_add_test(tc, sprintf_11_hex);
  tcase_add_test(tc, sprintf_12_hex);
  tcase_add_test(tc, sprintf_13_hex);
  tcase_add_test(tc, sprintf_14_hex);
  tcase_add_test(tc, sprintf_15_hex);
  tcase_add_test(tc, sprintf_16_hex);
  tcase_add_test(tc, sprintf_17_hex);

  suite_add_tcase(s, tc);
  return s;
}
