//Shortens the string s to new_len. If the original length of s is less than or equal to new_len, s is unchanged.
#include "string.h"

void shorten(char *s, int new_len) {
    int size = 0;
    char *ptr = s;

    //Check the size of the string.
    while(*ptr != '\0') {
        size++;
        ptr++;
    }

    //If the new_len is less than the size, iterate pointer *s to right after the first new_len chars.
    //Replace any remaining chars at the spot of the pointer and after it with '\0'.
    if(size > new_len) {
        for(int i = 0; i < new_len; i++) {
            s++;
        }
        while(*s != '\0') {
            *s = '\0';
            s++;
        }
    }
}
