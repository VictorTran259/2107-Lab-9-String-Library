//Returns the length of s1 - the length of s2.
#include "string.h"

int len_diff(char *s1, char *s2) {
    int s1_length = 0;
    int s2_length = 0;

    while(*s1 != '\0' || *s2 != '\0') {
        if(*s1 != '\0') {
            s1_length++;
            s1++;
        }
        if(*s2 != '\0') {
            s2_length++;
            s2++;
        }
    }

    return s1_length - s2_length;
}
