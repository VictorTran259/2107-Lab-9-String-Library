//Returns a copy of the string s, but with each instance of pat replaced with rep, note that len(pat) can be less
//than, greater than, or equal to len(rep). The function allocates memory for the resulting string, and it is up to
//the caller to free it. For example, if we call replace("NBA X", "X", "rocks"), what is returned is the new
//string NBA rocks (but remember, pat could be longer than an individual character and could occur multiple
//times).
#include <stdlib.h>
#include "string.h"

char *replace(char *s, char *pat, char *rep) {
    int string_size = 0;
    int pat_size = 0;
    int rep_size = 0;
    char *ptr1 = s;
    char *ptr2 = pat;
    char *ptr3 = rep;

    //Calculate the size of each string.
    while (*ptr1 != '\0') {
        string_size++;
        ptr1++;
    }
    while (*ptr2 != '\0') {
        pat_size++;
        ptr2++;
    }
    while (*ptr3 != '\0') {
        rep_size++;
        ptr3++;
    }

    //Adds 1 extra space for the '\0' at the end.
    pat_size++;
    rep_size++;

    //Used to calculate the length of the new string later.
    //If pat and rep are the same length, the difference is 0.
    //If pat and rep are different lengths the difference equals the size of rep - the size of pat.
    //EX: pat = "bc" rep = "XYZ" diff_between_pat_and_rep = 1
    //EX: pat = "bce" rep = "XY" diff_between_pat_and_rep = -1
    int diff_between_pat_and_rep = 0;
    if(pat_size < rep_size || pat_size > rep_size) {
        diff_between_pat_and_rep = rep_size - pat_size;
    }

    //Finds out how many times pat occurs in the string to help calculate the size of the new string.
    int num_occurences_pat = 0;
    ptr1 = s;
    ptr2 = pat;
    while(*ptr1 != '\0') {
        if(*ptr1 == *ptr2) {
            char *ptr_to_ptr1_location = ptr1;
            while(*ptr_to_ptr1_location == *ptr2) {
                ptr_to_ptr1_location++;
                ptr2++;
                if(*ptr2 == '\0') {
                    num_occurences_pat++;
                }
            }
            ptr2 = pat;
        }
        ptr1++;
    }

    //Size of the new string will be the current string size + the difference between pat and rep multiplied by the number of occurrences of pat.
    //1 extra space is added for the '\0' at the end.
    int new_string_size = string_size + (diff_between_pat_and_rep * num_occurences_pat) + 1;

    //Create the new string.
    char *new_string = malloc(new_string_size * sizeof(char));
    ptr1 = s;
    ptr3 = rep;
    while(*ptr1 != '\0') {
        //It's not pat if the character ptr1 points to is not equal to the first character of pat (ptr2).
        if(*ptr1 != *ptr2) {
            *new_string = *ptr1;
            new_string++;
            ptr1++;
        }
        //Replaces any occurrences of pat with rep in the new string.
        if(*ptr1 == *ptr2) {
            char *ptr_to_ptr1_location = ptr1;
            while(*ptr_to_ptr1_location == *ptr2) {
                ptr_to_ptr1_location++;
                ptr2++;
                if(*ptr2 == '\0') {
                    while(*ptr3 != '\0') {
                        *new_string = *ptr3;
                        new_string++;
                        ptr3++;
                    }
                }
            }
            ptr2 = pat;
            ptr3 = rep;
            ptr1 = ptr1+(pat_size-1);
        }
    }

    new_string = new_string - (new_string_size - 1);
    return new_string;
}
