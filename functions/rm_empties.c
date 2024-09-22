//words is an array of string terminated with a NULL pointer. The function removes any empty strings (i.e., strings
//of length 0) from the array.
#include <stdio.h>
#include "string.h"

void rm_empties(char **words) {
    int array_size = 0;
    int num_nonempty_strings = 0;

    //Find the size of the array and the number of nonempty strings in the array.
    char **ptr = words;
    while(*ptr != NULL) {
        array_size++;
        ptr++;
    }
    ptr = words;
    while(*ptr != NULL) {
        if(**ptr != '\0') {
            num_nonempty_strings++;
        }
        ptr++;
    }

    //For later when the rest of the array needs to be filled with NULL.
    int starting_position = num_nonempty_strings;

    //Searches for empty strings, replace them with the next nonempty string, and replace the nonempty string used with an empty string to be replaced again.
    while(num_nonempty_strings != 0) {
        if(**words == '\0') {
            char **ptr_to_next_nonempty_string = words;
            int num_increments = 0;
            while(**ptr_to_next_nonempty_string == '\0') {
                ptr_to_next_nonempty_string++;
                num_increments++;
            }
            *words = *ptr_to_next_nonempty_string;
            words = ptr_to_next_nonempty_string;
            *words = "";
            words = words - num_increments;
        }
        num_nonempty_strings--;
        words++;
    }

    //Fill the rest of the array with NULL.
    for(int i = starting_position; i < array_size; i++) {
        *words = NULL;
        words++;
    }
}
