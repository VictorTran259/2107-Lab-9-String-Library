//Compares s1 and s2 ignoring case. Returns a positive number if s1 would appear after s2 in the dictionary, a
//negative number if it would appear before s2, or 0 if the two are equal.
#include "string.h"

int strcmp_ign_case(char *s1, char *s2) {
    char *ptr1 = s1;
    char *ptr2 = s2;
    int size_s1 = 0;
    int size_s2 = 0;

    //Determine the size of the two strings.
    while(*ptr1 != '\0') {
        size_s1++;
        ptr1++;
    }
    while(*ptr2 != '\0') {
        size_s2++;
        ptr2++;
    }

    //Adds a place for the '\0' at the end of the string in the arrays.
    size_s1++;
    size_s2++;

    //Copies both strings into arrays and make all the letters lowercase for easier comparison.
    ptr1 = s1;
    ptr2 = s2;
    char string_s1[size_s1];
    char string_s2[size_s2];
    for(int i = 0; *ptr1 != '\0'; i++) {
        if((int)*ptr1 >= 65 && (int)*ptr1 <= 90) {
            string_s1[i] = (int)*ptr1+32;
        }
        else {
            string_s1[i] = *ptr1;
        }
        ptr1++;
    }
    for(int i = 0; *ptr2 != '\0'; i++) {
        if((int)*ptr2 >= 65 && (int)*ptr2 <= 90) {
            string_s2[i] = (int)*ptr2+32;
        }
        else {
            string_s2[i] = *ptr2;
        }
        ptr2++;
    }
    string_s1[size_s1-1] = '\0';
    string_s2[size_s2-1] = '\0';

    int i = 0;
    int j = 0;
    //This while loop will stop if the strings are the same (ex: s1 = "hello" and s2 = "hello") and 0 will be returned.
    while(string_s1[i] != '\0' || string_s2[j] != '\0') {
        //CASE EX:s1 = "applesauce" and s2 = "apple". applesauce appears after apple in the dictionary.
        if(string_s1[i] != '\0' && string_s2[j] == '\0') {
            return 1;
        }
        //CASE EX:s1 = "help" and s2 = "helper". help appears before helper in the dictionary.
        if(string_s1[i] == '\0' && string_s2[j] != '\0') {
            return -1;
        }

        //CASE EX:s1 = "hello" and s2 = "goodbye". hello appears after goodbye in the dictionary.
        if((int)string_s1[i] > (int)string_s2[j]) {
            return 1;
        }
        //CASE EX:s1 = "helicopter" and s2 = "hello". helicopter appears before hello in the dictionary.
        if((int)string_s1[i] < (int)string_s2[j]) {
            return -1;
        }
        //If the current two letters of the strings are equal, iterate i and j by 1 to check the next two letters of the strings.
        if((int)string_s1[i] == (int)string_s2[j]) {
            if(string_s1[i] != '\0') {
                i++;
            }
            if(string_s2[j] != '\0') {
                j++;
            }
        }
    }

    return 0;
}
