#include "test_me.h"

START_TEST(sprintf_1_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%g Word %.g Word %4g Word %4.g Word %5.10g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%g Word %.g Word %4g Word %4.g Word %5.10g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%25.18g Word\n%.6g Word\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%.2g Word\n%.3g Word\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%g Word %.g Word %4g Word %4.g Word %#5.10g!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%g Word %.g Word %4g Word %4.g Word %#5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%g Word %.g Word %4g Word %4.g Word %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%g Word %.0g Word %4.2g Word %4.g Word %5.10g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %15.1g\nWord: %16.2g\nWord: %18.3g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %10.4g\nWord: %25.5g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-#15.g\nWord: %-26.1g\nWord: %-18.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %#-10.g\nWord: %-+25.g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%6g Word %.2g Word %4.5g Word %4.3g Word %5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%g Word %.g Word %4g Word %4.g Word %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10g\n%20.15g\n%-20.5g!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg\n%+-#Lg\n%+#.Lg\n%-#.Lg!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %15.13g!\nWord: %26.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %18.7g!\nWord: %10.15g!\nWord: %25.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %15.13g!\nWord: %26.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %18.7g!\nWord: %10.15g!\nWord: %25.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %020g!\nWord: %-020g!\nWord: %+025g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-+ 025.5g!\nWord: %- 020.4g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %020g!\nWord: %-020g!\nWord: %+025g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-+ 025.5g!\nWord: %- 020.4g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %015g!\nWord: %-026g!\nWord: %+018g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+- 010.2g!\nWord: %- 025.7g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: % 15.1Lg!\nWord: % -26.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %- 30.15Lg!\nWord: %+ 50.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: % +40.15Lg\nWord: % +-25.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: % 15.1Lg!\nWord: % -26.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %- 30.13Lg!\nWord: %+ 50.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: % +40.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.1Lg!\nWord: %.2Lg!\nWord: %.3Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.6Lg!\nWord: %.Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.g!\nWord: %.2g!\nWord: %.3g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.10g!\nWord: %.6g!\nWord: %.g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-20.13g!\nWord: %-25.7g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %-.15g!\nWord: %-16g!\nWord: %- 13.5g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+20.13g!\nWord: %+25.7g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %+.15g!\nWord: %+16g!\nWord: %+ 13.5g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.Lg!\nWord: %.2Lg!\nWord: %.3Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %.12Lg!\nWord: %.6Lg!\nWord: %.9Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %Lg!\n";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_g) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %Lg!\nWord: %Lg!\n";
  long double num = NAN;
  long double num1 = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_g(void) {
  Suite *s = suite_create("\033[47msprintf_g\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_g);
  tcase_add_test(tc, sprintf_2_g);
  tcase_add_test(tc, sprintf_3_g);
  tcase_add_test(tc, sprintf_4_g);
  tcase_add_test(tc, sprintf_5_g);
  tcase_add_test(tc, sprintf_6_g);
  tcase_add_test(tc, sprintf_7_g);
  tcase_add_test(tc, sprintf_8_g);
  tcase_add_test(tc, sprintf_9_g);
  tcase_add_test(tc, sprintf_10_g);
  tcase_add_test(tc, sprintf_11_g);
  tcase_add_test(tc, sprintf_12_g);
  tcase_add_test(tc, sprintf_13_g);
  tcase_add_test(tc, sprintf_14_g);
  tcase_add_test(tc, sprintf_15_g);
  tcase_add_test(tc, sprintf_16_g);
  tcase_add_test(tc, sprintf_17_g);
  tcase_add_test(tc, sprintf_18_g);
  tcase_add_test(tc, sprintf_19_g);
  tcase_add_test(tc, sprintf_20_g);
  tcase_add_test(tc, sprintf_21_g);
  tcase_add_test(tc, sprintf_22_g);
  tcase_add_test(tc, sprintf_23_g);
  tcase_add_test(tc, sprintf_24_g);
  tcase_add_test(tc, sprintf_25_g);
  tcase_add_test(tc, sprintf_26_g);
  tcase_add_test(tc, sprintf_27_g);
  tcase_add_test(tc, sprintf_28_g);
  tcase_add_test(tc, sprintf_29_g);
  tcase_add_test(tc, sprintf_30_g);
  tcase_add_test(tc, sprintf_31_g);
  tcase_add_test(tc, sprintf_32_g);
  tcase_add_test(tc, sprintf_33_g);
  tcase_add_test(tc, sprintf_34_g);
  tcase_add_test(tc, sprintf_35_g);
  tcase_add_test(tc, sprintf_36_g);
  tcase_add_test(tc, sprintf_37_g);
  tcase_add_test(tc, sprintf_38_g);
  tcase_add_test(tc, sprintf_39_g);
  tcase_add_test(tc, sprintf_40_g);
  tcase_add_test(tc, sprintf_41_g);
  tcase_add_test(tc, sprintf_42_g);
  tcase_add_test(tc, sprintf_43_g);
  tcase_add_test(tc, sprintf_44_g);
  tcase_add_test(tc, sprintf_45_g);

  suite_add_tcase(s, tc);
  return s;
}
