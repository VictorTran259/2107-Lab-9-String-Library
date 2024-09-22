//removes whitespace characters from the end of s.
#include "string.h"

void rm_right_space(char *s) {
    //Iterate through the letters of the string until two consecutive white spaces or a white space and '\0' after it are found.
    while(*s != '\0') {
        s++;
    }

    //Move the pointer back from '\0'.
    s--;

    //Move the pointer back until it reaches a non white space char.
    while(*s == 32) {
        s--;
    }

    //Move the pointer forward towards the first white space.
    s++;

    //Replaces any white spaces at the end of the string with '\0'.
    while(*s == 32) {
        *s = '\0';
        s++;
    }
}
