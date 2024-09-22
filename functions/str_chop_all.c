//Returns an array of string consisting of the characters in s split into tokens based on the delimeter c, followed by
//a NULL pointer. For example, if s is "I am ready for a nice vacation" and c is ' ', it returns {"I", "am",
//"ready", "for", "a", "nice", "vacation", NULL}.
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char **str_chop_all(char *s, char c) {
    char **strings = NULL;

    //CASE: s = "" (empty string).
    if(*s == '\0') {
        printf("empty string\n");
        return strings;
    }

    //Calculate the number of words in the string.
    char *ptr = s;
    int num_words = 0;
    while(*ptr != '\0') {
        if(*ptr == c) {
            num_words++;
        }
        ptr++;
    }
    ptr--;
    if(((int)*ptr >= 32 && (int)*ptr <= 126) && *ptr != c) {
        num_words++;
    }

    //Initialize all word sizes to 1 for the '\0' at the end of each string.
    int word_size[num_words];
    for(int i = 0; i < num_words; i++) {
        word_size[i] = 1;
    }

    //Find the size of each word and store it in the word_size array.
    ptr = s;
    int i = 0;
    while(*ptr != '\0') {
        if(*ptr != c) {
            word_size[i]++;
        }
        else {
            i++;
        }
        ptr++;
    }

    //Adds each word in the string to the array.
    strings = malloc(num_words * sizeof(s));
    ptr = s;
    for(int i = 0; i < num_words; i++) {
        char *word = malloc(word_size[i] * sizeof(char));
        char *word_ptr = word;
        while(*ptr != c) {
            *word = *ptr;
            word++;
            ptr++;
        }
        if(*ptr == c) {
            *word = '\0';
            ptr++;
        }
        *strings = word_ptr;
        strings++;
    }

    *strings = NULL;
    strings = strings - num_words;
    return strings;
}
