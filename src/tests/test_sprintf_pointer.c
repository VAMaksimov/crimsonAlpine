#include "test_me.h"

START_TEST(sprintf_1_pointer) {
  char str1[400] = "";
  char str2[400] = "";
  char* str3 = "Word %p Word";
  char* val = "0p32";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%p Word %p Word %p";
  char* val = "0p7a4";
  char* val2 = "0p91ba123f";
  char* val3 = "0p3123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%p Word %p Word %p";
  char* val = "0p3015";
  char* val2 = "0p712";
  char* val3 = "0p99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%p Word %p Word %p Word %p";
  long int* val = (void*)3088675747373646;
  long long int* val2 = (void*)33030030303;
  unsigned short int* val3 = (void*)22600;
  unsigned char* val4 = (void*)120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%3p Word %5p Word %12p";
  char* val = "3015";
  char* val2 = "01234";
  char* val3 = "99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%6.5p Word %.23p Word %3.p Word %.p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "38";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%-10.5p Word %-.4p Word %-16p Word %-.5p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%0p Word %0.p Word %0.0p Word %0p Word %.p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  char* val5 = "0123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%+p Word %+3.p Word %+5.7p Word %+10p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%p Word %3.p Word %5.7p Word %10p %#p %-p %+p %.p % .p";
  char* val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "% p Word % 3.p Word % 5.7p Word % 10p Word %.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "23";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%+p Word %+3.p Word %+5.7p Word %+10p Word %+.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "3261";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%#p Word %#3p Word %#5.7p Word %#.7p Word %#.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%0p Word %06p Word %05.7p Word %0.7p Word %0.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_pointer) {
  char str1[400];
  char str2[400];
  char* str3 = "%*p Word %-*p Word %*.*p Word %.*p Word %.*p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "9193112312312";
  char* val4 = "32311";
  char* val5 = "ABO baabo";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int ast6 = 18;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                           ast5, val4, ast6, val5),
                   s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4,
                               val3, ast5, val4, ast6, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* test_sprintf_pointer(void) {
  Suite* s = suite_create("\033[47msprintf_pointer\033[0m");
  TCase* tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_pointer);
  tcase_add_test(tc, sprintf_2_pointer);
  tcase_add_test(tc, sprintf_3_pointer);
  tcase_add_test(tc, sprintf_4_pointer);
  tcase_add_test(tc, sprintf_5_pointer);
  tcase_add_test(tc, sprintf_6_pointer);
  tcase_add_test(tc, sprintf_7_pointer);
  tcase_add_test(tc, sprintf_8_pointer);
  tcase_add_test(tc, sprintf_9_pointer);
  tcase_add_test(tc, sprintf_10_pointer);
  tcase_add_test(tc, sprintf_11_pointer);
  tcase_add_test(tc, sprintf_12_pointer);
  tcase_add_test(tc, sprintf_13_pointer);
  tcase_add_test(tc, sprintf_14_pointer);
  tcase_add_test(tc, sprintf_15_pointer);

  suite_add_tcase(s, tc);
  return s;
}
