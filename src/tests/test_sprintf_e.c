#include "test_me.h"

START_TEST(sprintf_1_e) {
  char str1[400];
  char str2[400];
  char *str3 = "%e Word %5e Word %5.e";
  double num = -764231539.;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_e) {
  char str1[400];
  char str2[400];
  char *str3 = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
  double num = -764236539.;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_e) {
  char str1[400];
  char str2[400];
  char *str3 = "%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
  double num = -665695352471359.;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_e) {
  char str1[400];
  char str2[400];
  char *str3 = "first word: %020e\nSecond Word: %020.e!";
  double num = -5921563214775967.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Third Word: %010e\nFourth Word: %010.e!";
  double num = -5921563224775967.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Fifth Word: %0.0e!";
  double num = -5921563224775967.;
  sprintf(str1, str3, num);
  s21_sprintf(str2, str3, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_e) {
  char str1[400];
  char str2[400];
  char *str3 = "New Word: %020e\nSecond Word: %020.e!";
  double num =
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Third Word: %010e\nFourth Word: %010.e\nFifth Word: %0.0e!";
  double num =
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_e) {
  char str1[400];
  char str2[400];
  char *str3 = "New Word: %020e\nSecond Word: %020.5e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Third Word: %020.4e\nFourth Word: %020.3e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Fifth Word: %020.2e\nSixth Word: %020.1e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Seventh Word: %020.e\n Eighth Word: %020.0e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_e) {
  char str1[400];
  char str2[400];
  char *str3 = "New Word: % 20e\nSecond Word: % 20.5e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Third Word: % 20.4e\nFourth Word: % 20.3e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Fifth Word: % 20.2e\nSixth Word: % 20.1e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Seventh Word: % 20.e\n Eighth Word: % 20.0e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_e) {
  char str1[400];
  char str2[400];
  char *str3 = "New Word: % 31e\nSecond Word: % 30.5e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Third Word: % 33.4e\nFourth Word: % 35.3e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Fifth Word: % 36.2e\nSixth Word: % 45.1e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Seventh Word: % 64.e\n Eighth Word: % 80.0e!";
  double num = -592156322477596.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_e) {
  char str1[400];
  char str2[400];
  double num1 = -89435776876.;
  double num2 = -894357768.76;
  char *str3 = "New Word: %e\nSecond Word: %e!";
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_e) {
  char str1[400];
  char str2[400];
  double num3 = -89435.776876;
  double num4 = -0.89435776876;
  char *str3 = "Third Word: %e\nFourth Word: %e\n!";
  sprintf(str1, str3, num3, num4);
  s21_sprintf(str2, str3, num3, num4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_e) {
  char str1[400];
  char str2[400];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  char *str3 = "New Word: %e\nSecond Word: %e!";
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_e) {
  char str1[400];
  char str2[400];
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "Third Word: %e\nFourth Word: %e\n!";
  sprintf(str1, str3, num3, num4);
  s21_sprintf(str2, str3, num3, num4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_e) {
  char str1[400];
  char str2[400];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "Word: %.E!\nWord: %#E!\nWord: %#.E!\nWord: %0.E!\n";
  sprintf(str1, str3, num1, num2, num3, num4);
  s21_sprintf(str2, str3, num1, num2, num3, num4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_e) {
  char str1[400];
  char str2[400];
  double num1 = -.3529373967;
  double num2 = -.0003529373967;
  double num3 = -0.00000003529373967;
  char *str3 = "Word: % 013.E\nWord: %#4.9E\nWord: %016.2E!";
  sprintf(str1, str3, num1, num2, num3);
  s21_sprintf(str2, str3, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_e) {
  char str1[400];
  char str2[400];
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "Word: %20.E\nWord: %-20.E\n!";
  sprintf(str1, str3, num4, num1);
  s21_sprintf(str2, str3, num4, num1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_e) {
  char str1[400];
  char str2[400];
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "Word: % 30.1E\nWord: % 30.E\nWord: %030.0E!";
  sprintf(str1, str3, num1, num2, num3);
  s21_sprintf(str2, str3, num1, num2, num3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_e) {
  char str1[400];
  char str2[400];
  double num1 = .3529373967;
  double num4 = 0000000000000.3529373967;
  char *str3 = "Word: %066.E\nWord: %-20.E\n!";
  sprintf(str1, str3, num4, num1);
  s21_sprintf(str2, str3, num4, num1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_e) {
  char str1[400];
  char str2[400];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "Word: %- 17.1E\nWord: % -17.1E!";
  sprintf(str1, str3, num1, num1);
  s21_sprintf(str2, str3, num1, num1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_e) {
  char str1[400];
  char str2[400];
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "Word: %# 10.2E\nWord: % #10.0E\nWord: %010.E\n!";
  sprintf(str1, str3, num2, num2, num2);
  s21_sprintf(str2, str3, num2, num2, num2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_e) {
  char str1[400];
  char str2[400];
  double num1 = 1234567890000.0938217586;
  char *str3 = "Word: %- 67.1E\nWord: % -67.1E!";
  sprintf(str1, str3, num1, num1);
  s21_sprintf(str2, str3, num1, num1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_e) {
  char str1[4000];
  char str2[4000];
  double num2 = -.12345678900000938217586;
  char *str3 = "Word: %# 400.0E\nWord: % #400.0E\nWord: %0400.E\n!";
  sprintf(str1, str3, num2, num2, num2);
  s21_sprintf(str2, str3, num2, num2, num2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_e) {
  char str1[4000];
  char str2[4000];
  double num1 = 1234567890000.0938217586;
  double num2 = -.12345678900000938217586;
  char *str3 = "Word: % 070.10E\nWord: % -67.10E\n!";
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_e) {
  char str1[4000];
  char str2[4000];
  double num1 = -12345678900000938217586.;
  double num2 = .12345678900000938217586;
  char *str3 = "Word: % 070.10E\nWord: % -67.10E\n!";
  sprintf(str1, str3, num1, num2);
  s21_sprintf(str2, str3, num1, num2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_e) {
  char str1[400];
  char str2[400];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "Word: % 10.1E\nWord: %- 10.1E!";
  sprintf(str1, str3, num1, num1);
  s21_sprintf(str2, str3, num1, num1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_e) {
  char str1[400];
  char str2[400];
  double num2 = 53296575676899283.734747273752737878257;
  char *str3 = "Word: % -10.0E\nWord: %- 10.0E\nWord: % -10.E\n!";
  sprintf(str1, str3, num2, num2, num2);
  s21_sprintf(str2, str3, num2, num2, num2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_e) {
  char str1[400];
  char str2[400];
  double num1 = .000000005329657567689928373474727375273787825732159676631957;
  double num2 = 53296575676899283.73474727375273787825732159676631957;
  char *str3 = "Word: % 20E\nWord: %-20E\nWord: %+ 020.E\n!";
  sprintf(str1, str3, num1, num2, num1);
  s21_sprintf(str2, str3, num1, num2, num1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_e) {
  char str1[400];
  char str2[400];
  double num3 = 5329657567689928373474727375.273787825732159676631957;
  double num4 = 53296575676899283734747273752737878257.32159676631957;
  char *str3 = "Word: %#20.E\nWord: %- 20E!";
  sprintf(str1, str3, num3, num4);
  s21_sprintf(str2, str3, num3, num4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_e) {
  char str1[400];
  char str2[400];
  char *str3 = "%.e\n%.2e\n%.5E\n%.9E\n%.13E!";
  double num = -2599999999.;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_e) {
  char str1[400];
  char str2[400];
  char *str3 = "%.Le\n%.2Le\n%.5Le\n%.9Le\n%.13LE!";
  long double num = -2599999999.;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_e) {
  char str1[400];
  char str2[400];
  char *str3 = "%e\n%.e\n%.5e\n%.9e\n%.15E!";
  double num = 0;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %20Le!\nWord: %Le!\nWord: %-10Le!";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_e) {
  char str1[400];
  char str2[400];
  char *str3 = "Word: %060Le!\nWord: %.14Le!";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_e(void) {
  Suite *s = suite_create("\033[47;30msprintf_e\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_e);
  tcase_add_test(tc, sprintf_2_e);
  tcase_add_test(tc, sprintf_3_e);
  tcase_add_test(tc, sprintf_4_e);
  tcase_add_test(tc, sprintf_5_e);
  tcase_add_test(tc, sprintf_6_e);
  tcase_add_test(tc, sprintf_7_e);
  tcase_add_test(tc, sprintf_8_e);
  tcase_add_test(tc, sprintf_9_e);
  tcase_add_test(tc, sprintf_10_e);
  tcase_add_test(tc, sprintf_11_e);
  tcase_add_test(tc, sprintf_12_e);
  tcase_add_test(tc, sprintf_13_e);
  tcase_add_test(tc, sprintf_14_e);
  tcase_add_test(tc, sprintf_15_e);
  tcase_add_test(tc, sprintf_16_e);
  tcase_add_test(tc, sprintf_17_e);
  tcase_add_test(tc, sprintf_18_e);
  tcase_add_test(tc, sprintf_19_e);
  tcase_add_test(tc, sprintf_20_e);
  tcase_add_test(tc, sprintf_21_e);
  tcase_add_test(tc, sprintf_22_e);
  tcase_add_test(tc, sprintf_23_e);
  tcase_add_test(tc, sprintf_24_e);
  tcase_add_test(tc, sprintf_25_e);
  tcase_add_test(tc, sprintf_26_e);
  tcase_add_test(tc, sprintf_27_e);
  tcase_add_test(tc, sprintf_28_e);
  tcase_add_test(tc, sprintf_29_e);
  tcase_add_test(tc, sprintf_30_e);
  tcase_add_test(tc, sprintf_31_e);
  tcase_add_test(tc, sprintf_32_e);
  tcase_add_test(tc, sprintf_33_e);
  tcase_add_test(tc, sprintf_34_e);
  tcase_add_test(tc, sprintf_35_e);
  tcase_add_test(tc, sprintf_36_e);
  tcase_add_test(tc, sprintf_37_e);
  tcase_add_test(tc, sprintf_38_e);
  tcase_add_test(tc, sprintf_39_e);
  tcase_add_test(tc, sprintf_40_e);
  tcase_add_test(tc, sprintf_41_e);
  tcase_add_test(tc, sprintf_42_e);
  tcase_add_test(tc, sprintf_43_e);
  tcase_add_test(tc, sprintf_44_e);

  suite_add_tcase(s, tc);
  return s;
}
