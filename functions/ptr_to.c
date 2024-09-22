//returns a pointer to the first occurrence of n in the string h or NULL if it isn't found.
#include <stdio.h>
#include "string.h"

char *ptr_to(char *h, char *n) {
    while(*h != '\0') {
        //If the char that pointer h is pointing to is equal to the first letter of string n,
        //initiate a check to see if it's string n inside string h.
        if(*h == *n) {
            char *ptr_to_h = h;
            char *ptr_to_n = n;
            while(*ptr_to_h == *ptr_to_n) {
                ptr_to_h++;
                ptr_to_n++;
                //If *ptr_to_n = '\0', that means string n was found in string h so return a pointer to where h is currently pointing to.
                if(*ptr_to_n == '\0') {
                    return h;
                }
            }
        }
        h++;
    }

    return NULL;
}
