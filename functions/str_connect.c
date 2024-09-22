//Returns a string consisting of the first n strings in strs with the character c used as a separator. For example, if
//strs contains the strings {"Washington", "Adams", "Jefferson"} and c is '+', the function returns the
//string "Washington+Adams+Jefferson".
#include <stdlib.h>
#include "string.h"

char *str_connect(char **strs, int n, char c) {
    //Initialize an array to hold the size of each string with each of its values initialized to 0.
    int string_sizes[n];
    for(int i = 0; i < n; i++) {
        string_sizes[i] = 0;
    }

    //Find the size of each string before n.
    for(int i = 0; i < n; i++) {
        char *ptr = strs[i];
        while(*ptr != '\0') {
            string_sizes[i]++;
            ptr++;
        }
    }

    //Add the sizes of the first n strings to the size of the new string.
    int new_string_size = 0;
    for(int i = 0; i < n; i++) {
        new_string_size += string_sizes[i];
    }
    //Add the number of separators to the size of the new string. The number of separators is equal to number of strings (n) - 1.
    int num_separators = n - 1;
    new_string_size += num_separators;

    new_string_size++;

    //Create the new string.
    char *new_string = malloc(new_string_size * sizeof(char));
    int j = 0;
    for(int i = 0; i < n; i++) {
        char *ptr = strs[i];
        while(*ptr != '\0') {
            *new_string = *ptr;
            new_string++;
            ptr++;
        }
        //Adds the separator when the end of a string is reached that isn't the last string.
        if(*ptr == '\0' && i < n - 1) {
            *new_string = c;
            new_string++;
        }
    }
    *new_string = '\0';

    new_string = new_string - (new_string_size - 1);
    return new_string;
}
