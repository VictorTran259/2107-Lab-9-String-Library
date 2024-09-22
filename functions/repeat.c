//Returns a new string consisting of the characters in s repeated x times, with the character sep in between. For
//example, if s is the string all right, x is 3, and sep is , the function returns the new string all right,all
//right,all right. If s is NULL, the function returns NULL. It is up to the caller to free any memory allocated by
//the function.
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char *repeat (char *s, int x, char sep) {
    int string_size = 0;
    char *ptr = s;

    //Determine the size of the string.
    while (*ptr != '\0') {
        string_size++;
        ptr++;
    }

    if(string_size == 0) {
        return NULL;
    }

    //Determine the size of the new string. 1 additional space for the '\0' at the end of the string.
    int num_separators = x - 1;
    int new_string_size = (string_size * x) + num_separators + 1;

    //Creates the new string. While loop goes until x amount of repetitions is completed.
    ptr = s;
    char new_string_array[new_string_size];
    int num_repetitions = 0;
    int i = 0;
    while (num_repetitions < x) {
        new_string_array[i] = *ptr;
        i++;
        ptr++;
        //If the end of the string is reached, reset the pointer to the beginning and place the separator if it's not at the last repetition.
        if (*ptr == '\0') {
            if(i < new_string_size) {
                new_string_array[i] = sep;
            }
            num_repetitions++;
            i++;
            ptr = s;
        }
    }
    new_string_array[new_string_size-1] = '\0';

    char *new_string = malloc(new_string_size * sizeof(char));
    i = 0;
    while(new_string_array[i] != '\0') {
        *new_string = new_string_array[i];
        new_string++;
        i++;
    }
    *new_string = '\0';
    new_string = new_string - i;

    return new_string;
}
