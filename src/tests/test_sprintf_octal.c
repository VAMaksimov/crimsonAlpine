#include "test_me.h"

START_TEST(sprintf_1_octal) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "Word %o Word";
  int val = 012;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%o Word %o Word %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%o Word %o Word %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%lo Word %lo Word %ho Word %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%3o Word %5o Word %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.5o Word %.23o Word %3.o Word %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%-10.5o Word %-.8o Word %-7o Word %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%0o Word %0.o Word %0.0o Word %0o Word %.o";
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

START_TEST(sprintf_9_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%+o Word %+3.o Word %+5.7o Word %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%o Word %3.o Word %5.7o Word %10o %#o %-o %+o %.o % .o";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "% o Word % 3.o Word % 5.7o Word % 10o Word %.o";
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

START_TEST(sprintf_12_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%+o Word %+3.o Word %+5.7o Word %+10o Word %+.o";
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

START_TEST(sprintf_13_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%#o Word %#3o Word %#5.7o Word %#.7o Word %#.o";
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

START_TEST(sprintf_14_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%0o Word %06o Word %05.7o Word %0.7o Word %0.o";
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

START_TEST(sprintf_15_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%*o Word %-*o Word %*.*o Word %.*o";
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

START_TEST(sprintf_16_octal) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "%o";
  int val = 012;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "%- o Word %- 15o Word %- 15o Word %- o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_octal) {
  char str1[400];
  char str2[400];
  char *str3 = "Word %lo";
  long int val = ULONG_MAX;
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_octal(void) {
  Suite *s = suite_create("\033[47;30msprintf_octal\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_octal);
  tcase_add_test(tc, sprintf_2_octal);
  tcase_add_test(tc, sprintf_3_octal);
  tcase_add_test(tc, sprintf_4_octal);
  tcase_add_test(tc, sprintf_5_octal);
  tcase_add_test(tc, sprintf_6_octal);
  tcase_add_test(tc, sprintf_7_octal);
  tcase_add_test(tc, sprintf_8_octal);
  tcase_add_test(tc, sprintf_9_octal);
  tcase_add_test(tc, sprintf_10_octal);
  tcase_add_test(tc, sprintf_11_octal);
  tcase_add_test(tc, sprintf_12_octal);
  tcase_add_test(tc, sprintf_13_octal);
  tcase_add_test(tc, sprintf_14_octal);
  tcase_add_test(tc, sprintf_15_octal);
  tcase_add_test(tc, sprintf_16_octal);
  tcase_add_test(tc, sprintf_17_octal);
  tcase_add_test(tc, sprintf_18_octal);

  suite_add_tcase(s, tc);
  return s;
}
