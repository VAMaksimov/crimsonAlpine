#include "test_me.h"

void assert_strcspn(const char *str1, const char *str2) {
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}

START_TEST(strcspn_multiple_repeated_substring) {
    assert_strcspn("Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!", "Hello, world!");
}
END_TEST

START_TEST(strcspn_full_match_substring) {
    assert_strcspn("Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!", "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!");
}
END_TEST

START_TEST(strcspn_single_character_matching) {
    assert_strcspn("v", "vendetta");
}
END_TEST

START_TEST(strcspn_empty_string_first) {
    assert_strcspn("", "Hello, world!");
}
END_TEST

START_TEST(strcspn_empty_set_second) {
    assert_strcspn("Hello, world!", "");
}
END_TEST

START_TEST(strcspn_first_character_match) {
    assert_strcspn("6", "67");
}
END_TEST

START_TEST(strcspn_full_match) {
    assert_strcspn("69917020", "69917020");
}
END_TEST

START_TEST(strcspn_repeated_full_match) {
    assert_strcspn("69917020", "69917020");
}
END_TEST

START_TEST(strcspn_partial_first_match) {
    assert_strcspn("699", "69917020");
}
END_TEST

START_TEST(strcspn_partial_second_match) {
    assert_strcspn("69917020", "699");
}
END_TEST

START_TEST(strcspn_both_empty_strings) {
    assert_strcspn("", "");
}
END_TEST

START_TEST(strcspn_partial_non_matching) {
    assert_strcspn("69917020", "6991702H");
}
END_TEST

START_TEST(strcspn_single_character_matching_exact) {
    assert_strcspn("a", "a"); 
}
END_TEST

START_TEST(strcspn_single_character_no_match) {
    assert_strcspn("b", "a"); 
}
END_TEST

START_TEST(strcspn_first_character_matches) {
    assert_strcspn("abc", "b"); 
}
END_TEST

START_TEST(strcspn_second_string_in_first) {
    assert_strcspn("abcdef", "def"); 
}
END_TEST

START_TEST(strcspn_repeated_characters) {
    assert_strcspn("aaaaa", "a"); 
}
END_TEST

START_TEST(strcspn_no_match_in_set) {
    assert_strcspn("aaaaa", "b"); 
}
END_TEST

START_TEST(strcspn_single_character_empty_set) {
    assert_strcspn("a", ""); 
}
END_TEST

Suite *test_strcspn(void) {
    Suite *s = suite_create("\033[45m-=S21_STRCSPN=-\033[0m");
    TCase *tc = tcase_create("strcspn_tc");

    tcase_add_test(tc, strcspn_multiple_repeated_substring);
    tcase_add_test(tc, strcspn_full_match_substring);
    tcase_add_test(tc, strcspn_single_character_matching);
    tcase_add_test(tc, strcspn_empty_string_first);
    tcase_add_test(tc, strcspn_empty_set_second);
    tcase_add_test(tc, strcspn_first_character_match);
    tcase_add_test(tc, strcspn_full_match);
    tcase_add_test(tc, strcspn_repeated_full_match);
    tcase_add_test(tc, strcspn_partial_first_match);
    tcase_add_test(tc, strcspn_partial_second_match);
    tcase_add_test(tc, strcspn_both_empty_strings);
    tcase_add_test(tc, strcspn_partial_non_matching);
    tcase_add_test(tc, strcspn_single_character_matching_exact);
    tcase_add_test(tc, strcspn_single_character_no_match);
    tcase_add_test(tc, strcspn_first_character_matches);
    tcase_add_test(tc, strcspn_second_string_in_first);
    tcase_add_test(tc, strcspn_repeated_characters);
    tcase_add_test(tc, strcspn_no_match_in_set);
    tcase_add_test(tc, strcspn_single_character_empty_set);

    suite_add_tcase(s, tc);
    return s;
}
