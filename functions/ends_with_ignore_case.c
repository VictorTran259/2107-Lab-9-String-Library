//returns 1 if suff is a suffix of s ignoring case or 0 otherwise.
#include "string.h"

int ends_with_ignore_case(char *s, char *suff) {
    char *ptr1 = s;
    char *ptr2 = suff;
    int size_s = 0;
    int size_suff = 0;

    //Determine the size of the two strings.
    while(*ptr1 != '\0') {
        size_s++;
        ptr1++;
    }
    while(*ptr2 != '\0') {
        size_suff++;
        ptr2++;
    }

    //Adds a place for the '\0' at the end of the string in the arrays.
    size_s++;
    size_suff++;

    //Copies both strings into arrays and make all the letters lowercase for easier comparison.
    ptr1 = s;
    ptr2 = suff;
    char string_s[size_s];
    char string_suff[size_suff];
    for(int i = 0; *ptr1 != '\0'; i++) {
        if((int)*ptr1 >= 65 && (int)*ptr1 <= 90) {
            string_s[i] = (int)*ptr1+32;
        }
        else {
            string_s[i] = *ptr1;
        }
        ptr1++;
    }
    for(int i = 0; *ptr2 != '\0'; i++) {
        if((int)*ptr2 >= 65 && (int)*ptr2 <= 90) {
            string_suff[i] = (int)*ptr2+32;
        }
        else {
            string_suff[i] = *ptr2;
        }
        ptr2++;
    }
    string_s[size_s-1] = '\0';
    string_suff[size_suff-1] = '\0';

    //int i is set back the size of suff spaces from the end of string_s.
    //int j is set to the beginning of string_suff.
    int i = size_s - size_suff;
    int j = 0;
    //Checks to see if the two current letters are the same. If they are, increment i and j to check if the next two letters are the same.
    //If they're different, return 0. If the end of both strings are reached without 0 being returned, then string suff is the suffix of string s
    //and 1 is returned.
    while(string_s[i] != '\0' && string_suff[j] != '\0') {
        if(string_s[i] != string_suff[j]) {
            return 0;
        }
        i++;
        j++;
    }

    return 1;
}
