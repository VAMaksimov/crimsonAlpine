#include "test_me.h"

START_TEST(sprintf_1_string) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "Word %s Word";
  char *val = "Who I am?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%s Word %s Word %s";
  char *val = "I'm so glad";
  char *val2 = "Who opened the door?";
  char *val3 = "My room is tiny and dark";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%s Word %s Word %s";
  char *val = "Like and sub";
  char *val2 = "Great Chinese wall";
  char *val3 = "aboba";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes WCHAR FOR LATER
START_TEST(sprintf_4_string) {
  char str1[400];
  char str2[400];
  char *str3 = "Word %ls Word";
  wchar_t *val = L"3abo80";
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  // ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
  //                s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%3s Word %5s Word %10s";
  char *val = "WHO are you";
  char *val2 = "my followers";
  char *val3 = "matofatogentleman";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.5s Word %.23s Word %3.s Word %.s";
  char *val = "WHO are you";
  char *val2 = "hello guys";
  char *val3 = "MATOFATOGENTLEMAN";
  char *val4 = "And I'm feeling good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%-10.5s Word %-.8s Word %-7s Word %-.s";
  char *val = "WHO are you";
  char *val2 = "hello guys";
  char *val3 = "MATOFATOGENTLEMAN";
  char *val4 = "And I'm feeling good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%0s Word %0.s Word %0.0s Word %0s Word %.s";
  char *val = "WHO are you";
  char *val2 = "And I'm feeling good";
  char *val3 = "MATOFATOGENTLEMAN";
  char *val4 = "And I'm feeling good";
  char *val5 = "hello world";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%+s Word %+3.s Word %5.7s Word %10s";
  char *val = "WHO are you";
  char *val2 = "And I'm feeling good";
  char *val3 = "aboba sus";
  char *val4 = "AMOGUS sus";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%s Word %3.s Word %5.7s Word %10s %#s %-s %+s %.s % .s";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_string) {
  char str1[400];
  char str2[400];
  char *str3 = "% s Word % 3.s Word % 5.7s Word % 10s Word %.s";
  char *val = "WHO are you";
  char *val2 = "And I'm feeling good";
  char *val3 = "MATOFATOGENTLEMAN";
  char *val4 = "AMOGUS sus";
  char *val5 = "hello";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%+s Word %+3.s Word %+5.7s Word %+10s Word %+.s";
  char *val = "WHO are you";
  char *val2 = "And I'm feeling good";
  char *val3 = "MATOFATOGENTLEMAN";
  char *val4 = "AMOGUS sus";
  char *val5 = "hello";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%#s Word %#3s Word %#5.7s Word %#.7s Word %#.s";
  char *val = "WHO are you";
  char *val2 = "And I'm feeling good";
  char *val3 = "MATOFATOGENTLEMAN";
  char *val4 = "AMOGUS sus";
  char *val5 = "hello";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%0s Word %06s Word %05.7s Word %0.7s Word %0.s";
  char *val = "WHO are you";
  char *val2 = "idx";
  char *val3 = "MATOFATOGENTLEMAN";
  char *val4 = "I don't";
  char *val5 = "hello";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%*s Word %-*s Word %*.*s Word %.*s";
  char *val = "WHO are you";
  char *val2 = "And I'm feeling good";
  char *val3 = "MATOFATOGENTLEMAN";
  char *val4 = "AMOGUS sus";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_string) {
  char str1[400];
  char str2[400];
  char *str3 = "%s %s %s %% %d";
  char *val = "That is";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "nothing";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_string) {
  char str1[1024];
  char str2[1024];
  char *str3 =
      "%0.0s %1.0s %2.0s %3.0s %5.0s %6.0s %7.0s %0.3s %0.7s %3.2s %3.7s %7.3s";
  char *val = NULL;
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val, val,
              val);
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val, val, val,
          val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_string(void) {
  Suite *s = suite_create("\033[47;30msprintf_string\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_string);
  tcase_add_test(tc, sprintf_2_string);
  tcase_add_test(tc, sprintf_3_string);
  tcase_add_test(tc, sprintf_4_string);
  tcase_add_test(tc, sprintf_5_string);
  tcase_add_test(tc, sprintf_6_string);
  tcase_add_test(tc, sprintf_7_string);
  tcase_add_test(tc, sprintf_8_string);
  tcase_add_test(tc, sprintf_9_string);
  tcase_add_test(tc, sprintf_10_string);
  tcase_add_test(tc, sprintf_11_string);
  tcase_add_test(tc, sprintf_12_string);
  tcase_add_test(tc, sprintf_13_string);
  tcase_add_test(tc, sprintf_14_string);
  tcase_add_test(tc, sprintf_15_string);
  tcase_add_test(tc, sprintf_16_string);
  tcase_add_test(tc, sprintf_17_string);

  suite_add_tcase(s, tc);
  return s;
}
