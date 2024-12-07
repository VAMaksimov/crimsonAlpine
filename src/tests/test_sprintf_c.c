#include "test_me.h"

START_TEST(sprintf_1_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%c Word %c Word %c Word %c Word %c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%c Word %c Word %c Word %c Word %c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%c Word %c Word %c Word %c Word %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%c Word %c Word %c Word %c Word %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%c Word %c Word %c Word %c Word %c";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%05c Word % 5c Word %lc Word";
  int a = 70;
  unsigned long int b = 70;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%-010c Word % -10c Word %-lc";
  int a = 74;
  unsigned long int b = 74;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%+010.5c Word % +10.5c Word %-10lc Word %-10lc Word %+10lc";
  char a = 92;
  unsigned long int b = 92;
  unsigned long int c = 92;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.4c Word %-6.4c Word %4.10lc Word %-4.10lc Word %-0lc";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%6.4c Word %-6.4c Word %4.10lc Word %-4.10lc Word %-0lc";
  int a = -10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%#c Word %#c Word %#c Word %#c Word %#c";
  ck_assert_int_eq(sprintf(str1, str3, ' ', 'n', '5', '%', '\\'),
                   s21_sprintf(str2, str3, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%c Word %c Word %c Word %c Word %c";
  ck_assert_int_eq(sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c'),
                   s21_sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%c Word %c Word %c Word %c Word %c";
  ck_assert_int_eq(sprintf(str1, str3, 'b', '4', '#', '@', '\0'),
                   s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%c Word %c Word %c Word %c Word %c";
  ck_assert_int_eq(sprintf(str1, str3, 'Y', 'G', 123, '\0', 'J'),
                   s21_sprintf(str2, str3, 'Y', 'G', 123, '\0', 'J'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Word %-7c Word %-50c Word % 54c Word %0188c";
  int a = 112;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Word % -.7c Word %- 050c Word %- 54c Word %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Word %-90c Word %080c Word %-065c Word %- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Word %-90c Word %080c Word %-065c Word %- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_c) {
  char str1[400];
  char str2[400];  //%lc Word %llc Word %hc Word %hhc
  char *str3 = "%c Word %lc Word %hc";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

/*START_TEST(sprintf_20_c) {
  char str1[400];
  char str2[400];
  char *str3 = "TEST %lc right now\n";
  int a = 266;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
  // sprintf(str1, str3, a);
  //                  s21_sprintf(str2, str3, a);
  // printf("SPRINT: %s", str1);
  // printf("S21_PRINT: %s", str2);
}
END_TEST

START_TEST(sprintf_21_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%lc This is the Word right now\n";
  int a = 1156;
  ck_assert_int_eq(sprintf(str1, str3, a),
                   s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
  printf("SPRINT: %s", str1);
  printf("S21_PRINT: %s", str2);
}
END_TEST */

Suite *test_sprintf_c(void) {
  Suite *s = suite_create("\033[47;30msprintf_c\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_c);
  tcase_add_test(tc, sprintf_2_c);
  tcase_add_test(tc, sprintf_3_c);
  tcase_add_test(tc, sprintf_4_c);
  tcase_add_test(tc, sprintf_5_c);
  tcase_add_test(tc, sprintf_6_c);
  tcase_add_test(tc, sprintf_7_c);
  tcase_add_test(tc, sprintf_8_c);
  tcase_add_test(tc, sprintf_9_c);
  tcase_add_test(tc, sprintf_10_c);
  tcase_add_test(tc, sprintf_11_c);
  tcase_add_test(tc, sprintf_12_c);
  tcase_add_test(tc, sprintf_13_c);
  tcase_add_test(tc, sprintf_14_c);
  tcase_add_test(tc, sprintf_15_c);
  tcase_add_test(tc, sprintf_16_c);
  tcase_add_test(tc, sprintf_17_c);
  tcase_add_test(tc, sprintf_18_c);
  tcase_add_test(tc, sprintf_19_c);
  // tcase_add_test(tc, sprintf_20_c);
  // tcase_add_test(tc, sprintf_21_c);

  suite_add_tcase(s, tc);
  return s;
}
