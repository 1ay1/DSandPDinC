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

    return(m+n+1); // plus one to add the starting operator that we removed
}

// the convert function that uses find()
void convert (char prefix[], char postfix[]) {
    char *opnd1, *opnd2; // buffers for the two operands
    char post1[MAXLENGTH], post2[MAXLENGTH]; // buffers for convered postfix strings from the operands

    char *temp; //usual temp buffer
    char op[2]; //buffer for op

    int length;
    int i, j, m, n;

    if((length = strlen(prefix)) == 1) {
        if(isalpha(prefix[0])) {
            postfix[0] = prefix[0];
            postfix[1] = '\0';
            return;
        }
        else {
            printf("\n Illegal Prefix string!\n");
            exit(EXIT_FAILURE);
        }

        // the prefix string is longer than one single char
        // THE RECURSIVE PART

        // the the operator in op
        op[0] = prefix[0];
        op[1] = '\0';
        temp = between_substring(prefix, 1, length -1); 
        m = find(temp); // get first operand
        temp = between_substring(prefix, m+1, length - m - 1); // get second operand
        n = find(temp); // get second operand

        if((op[0] != '+' && op[0] != '-' && op[0] != '*' && op[0] != '/') || (m == 0) || (n == 0)
        || (m + n + 1  != length)) {
            printf("Invalid String");
            exit(EXIT_FAILURE);
        }

        opnd1 = between_substring(prefix, 1 , m);
        opnd2 = between_substring(prefix, m+1, n);
        convert(opnd1, post1);
        convert(opnd2, post2);
        strcat(post1, post2);
        strcat(post1, op);
        postfix = between_substring(post1, 0, length);
    }
}

int main() {

    char prestr[MAXLENGTH], poststr[MAXLENGTH];
    fgets(prestr, MAXLENGTH, stdin);
    
    convert(prestr, poststr);

    puts(poststr);

    return 0;
}