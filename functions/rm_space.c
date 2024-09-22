//removes whitespace characters from the beginning and the ending s.
#include "string.h"

void rm_space(char *s) {
    //Pointer to the beginning of the string.
    char *ptr = s;

    //Move the pointer past all the white spaces at the beginning of the string.
    while((int)*s == 32) {
        s++;
    }

    //Move the pointer to the end of the string while iterating int size by 1 each time the pointer is moved.
    int size = 0;
    while(*s != '\0') {
        size++;
        s++;
    }

    //Move the pointer back from '\0'.
    s--;

    //Move the pointer back until it reaches a non white space char and decrease the size by 1 each time the pointer is moved.
    while((int)*s == 32) {
        size--;
        s--;
    }

    //Move the pointer forward towards the first white space.
    s++;

    //Replaces any white spaces at the end of the string with '\0'.
    int num_white_spaces = 0;
    while((int)*s == 32) {
        num_white_spaces++;
        *s = '\0';
        s++;
    }

    //Move the pointer back to the last char of the string.
    while(num_white_spaces > 0) {
        num_white_spaces--;
        s--;
    }
    s--;

    //Move the pointer back to the first non white space char of the string.
    while(size > 1) {
        size--;
        s--;
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
