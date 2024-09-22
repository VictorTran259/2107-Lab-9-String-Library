//Modifies s so that it consists of only its last n characters. If n is ≥ the length of s, the original string is unmodified.
//For example if we call take_last("Brubeck" 5), when the function finishes, the original string becomes "ubeck".
#include "string.h"

void take_last(char *s, int n) {
    char *ptr = s;
    int string_size = 0;

    //Determine the size of the string.
    while(*ptr != '\0') {
        string_size++;
        ptr++;
    }

    //If n is less than the string size, the string needs to be modified.
    if(n < string_size) {
        //Pointer to the beginning of the string.
        char *ptr = s;

        //Moves the pointer until it reaches the first letter of the last n letters of the string.
        for(int i = 0; i < string_size - n; i++) {
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
}
