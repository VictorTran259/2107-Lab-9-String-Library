//returns a new string consisting of all of the letters of s, but padded with spaces at the end so that the total length
//of the returned string is an even multiple of d. If the length of s is already an even multiple of d, the function
//returns a copy of s. The function returns NULL on failure or if s is NULL. Otherwise, it returns the new string. It is
//up to the caller to free any memory allocated by the function.
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char *pad(char *s, int d) {
    int string_size = 0;
    int new_string_size = d;
    char *ptr = s;

    //Determine the size of the string.
    while(*ptr != '\0') {
        string_size++;
        ptr++;
    }

    char *new_string = NULL;
    //Return NULL if the s = "" (size of s = 0).
    if(string_size == 0) {
        return NULL;
    }
    //CASE EX:s = "abcd" d = 3. output would be "abcd  " (2 white spaces added after the letters
    //which makes the length of the string 6 to meet the requirements of the length
    //to be an even multiple of d where all letters of s are included)
    else if(string_size > new_string_size) {
        for(int i = 2; new_string_size < string_size && new_string_size%2 != 0; i++) {
            new_string_size *= i;
        }
        new_string_size++;
        new_string = malloc(new_string_size * sizeof(char));
        for(int i = 0; i < string_size; i++) {
            *new_string = *s;
            new_string++;
            s++;
        }
        for(int i = string_size; i < new_string_size-1; i++) {
            *new_string = ' ';
            new_string++;
        }
        *new_string = '\0';
        new_string = new_string - (new_string_size - 1);
        return new_string;
    }
    //CASE EX 1:s = "hi" d = 3. output would be "hi    " (3 is not an even multiple of 3 so
    //4 white spaces added after the letters which makes the length of the string 6 to meet the requirements of the length
    //to be an even multiple of d where all letters of s are included)
    //CASE EX 2:s = "hello" d = 5. output would be "hello     " (5 is not an even multiple of 5 so
    //5 white spaces added after the letters which makes the length of the string 10 to meet the requirements of the length
    //to be an even multiple of d where all letters of s are included)
    else if(string_size < new_string_size || (string_size == new_string_size && new_string_size%2 != 0)) {
        for(int i = 2; new_string_size%2 != 0; i++) {
            new_string_size *= i;
        }
        new_string_size++;
        new_string = malloc(new_string_size * sizeof(char));
        for(int i = 0; i < string_size; i++) {
            *new_string = *s;
            new_string++;
            s++;
        }
        for(int i = string_size; i < new_string_size-1; i++) {
            *new_string = ' ';
            new_string++;
        }
        *new_string = '\0';
        new_string = new_string - (new_string_size - 1);
        return new_string;
    }
    //CASE EX:s = "help" d = 4. output would be "help" (4 is an even multiple of 4 and there are only 4 letters in "help" so no need to change the length)
    else if(string_size == new_string_size && new_string_size%2 == 0){
        new_string = s;
        return new_string;
    }

    return NULL;
}
