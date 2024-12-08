#include "test_me.h"

START_TEST(sprintf_1_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%f Word %.f Word %4f Word %4.f Word %5.9f!";
  double num = 76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%f Word %.f Word %3f Word %4.f Word %5.9f!";
  double num = -76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf!";
  long double num_long = -76.756589;
  sprintf(str1, str3, num_long, num_long);
  s21_sprintf(str2, str3, num_long, num_long);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.9f\n%20.9f\n%-20.5f!";
  double num = -76.756589;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf\n%+-#Lf\n%+#.Lf\n%-#.Lf!";
  long double num = 76.756589;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %5f\nWord: %6.1f\nWord: %8.2f!";
  double num = 76.756589;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %10.5f\nWord: %12.4f!";
  double num = 76.756589;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %15.1f\nWord: %16.2f\nWord: %18.3f!";
  double num = -7648938790.756589;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %10.4f\nWord: %25.5f!";
  double num = -7648938790.756589;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+15.f\nWord: %+#16.f\nWord: %+#18.0f!";
  double num = 7648938790.756589;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+ 18.0f\nWord: %+10.f\nWord: %+25.f!";
  double num = 7648938790.756589;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-26.1f\nWord: %-18.0f\nWord: %#-10.f!";
  double num = 7648938790.756589;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-#15.f\nWord: %-+25.f!";
  double num = 7648938790.756589;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-15.4f!\nWord: %-26.1f!\nWord: %-18.0f!";
  double num = -365289.3462865487;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %#-10.9f!\nWord: %-+25.9f!";
  double num = -365289.3462865487;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %15.9f!\nWord: %26.9f!";
  double num = -365289.34628654873789362746834;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %18.7f!\nWord: %10.9f!\nWord: %25.9f!";
  double num = -365289.34628654873789362746834;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %15.9f!\nWord: %26.9f!";
  double num = 365289.34628654873789362746834;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %18.7f!\nWord: %10.9f!";
  double num = 365289.34628654873789362746834;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %- 23.9f!\nWord: %+ 25.9f!";
  double num = 365289.34628654873789362746834;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: % 15f!\nWord: % -26f!\nWord: %- 18f!";
  double num = -365789.34;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+- 14f!\nWord: %+ 10f!\nWord: % +25f!";
  double num = -365789.34;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: % 14f!\nWord: % -27f!\nWord: %- 19f!";
  double num = 365789.34;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+- 16f!\nWord: %+ 44f!\nWord: % +35f!";
  double num = 365789.34;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %26Lf!\ntest: %18Lf!\ntest: %60Lf!";
  long double num = -37593496.34;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15Lf!test: %100Lf!";
  long double num = -37593496.34;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_f) {
  char str1[4000];
  char str2[4000];
  char *str3 = "Word: %020f!\nWord: %-020f!\nWord: %+025f!";
  double num = 837564.4753366;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_f) {
  char str1[4000];
  char str2[4000];
  char *str3 = "Word: %-+ 025.5f!\nWord: %- 020.4f\nWord: %+ 016.6f!";
  double num = 837564.4753366;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_f) {
  char str1[4000];
  char str2[4000];
  char *str3 = "Word: %015f!\nWord: %-026f!\nWord: %+018f!";
  double num = -947.6785643;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_f) {
  char str1[4000];
  char str2[4000];
  char *str3 = "Word: %+- 010.2f!\nWord: %- 025.7f\nWord: %+- 18.4f!";
  double num = -947.6785643;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: % 15.1Lf!\nWord: % -26.9Lf!\nWord: %- 30.9Lf!";
  long double num = 278.723786;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+ 50.9Lf!\nWord: % +40.9Lf!";
  long double num = 278.723786;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: % 15.1Lf!\nWord: % -26.9Lf!\nWord: %- 30.8Lf!";
  long double num = -2358.367776967;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+ 50.9Lf!\nWord: % +40.9Lf!";
  long double num = -2358.367776967;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.1Lf!\nWord: %.2Lf!\nWord: %.3Lf!";
  long double num = -9999.99999;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.9Lf!\nWord: %.6Lf!\nWord: %.Lf!";
  long double num = -9999.99999;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.1Lf!\nWord: %.2Lf!\nWord: %.3Lf!";
  long double num = 000000000000000.00000000000;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.6Lf!\nWord: %.Lf\nWord: %+ 0Lf!!";
  long double num = 000000000000000.00000000000;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.1Lf!\nWord: %.2Lf!\nWord: %.3Lf!";
  long double num = -6393753.6433;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+ 0Lf!\nWord: %.6Lf!\nWord: %.7Lf!";
  long double num = -6393753.6433;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.1Lf!\nWord: %.2Lf!\nWord: %.3Lf!";
  long double num = -236310753.6495633;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_46_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -93257889988.;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_50_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %25.5Lf!\nWord: %Lf!\nWord: %-50Lf!";
  long double num = -932589988.;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_52_f) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-+.1Lf!\nWord: %- .2Lf!\nWord: %-0.3Lf!";
  long double num = -0.999999;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_54_f) {
  char str1[400];
  char str2[400];
  char *str3 = "aboba% 10.9f sussusbaka";
  double num = 0.235300;
  sprintf(str1, str3, num);
  s21_sprintf(str2, str3, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_f(void) {
  Suite *s = suite_create("\033[47;30msprintf_f\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_f);
  tcase_add_test(tc, sprintf_2_f);
  tcase_add_test(tc, sprintf_3_f);
  tcase_add_test(tc, sprintf_4_f);
  tcase_add_test(tc, sprintf_5_f);
  tcase_add_test(tc, sprintf_6_f);
  tcase_add_test(tc, sprintf_7_f);
  tcase_add_test(tc, sprintf_8_f);
  tcase_add_test(tc, sprintf_9_f);
  tcase_add_test(tc, sprintf_10_f);
  tcase_add_test(tc, sprintf_11_f);
  tcase_add_test(tc, sprintf_12_f);
  tcase_add_test(tc, sprintf_13_f);
  tcase_add_test(tc, sprintf_14_f);
  tcase_add_test(tc, sprintf_15_f);
  tcase_add_test(tc, sprintf_16_f);
  tcase_add_test(tc, sprintf_17_f);
  tcase_add_test(tc, sprintf_18_f);
  tcase_add_test(tc, sprintf_19_f);
  tcase_add_test(tc, sprintf_20_f);
  tcase_add_test(tc, sprintf_21_f);
  tcase_add_test(tc, sprintf_22_f);
  tcase_add_test(tc, sprintf_23_f);
  tcase_add_test(tc, sprintf_24_f);
  tcase_add_test(tc, sprintf_25_f);
  tcase_add_test(tc, sprintf_26_f);
  tcase_add_test(tc, sprintf_30_f);
  tcase_add_test(tc, sprintf_31_f);
  tcase_add_test(tc, sprintf_32_f);
  tcase_add_test(tc, sprintf_33_f);
  tcase_add_test(tc, sprintf_34_f);
  tcase_add_test(tc, sprintf_35_f);
  tcase_add_test(tc, sprintf_36_f);
  tcase_add_test(tc, sprintf_37_f);
  tcase_add_test(tc, sprintf_38_f);
  tcase_add_test(tc, sprintf_39_f);
  tcase_add_test(tc, sprintf_40_f);
  tcase_add_test(tc, sprintf_41_f);
  tcase_add_test(tc, sprintf_42_f);
  tcase_add_test(tc, sprintf_43_f);
  tcase_add_test(tc, sprintf_44_f);
  tcase_add_test(tc, sprintf_46_f);
  tcase_add_test(tc, sprintf_50_f);
  tcase_add_test(tc, sprintf_52_f);
  tcase_add_test(tc, sprintf_54_f);

  suite_add_tcase(s, tc);
  return s;
}
