//prefix to postfix using recursion
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLENGTH 100

char *between_substring(char *str, char from, char to){
    while(*str && *str != from)
            ++str;//skip
    if(*str == '\0')
        return NULL;
    else
        ++str;

    char *ret = malloc(strlen(str)+1);
    char *p = ret;
    while(*str && *str != to){
        *p++ = *str++;//To the end if `to` do not exist
    }
    *p = 0;
    return ret;
}

// find function using recursion that returns the longest prefix expression starting at the index 0 of the
//string
int find(char str[]) {
    char *temp;
    int length;

    int i, j , m , n;

    if((length = strlen(str)) == 0) { //if the length is zero return zero and everything is over
        return 0;
    }

    if(isalpha(str[0]) != 0) { //if first char is a letter, THATS the longest prefix exp we are looking for
        return 1;
    }

    // if the first char is operator then

    if(strlen(str) < 2) { // if the first character is operator and length is only one, its invalid char
        return 0;
    }

    //remove the operator and find the first operand of the prefix expression at the starting
    // remove the operator at 0
    temp = between_substring(str, 1, length-1);
    //find the first operand (which can be a prefix exp too)
    m = find(temp);

    if(m == 0 || strlen(str) == m) {
        return 0; // there was only one operator then no valid prefix exp
    }
    // find the next operand
    temp = between_substring(str, m+1, length - m - 1);
    if(n == 0) return 0; // no valid second operand, so not a valid prefix exp

    return(m+n+1) // plus one to add the starting operator that we removed
}



int main() {

}