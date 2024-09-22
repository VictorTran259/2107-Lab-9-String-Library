//Changes s so that the first letter of every word is in upper case and each additional letter is in lower case.
#include "string.h"

void capitalize(char *s) {
    //Moves the pointer past any non letter characters such as white spaces to the first letter of the first word.
    //EX: s = " !@hello world"
    while(!( ((int)*s >= 97 && (int)*s <= 122) || ((int)*s >= 65 && (int)*s <= 90) ) ) {
        s++;
    }
    //Capitalize the first letter of the first word if it's lowercase.
    if((int)*s >= 97 && (int)*s <= 122) {
        *s = (int)*s-32;
    }

    while(*s != '\0') {
        char *ptr = s - 1;
        //If the character before the character that the pointer s is pointing to is something like " !@_:;" and the character the pointer s
        //is pointing to is lowercase, make it uppercase.
        if((((int)*ptr >= 32 && (int)*ptr <= 64) || ((int)*ptr >= 91 && (int)*ptr<= 96) || ((int)*ptr >= 123
        && (int)*ptr <= 126)) && ((int)*s >= 97 && (int)*s <= 122)) {
            *s = (int)*s-32;
        }
        s++;
    }
}
