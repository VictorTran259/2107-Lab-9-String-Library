//Returns 1 if all of the characters in the string are either upper- or lower-case letters of the alphabet. It returns 0 otherwise.
#include "string.h"

int all_letters(char *s) {
    while(*s != '\0') {
        if( (int)*s != 32 && !((int)*s >= 65 && (int)*s <= 90) && !((int)*s >= 97 && (int)*s <= 122) ) {
            return 0;
        }
        s++;
    }

    return 1;
}
