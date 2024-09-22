//returns the number of characters c in s1 such that b<=c<=t.
#include "string.h"

int num_in_range(char *s1, char b, char t) {
    int numCharsBetweenBAndT = 0;

    while(*s1 != '\0') {
        if((int)*s1 >= b && (int)*s1 <= t) {
            numCharsBetweenBAndT++;
        }
        s1++;
    }

    return numCharsBetweenBAndT;
}
