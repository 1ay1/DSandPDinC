//using recursion to find the correctness of an algebraic expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STR_LEN 100

int is_factor(char str[], int length, int *ppos);
int is_term(char str[], int length, int *ppos);
int is_expr(char str[], int length, int *ppos);

char str[STR_LEN];


char * get_new_string() {
    fgets(str, STR_LEN, stdin);
    return str;
}

char * f_string(char *s) {
    int i, j;
    char *r, *ss;
    r = s;
    ss = s;
    for(j = 0, i = 0; j < strlen(s); j++) {
        if(*(ss + j) != ' ') {
            *(r + (i++)) = *(ss + j);
        }
    }
    *(r+i) = '\0';
    return r;
} 

char get_symbol(char sym[], int length, int *ppos) {
    char c;

    if( *ppos < length) c = str[*ppos];
    else c =  ' ';

    (*ppos)++;
    return c;
}

int is_factor(char str[], int length, int *ppos) {
    int c;
    if((c = get_symbol(str, length, ppos)) != '(') return (isalpha(c));
    return (is_expr(str, length, ppos) && (get_symbol(str, length, ppos) == ')') ); 
}

int is_term(char str[], int length, int *ppos) {
    if(is_factor(str, length, ppos) == 0) return 0;
    if(get_symbol(str, length, ppos) != '*') {
        (*ppos)--;
        return 1;
    }
    return(is_factor(str, length, ppos));
}




int is_expr(char str[], int length, int * ppos) {
    if(is_term(str, length, ppos) == 0) return 0;
    if(get_symbol(str, length, ppos) != '+') {
        (*ppos)--;
        return 1;
    }
    return (is_term(str, length, ppos));
}

int main() {
    char *ch = get_new_string();
    int pos = 0;
    if((is_expr(ch, strlen(ch), &pos) == 1) && pos <= strlen(ch)) {
        printf("Valid Expression!\n");
    }
    else {
        puts("Invalid Expression!");
    }

    return 0;
}