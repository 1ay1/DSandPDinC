//using recursion to find the correctness of an algebraic expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STR_LEN 100

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


int main() {
    char *ch = get_new_string();
    puts(f_string(ch));

    return 0;
}