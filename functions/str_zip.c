//Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other. For example, if
//s1 is "Spongebob" and s2 is "Patrick", the function returns the string "SPpaotnrgiecbkob".
#include <stdlib.h>
#include "string.h"

char *str_zip(char *s1, char *s2) {
    char *ptr1 = s1;
    char *ptr2 = s2;
    int string1_size = 0;
    int string2_size = 0;

    //Determines the size of both strings for the creation of the new string later.
    while(*ptr1 != '\0') {
        string1_size++;
        ptr1++;
    }
    while(*ptr2 != '\0') {
        string2_size++;
        ptr2++;
    }

    //Create the new string with one extra space at the end for the '\0'.
    int new_string_size = string1_size + string2_size + 1;
    char *new_string = malloc(new_string_size * sizeof(char));
    while(*s1 != '\0' || *s2 != '\0') {
        if(*s1 != '\0') {
            *new_string = *s1;
            new_string++;
            s1++;
        }
        if(*s2 != '\0') {
            *new_string = *s2;
            new_string++;
            s2++;
        }
    }
    *new_string = '\0';
    new_string = new_string - (new_string_size - 1);

    return new_string;
}
