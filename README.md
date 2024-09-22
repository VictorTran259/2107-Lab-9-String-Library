# CIS 2107 Lab 9 - String Library

## String Library
In this assignment, you'll create your own library of string functions. You'll have the opportunity to practice manipulating strings and managing memory. Additionally, you'll learn the role of header and library files. You may not call functions in string.h but you can use other code in the Standard C Library.

### all_letters.c
    Returns 1 if all of the characters in the string are either upper- or lower-case
    letters of the alphabet. It returns 0 otherwise.

### capitalize.c
    Changes s so that the first letter of every word is in upper case and each additional letter is in lower case.

### dedup.c
    Returns a new string based on s, but without any duplicate characters. For example, if s is the string,
    "There's always money in the banana stand.", the function returns the string "Ther's alwymonitbd.".
    It is up to the caller to free the memory allocated by the function.

### diff.c
    Returns the number of positions in which s1 and s2 differ, i.e., it returns the number of changes that would need to
    be made in order to transform s1 into s2, where a change could be a character substitution, an insertion, or a
    deletion.

### ends_with_ignore_case.c
    Returns 1 if suff is a suffix of s ignoring case or 0 otherwise.

### find.c
    Returns the index of the first occurrence of n in the string h or -1 if it isn't found.

### is_empty.c
    Returns 1 if s is NULL, consists of only the null character ('') or only whitespace. returns 0 otherwise.

### len_diff.c
    Returns the length of s1 - the length of s2.

### num_in_range.c
    Returns the number of characters c in s1 such that b<=c<=t.

### pad.c
    Returns a new string consisting of all of the letters of s, but padded with spaces at the end so that the total length
    of the returned string is an even multiple of d. If the length of s is already an even multiple of d, the function
    returns a copy of s. The function returns NULL on failure or if s is NULL. Otherwise, it returns the new string. It is
    up to the caller to free any memory allocated by the function.

### ptr_to.c
    Returns a pointer to the first occurrence of n in the string h or NULL if it isn't found.

### repeat.c
    Returns a new string consisting of the characters in s repeated x times, with the character sep in between. For
    example, if s is the string all right, x is 3, and sep is , the function returns the new string all right,all
    right, all right. If s is NULL, the function returns NULL. It is up to the caller to free any memory allocated by
    the function.

### replace.c
    Returns a copy of the string s, but with each instance of pat replaced with rep, note that len(pat) can be less
    than, greater than, or equal to len(rep). The function allocates memory for the resulting string, and it is up to
    the caller to free it. For example, if we call replace("NBA X", "X", "rocks"), what is returned is the new
    string NBA rocks (but remember, pat could be longer than an individual character and could occur multiple
    times).

### rm_empties.c
    Words is an array of string terminated with a NULL pointer. The function removes any empty strings (i.e., strings
    of length 0) from the array.

### rm_left_space.c
    Removes whitespace characters from the beginning of s.

### rm_right_space.c
    Removes whitespace characters from the end of s.

### rm_space.c
    Removes whitespace characters from the beginning and the ending s.

### shorten.c
    Shortens the string s to new_len. If the original length of s is less than or equal to new_len, s is unchanged.

### str_chop_all.c
    Returns an array of string consisting of the characters in s split into tokens based on the delimeter c, followed by
    a NULL pointer. For example, if s is "I am ready for a nice vacation" and c is ' ', it returns {"I", "am",
    "ready", "for", "a", "nice", "vacation", NULL}.

### str_connect.c
    Returns a string consisting of the first n strings in strs with the character c used as a separator. For example, if
    strs contains the strings {"Washington", "Adams", "Jefferson"} and c is '+', the function returns the
    string "Washington+Adams+Jefferson".

### str_zip.c
    Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other. For example, if
    s1 is "Spongebob" and s2 is "Patrick", the function returns the string "SPpaotnrgiecbkob".

### strcmp_ign_case.c
    Compares s1 and s2 ignoring case. Returns a positive number if s1 would appear after s2 in the dictionary, a
    negative number if it would appear before s2, or 0 if the two are equal.

### take_last.c
    Modifies s so that it consists of only its last n characters. If n is ≥ the length of s,
    the original string is unmodified. For example if we call take_last("Brubeck" 5), when the
    function finishes, the original string becomes "ubeck".
