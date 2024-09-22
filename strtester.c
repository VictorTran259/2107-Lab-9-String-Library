//Name: Victor Tran
//Date: 11/17/22
//Course: CIS_2107
//Homework Number: Lab 9 String Library
//In this assignment, you'll create your own library of string functions. You'll have the opportunity to practice manipulating
//strings and managing memory. Additionally, you'll learn the role of header and library files.
//You may not call functions in string.h but you can use other code in the Standard C Library.

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    //Test for all_letters
    printf("Testing all_letters\n");
    char *all_letters1 = "Hello World";
    char *all_letters2 = "He11o World";

    if(all_letters(all_letters1) == 1) {
        printf("All characters in \"Hello World\" are either uppercase or lowercase letters.\n");
    }
    else {
        printf("Not all characters in \"Hello World\" are either uppercase or lowercase letters.");
    }

    if(all_letters(all_letters2) == 1) {
        printf("All characters in \"He11o World\" are either uppercase or lowercase letters.\n");
    }
    else {
        printf("Not all characters in \"He11o World\" are either uppercase or lowercase letters.\n");
    }

    printf("\n");

    //Test for num_in_range
    printf("Testing num_in_range\n");
    char *num_in_range_s1 = "Yellow";
    char num_in_range_b = 'f';
    char num_in_range_t = 'm';

    printf("Number of characters in \"Yellow\" that are between f and m = %d\n", num_in_range(num_in_range_s1, num_in_range_b, num_in_range_t));

    printf("\n");

    //Test for diff
    printf("Testing diff\n");
    char *diff_s1 = "Book";
    char *diff_s2 = "Back";
    printf("Number of positions where \"Book\" and \"Back\" differ = %d\n", diff(diff_s1, diff_s2));

    printf("\n");

    //Test for shorten
    printf("Testing shorten\n");
    char shorten_s1[] = "Hello World";
    int new_len_1 = 5;
    char shorten_s2[] = "Hello World";
    int new_len_2 = 20;

    printf("Shortening \"Hello World\" to 5 characters...\n");
    shorten(shorten_s1, new_len_1);
    printf("Result: %s\n", shorten_s1);

    printf("Shortening \"Hello World\" to 20 characters...\n");
    shorten(shorten_s2, new_len_2);
    printf("Result: %s\n", shorten_s2);

    printf("\n");

    //Test for len_diff
    printf("Testing len_diff\n");
    char *len_diff_s1 = "Philadelphia";
    char *len_diff_s2 = "Hello";
    printf("Difference in length between \"Philadelphia\" and \"Hello\" = %d\n", len_diff(len_diff_s1, len_diff_s2));

    printf("\n");

    //Test for rm_left_space
    printf("Testing rm_left_space\n");
    char rm_left_space_s[] = "     Hello     ";
    printf("Removing white spaces from the beginning of \"     Hello     \"...\n");
    rm_left_space(rm_left_space_s);
    printf("Result: \"%s\"\n", rm_left_space_s);

    printf("\n");

    //Test for rm_right_space
    printf("Testing rm_right_space\n");
    char rm_right_space_s[] = "     Hello     ";
    printf("Removing white spaces from the end of \"     Hello     \"...\n");
    rm_right_space(rm_right_space_s);
    printf("Result: \"%s\"\n", rm_right_space_s);

    printf("\n");

    //Test for rm_space
    printf("Testing rm_space\n");
    char rm_space_s[] = "     Hello     ";
    printf("Removing white spaces from the beginning and end of \"     Hello     \"...\n");
    rm_space(rm_space_s);
    printf("Result: \"%s\"\n", rm_space_s);

    printf("\n");

    //Test for find
    printf("Testing find\n");
    char *find_h1 = "Hello";
    char *find_n1 = "lo";
    char *find_h2 = "Hello";
    char *find_n2 = "lp";
    if(find(find_h1, find_n1) == -1) {
        printf("\"lo\" was not found in \"Hello\"\n");
    }
    else {
        printf("\"lo\" was found in \"Hello\" at index %d\n", find(find_h1, find_n1));
    }

    if(find(find_h2, find_n2) == -1) {
        printf("\"lp\" was not found in \"Hello\"\n");
    }
    else {
        printf("\"lp\" was found in \"Hello\" at index %d\n", find(find_h2, find_n2));
    }

    printf("\n");

    //Test for ptr_to
    printf("Testing ptr_to\n");
    char *ptr_to_h1 = "Hello";
    char *ptr_to_n1 = "lo";
    char *ptr_to_h2 = "Hello";
    char *ptr_to_n2 = "lp";
    char *ptr_to_ptr1 = ptr_to(ptr_to_h1, ptr_to_n1);
    char *ptr_to_ptr2 = ptr_to(ptr_to_h2, ptr_to_n2);

    if(ptr_to_ptr1 == NULL) {
        printf("\"lo\" was not found in \"Hello\"\n");
    }
    else {
        printf("\"lo\" was found in \"Hello\". Pointer is at '%c'\n", *ptr_to_ptr1);
    }

    if(ptr_to_ptr2 == NULL) {
        printf("\"lp\" was not found in \"Hello\"\n");
    }
    else {
        printf("\"lp\" was found in \"Hello\". Pointer is at '%c'\n", *ptr_to_ptr2);
    }

    printf("\n");

    //Test for is_empty
    printf("Testing is_empty\n");
    char *is_empty_s1 = "";
    char *is_empty_s2 = "   ";
    char *is_empty_s3 = "Hello";
    if(is_empty(is_empty_s1) == 1) {
        printf("\"\" is empty.\n");
    }
    else {
        printf("\"\" is not empty.\n");
    }

    if(is_empty(is_empty_s2) == 1) {
        printf("\"   \" is empty.\n");
    }
    else {
        printf("\"   \" is not empty.\n");
    }

    if(is_empty(is_empty_s3) == 1) {
        printf("\"Hello\" is empty.\n");
    }
    else {
        printf("\"Hello\" is not empty.\n");
    }

    printf("\n");

    //Test for str_zip
    printf("Testing str_zip\n");
    char *str_zip_s1 = "Temple";
    char *str_zip_s2 = "Hello";
    char *str_zip_s3 = "Spongebob";
    char *str_zip_s4 = "Patrick";

    char *str_zip_string1 = str_zip(str_zip_s1, str_zip_s2);
    char *str_zip_string2 = str_zip(str_zip_s3, str_zip_s4);

    printf("Result of str_zip on \"Temple\" and \"Hello\": \"%s\"\n", str_zip_string1);
    printf("Result of str_zip on \"Spongebob\" and \"Patrick\": \"%s\"\n", str_zip_string2);

    printf("\n");

    //Test for capitalize
    printf("Testing capitalize\n");
    char capitalize_s1[] = "   hello world";
    char capitalize_s2[] = "hello   world";

    printf("Capitalizing the first letter of the words in \"   hello world\"...\n");
    capitalize(capitalize_s1);
    printf("Result: \"%s\"\n", capitalize_s1);

    printf("Capitalizing the first letter of the words in \"hello   world\"...\n");
    capitalize(capitalize_s2);
    printf("Result: \"%s\"\n", capitalize_s2);

    printf("\n");

    //Test for strcmp_ign_case
    printf("Testing strcmp_ign_case\n");
    char *strcmp_ign_case_s1 = "APPLESAUCE";
    char *strcmp_ign_case_s2 = "apple";
    char *strcmp_ign_case_s3 = "help";
    char *strcmp_ign_case_s4 = "helper";
    char *strcmp_ign_case_s5 = "HELicopter";
    char *strcmp_ign_case_s6 = "hello";
    char *strcmp_ign_case_s7 = "zebra";
    char *strcmp_ign_case_s8 = "lion";

    if(strcmp_ign_case(strcmp_ign_case_s1, strcmp_ign_case_s2) == 1) {
        printf("\"APPLESAUCE\" appears after \"apple\" in the dictionary.\n");
    }
    else if(strcmp_ign_case(strcmp_ign_case_s1, strcmp_ign_case_s2) == -1) {
        printf("\"APPLESAUCE\" appears before \"apple\" in the dictionary.\n");
    }
    else {
        printf("\"APPLESAUCE\" and \"apple\" are the same.\n");
    }

    if(strcmp_ign_case(strcmp_ign_case_s3, strcmp_ign_case_s4) == 1) {
        printf("\"help\" appears after \"helper\" in the dictionary.\n");
    }
    else if(strcmp_ign_case(strcmp_ign_case_s3, strcmp_ign_case_s4) == -1) {
        printf("\"help\" appears before \"helper\" in the dictionary.\n");
    }
    else {
        printf("\"help\" and \"helper\" are the same.\n");
    }

    if(strcmp_ign_case(strcmp_ign_case_s5, strcmp_ign_case_s6) == 1) {
        printf("\"HELicopter\" appears after \"hello\" in the dictionary.\n");
    }
    else if(strcmp_ign_case(strcmp_ign_case_s5, strcmp_ign_case_s6) == -1) {
        printf("\"HELicopter\" appears before \"hello\" in the dictionary.\n");
    }
    else {
        printf("\"Helicopter\" and \"hello\" are the same.\n");
    }

    if(strcmp_ign_case(strcmp_ign_case_s7, strcmp_ign_case_s8) == 1) {
        printf("\"zebra\" appears after \"lion\" in the dictionary.\n");
    }
    else if(strcmp_ign_case(strcmp_ign_case_s7, strcmp_ign_case_s8) == -1) {
        printf("\"zebra\" appears before \"lion\" in the dictionary.\n");
    }
    else {
        printf("\"zebra\" and \"lion\" are the same.\n");
    }

    if(strcmp_ign_case(strcmp_ign_case_s6, strcmp_ign_case_s6) == 1) {
        printf("\"help\" appears after \"help\" in the dictionary.\n");
    }
    else if(strcmp_ign_case(strcmp_ign_case_s6, strcmp_ign_case_s6) == -1) {
        printf("\"help\" appears before \"help\" in the dictionary.\n");
    }
    else {
        printf("\"help\" and \"help\" are the same.\n");
    }

    printf("\n");

    //Test for take_last
    printf("Testing take_last\n");
    char take_last_s1[] = "hello";
    int take_last_n1 = 3;
    char take_last_s2[] = "hello";
    int take_last_n2 = 6;
    char take_last_s3[] = "Brubeck";
    int take_last_n3 = 5;

    printf("Taking the last 3 letters of \"hello\"...\n");
    take_last(take_last_s1, take_last_n1);
    printf("Result: \"%s\"\n", take_last_s1);

    printf("Taking the last 6 letters of \"hello\"...\n");
    take_last(take_last_s2, take_last_n2);
    printf("Result: \"%s\"\n", take_last_s2);

    printf("Taking the last 5 letters of \"Brubeck\"...\n");
    take_last(take_last_s3, take_last_n3);
    printf("Result: \"%s\"\n", take_last_s3);

    printf("\n");

    //Test for dedup
    printf("Testing dedup\n");
    char *dedup_s1 = "There's always money in the banana stand.";
    char *dedup_s2 = "hello";

    char *dedup_string1 = dedup(dedup_s1);
    char *dedup_string2 = dedup(dedup_s2);

    printf("The result of dedup on \"There's always money in the banana stand.\": \"%s\"\n", dedup_string1);
    printf("The result of dedup on \"hello\": \"%s\"\n", dedup_string2);

    printf("\n");

    //Test for pad
    printf("Testing pad\n");
    char *pad_s1 = "abcd";
    int pad_d1 = 3;
    char *pad_s2 = "hi";
    int pad_d2 = 3;
    char *pad_s3 = "help";
    int pad_d3 = 4;
    char *pad_s4 = "";
    int pad_d4 = 0;

    char *pad_string1 = pad(pad_s1, pad_d1);
    char *pad_string2 = pad(pad_s2, pad_d2);
    char *pad_string3 = pad(pad_s3, pad_d3);
    char *pad_string4 = pad(pad_s4, pad_d4);

    printf("Result of pad on \"abcd\" and 3: \"%s\"\n", pad_string1);
    printf("Result of pad on \"hi\" and 3: \"%s\"\n", pad_string2);
    printf("Result of pad on \"help\" and 4: \"%s\"\n", pad_string3);
    printf("Result of pad on \"\" and 0: \"%s\"\n", pad_string4);

    printf("\n");

    //Test for ends_with_ignore_case
    printf("Testing ends_with_ignore_case\n");
    char *ends_with_ignore_case_s1 = "Coding";
    char *ends_with_ignore_case_suff1 = "ing";
    char *ends_with_ignore_case_s2 = "Coding";
    char *ends_with_ignore_case_suff2 = "in";

    if(ends_with_ignore_case(ends_with_ignore_case_s1, ends_with_ignore_case_suff1) == 1) {
        printf("\"ing\" is the suffix of \"Coding\".\n");
    }
    else {
        printf("\"ing\" is not the suffix of \"Coding\".\n");
    }

    if(ends_with_ignore_case(ends_with_ignore_case_s2, ends_with_ignore_case_suff2) == 1) {
        printf("\"in\" is the suffix of \"Coding\".\n");
    }
    else {
        printf("\"in\" is not the suffix of \"Coding\".\n");
    }

    printf("\n");

    //Test for repeat
    printf("Testing repeat\n");
    char *repeat_s1 = "hello";
    int repeat_x1 = 3;
    char repeat_sep1 = '-';
    char *repeat_s2 = "Spiderman";
    int repeat_x2 = 4;
    char repeat_sep2 = '!';

    char *repeat_string1 = repeat(repeat_s1, repeat_x1, repeat_sep1);
    char *repeat_string2 = repeat(repeat_s2, repeat_x2, repeat_sep2);

    printf("The result of repeat on \"hello\", 3, '-': \"%s\"\n", repeat_string1);
    printf("The result of repeat on \"Spiderman\", 4, '!': \"%s\"\n", repeat_string2);

    printf("\n");

    //Test for replace
    printf("Testing replace\n");
    char *replace_s1 = "Steph is the X at being the X";
    char *replace_pat1 = "X";
    char *replace_rep1 = "best";
    char *replace_s2 = "Thomas Jefferson";
    char *replace_pat2 = "Thomas";
    char *replace_rep2 = "Tom";

    char *replace_string1 = replace(replace_s1, replace_pat1, replace_rep1);
    char *replace_string2 = replace(replace_s2, replace_pat2, replace_rep2);

    printf("The result of replace on \"Steph is the X at being the X\", \"X\", \"best\": \"%s\"\n", replace_string1);
    printf("The result of replace on \"Thomas Jefferson\", \"Thomas\", \"Tom\": \"%s\"\n", replace_string2);

    printf("\n");

    //Test for str_connect
    printf("Testing str_connect\n");
    char *connect_strs1[5] = {"Washington", "Adams", "Jefferson", "Madison", "Monroe"};
    int connect_n1 = 3;
    char connect_c1 = '+';
    char *connect_strs2[4] = {"Hello", "world", "Hello", "World"};
    int connect_n2 = 4;
    char connect_c2 = '-';

    char *connect_string1 = str_connect(connect_strs1, connect_n1, connect_c1);
    char *connect_string2 = str_connect(connect_strs2, connect_n2, connect_c2);

    printf("The result of connecting the first 3 strings of connect_n1 with the separator '+': \"%s\"\n", connect_string1);
    printf("The result of connecting the first 4 strings of connect_n2 with the separator '-': \"%s\"\n", connect_string2);

    printf("\n");

    //Test for rm_empties
    printf("Testing rm_empties\n");
    char *rm_empties_words1[] = {"Hello", "World", "", "", "Steph", NULL};
    char *rm_empties_words2[] = {"", "Clinton", "", "Bush", "", "Obama", "", "Trump", "", NULL};

    printf("Removing empty strings from rm_empties_words1...\n");
    rm_empties(rm_empties_words1);
    printf("Resulting contents of array: ");
    for(int i = 0; rm_empties_words1[i] != NULL; i++) {
        printf("\"%s\" ", rm_empties_words1[i]);
    }

    printf("\n");

    printf("Removing empty strings from rm_empties_words2...\n");
    rm_empties(rm_empties_words2);
    printf("Resulting contents of array: ");
    for(int i = 0; rm_empties_words2[i] != NULL; i++) {
        printf("\"%s\" ", rm_empties_words2[i]);
    }
    printf("\n");

    printf("\n");

    //Test for str_chop_all
    printf("Testing str_chop_all\n");
    char *str_chop_all_s1 = "I am ready for a nice vacation";
    char str_chop_all_c1 = ' ';
    char *str_chop_all_s2 = "";
    char str_chop_all_c2 = ' ';

    printf("Creating the array for \"%s\"...\n", str_chop_all_s1);
    char **str_chop_all_array1 = str_chop_all(str_chop_all_s1, str_chop_all_c1);
    printf("Resulting contents of str_chop_all_array1: ");
    if(*str_chop_all_array1 != NULL) {
        while(*str_chop_all_array1 != NULL) {
            printf("\"%s\" ", *str_chop_all_array1);
            str_chop_all_array1++;
        }
    }
    else {
        printf("\n\"%s\" is an empty string.", str_chop_all_s1);
    }

    printf("\n");

    printf("Creating the array for \"%s\"...\n", str_chop_all_s2);
    char **str_chop_all_array2 = str_chop_all(str_chop_all_s2, str_chop_all_c2);
    printf("Resulting contents of str_chop_all_array2: ");
    if(str_chop_all_array2 != NULL) {
        while(*str_chop_all_array2 != NULL) {
            printf("\"%s\" ", *str_chop_all_array2);
            str_chop_all_array2++;
        }
    }
    else {
        printf("\n\"%s\" is an empty string.", str_chop_all_s2);
    }

    printf("\n");
}
