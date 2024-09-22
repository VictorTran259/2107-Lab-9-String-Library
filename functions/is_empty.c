//returns 1 if s is NULL, consists of only the null character ('') or only whitespace. returns 0 otherwise.
#include <stdio.h>
#include "string.h"

int is_empty(char *s) {
    if(s == NULL) {
        return 1;
    }
    if((int)*s == 0) {
        return 1;
    }
    while((int)*s == 32) {
        s++;
    }
    if(*s == '\0') {
        return 1;
    }

    return 0;
}
