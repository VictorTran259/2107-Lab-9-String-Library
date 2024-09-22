//returns the number of positions in which s1 and s2 differ, i.e., it returns the number of changes that would need to
//be made in order to transform s1 into s2, where a change could be a character substitution, an insertion, or a
//deletion.
#include "string.h"

int diff(char *s1, char *s2) {
    int difference = 0;

    while(*s1 != '\0' || *s2 != '\0') {
        if((int)*s1 != (int)*s2) {
            difference++;
        }
        if(*s1 != '\0') {
            s1++;
        }
        if(*s2 != '\0') {
            s2++;
        }
    }

    return difference;
}
