//returns the index of the first occurrence of n in the string h or -1 if it isn't found.
#include "string.h"

int find(char *h, char *n) {
    char *ptr1 = h;
    char *ptr2 = n;
    int string_size = 0;
    int substring_size = 0;

    while(*ptr1 != '\0') {
        string_size++;
        ptr1++;
    }
    while(*ptr2 != '\0') {
        substring_size++;
        ptr2++;
    }

    //Adds a place for the '\0' at the end of the string in the arrays.
    string_size++;
    substring_size++;

    char string[string_size];
    char substring[substring_size];
    for(int i = 0; i < string_size; i++) {
        string[i] = *h;
        h++;
    }
    for(int i = 0; i < substring_size; i++) {
        substring[i] = *n;
        n++;
    }
    string[string_size-1] = '\0';
    substring[substring_size-1] = '\0';

    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i] == substring[0]) {
            int matching_letters = 0;
            for(int j = 0; substring[j] != '\0'; j++) {
                if(string[i+j] == substring[j]) {
                    matching_letters++;
                }
                if(matching_letters == substring_size-1) {
                    return i;
                }
            }
        }
    }

    return -1;
}
