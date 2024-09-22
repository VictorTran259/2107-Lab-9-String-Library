//removes whitespace characters from the beginning of s.
#include "string.h"

void rm_left_space(char *s) {
    //Pointer to the beginning of string s.
    char *ptr = s;

    //Iterate through the white spaces at the beginning of the string until a non white space char is reached.
    while((int)*s == 32) {
        s++;
    }

    //Move each char to the beginning of the string.
    while(*s != '\0') {
        *ptr = *s;
        ptr++;
        s++;
    }

    //Replace all the other remaining garbage characters with '\0'.
    while(*ptr != '\0') {
        *ptr = '\0';
        ptr++;
    }
}
