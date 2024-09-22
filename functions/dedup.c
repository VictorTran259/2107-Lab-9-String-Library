//returns a new string based on s, but without any duplicate characters. For example, if s is the string, "There's
//always money in the banana stand.", the function returns the string "Ther's alwymonitbd.". It is up
//to the caller to free the memory allocated by the function.
#include <stdlib.h>
#include "string.h"

char *dedup(char *s) {
    //There are 94 unique characters on the ascii table. 1 extra space for a '\0' if necessary.
    char unique_chars[95];
    int num_curr_unique_chars = 0;

    while(*s != '\0') {
        int is_present = 0;
        //Checks through all the current unique characters in the array and if the character that pointer s is currently pointing to is already
        //present in the array, updates is_present to 1 which represents "true".
        for(int i = 0; i < num_curr_unique_chars; i++) {
            if(*s == unique_chars[i]) {
                is_present = 1;
            }
        }
        //If the character that pointer s is currently pointing to was not found to be present in the array, adds the character to the array.
        if(is_present == 0) {
            unique_chars[num_curr_unique_chars] = *s;
            num_curr_unique_chars++;
        }
        s++;
    }
    unique_chars[num_curr_unique_chars] = '\0';

    //Create a pointer to the new string and return it.
    char *new_string = malloc(num_curr_unique_chars * sizeof(char));

    int i = 0;
    while(unique_chars[i] != '\0') {
        *new_string = unique_chars[i];
        new_string++;
        i++;
    }
    *new_string = '\0';
    new_string = new_string - i;

    return new_string;
}
