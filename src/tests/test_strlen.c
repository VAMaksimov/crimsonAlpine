#include "test_me.h"

void assert_strlen(const char *str) {
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}

START_TEST(strlen_basic_string) {
  assert_strlen("Hello, world!");
}
END_TEST

START_TEST(strlen_long_string_with_numbers_and_symbols) {
  assert_strlen(
      "213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 "
      "21");
}
END_TEST

START_TEST(strlen_repeated_string) {
  assert_strlen("Hello, world!");
}
END_TEST

START_TEST(strlen_single_null_character) {
  assert_strlen("\0");
}
END_TEST

START_TEST(strlen_long_string_with_exclamation_marks) {
  assert_strlen(
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!");
}
END_TEST

START_TEST(strlen_empty_string) {
  assert_strlen("");
}
END_TEST

START_TEST(strlen_alphabet_and_numbers) {
  assert_strlen("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
}
END_TEST

START_TEST(strlen_string_with_spaces) {
  assert_strlen("          00000000           ......  ");
}
END_TEST

START_TEST(strlen_newline_characters) {
  assert_strlen("\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n");
}
END_TEST

START_TEST(strlen_null_characters_and_newline) {
  assert_strlen("\0\0\0\0\n");
}
END_TEST

START_TEST(strlen_empty_string_2) {
  assert_strlen("");
}
END_TEST

START_TEST(strlen_tab_characters) {
  assert_strlen("\t\t");
}
END_TEST

START_TEST(strlen_null_terminated_string) {
  assert_strlen("\0test");
}
END_TEST

START_TEST(strlen_string_with_internal_null) {
  assert_strlen("wtf \0 wtf");
}
END_TEST

START_TEST(strlen_single_character) {
  assert_strlen("a");  
}
END_TEST

START_TEST(strlen_empty_with_null_char) {
  assert_strlen("\0\0\0");  
}
END_TEST

START_TEST(strlen_maximum_length_string) {
  char str[10000];
  memset(str, 'a', 9999);
  str[9999] = '\0';  
  assert_strlen(str);  
}
END_TEST

Suite *test_strlen(void) {
  Suite *s = suite_create("s21_string_test");
  TCase *tc = tcase_create("strlen_test_case");

  tcase_add_test(tc, strlen_basic_string);
  tcase_add_test(tc, strlen_long_string_with_numbers_and_symbols);
  tcase_add_test(tc, strlen_repeated_string);
  tcase_add_test(tc, strlen_single_null_character);
  tcase_add_test(tc, strlen_long_string_with_exclamation_marks);
  tcase_add_test(tc, strlen_empty_string);
  tcase_add_test(tc, strlen_alphabet_and_numbers);
  tcase_add_test(tc, strlen_string_with_spaces);
  tcase_add_test(tc, strlen_newline_characters);
  tcase_add_test(tc, strlen_null_characters_and_newline);
  tcase_add_test(tc, strlen_empty_string_2);
  tcase_add_test(tc, strlen_tab_characters);
  tcase_add_test(tc, strlen_null_terminated_string);
  tcase_add_test(tc, strlen_string_with_internal_null);
  tcase_add_test(tc, strlen_single_character);
  tcase_add_test(tc, strlen_empty_with_null_char);
  tcase_add_test(tc, strlen_maximum_length_string);

  suite_add_tcase(s, tc);
  return s;
}
