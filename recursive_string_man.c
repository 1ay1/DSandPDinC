#define _GNU_SOURCE
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void selection_sort(int A[], int len){
    int small, temp; //small is the index not the value

    for(int i = 0; i < len -1 ; i++) {
        small = i;
        for(int j = i+1; j < len; j++){
            if(A[j] < A[small]) small = j;
        }

        temp = A[small];
        A[small] = A[i];
        A[i] = temp;
    }
}


int fact(int n) {
    int fact = 1;
    int i = 2;
    while (i <= n)
    {
        fact = fact * i;
        i++;
    }

    return fact;    
}

int str_dic(char *ch1, char *ch2) {
    //first base case
    if(*(ch1) != *(ch2)){
      if ( *(ch1) < * (ch2)) return 1;
      else return 0;
    }

    //second_base case
    if(*(ch1+1) == '\0' || *(ch2+1) == '\0'){
        if(*(ch1+1) == '\0') return 1;
        else return 0;
    }

    //move on 
    str_dic(ch1 + 1, ch2 + 1);
}

void selection_sort_strings(char **A, int len){
    int small; //small is the index not the value
    char *temp; //small is the index not the value

    for(int i = 0; i < len -1 ; i++) {
        small = i;
        for(int j = i+1; j < len; j++){
            if(str_dic(A[j], A[small])) small = j;
        }

        temp = A[small];
        A[small] = A[i];
        A[i] = temp;
    }
}

int main() {
    FILE *fp;
    if(!(fp = fopen("file.txt", "r"))){
        puts("Feed a valid file to sort!");
        exit(EXIT_FAILURE);
    }

    int count =0;
    char ch;
    for(ch = fgetc(fp); ch != EOF; ch = fgetc(fp)){
        if(ch == '\n') count++;
    }

    char **lines = malloc(sizeof(char *)*count + 1);

    fseek(fp, 0, 0);
    int char_count = 0;
    int line_count = 0;
    int *line_sum = malloc(sizeof(int)* count + 1);
    for(ch = fgetc(fp); ch != EOF; ch = fgetc(fp)) {
        if(ch != '\n') {
            char_count++;
        }
        else {
            lines[line_count] = malloc(sizeof(char)*char_count + 1);
            line_sum[line_count] = char_count + 1;
            char_count = 0;
            line_count++;
        }
    }

    // for (size_t i = 0; i < count; i++)
    // {
    //     *(lines + i) = malloc(sizeof(char)*100000);
    // }

    fseek(fp, 0, 0);

    int cn = 0;
    while ((fgets(lines[cn], line_sum[ch], fp)) != NULL)
    {
        cn++;
    }

    for(int i = 0; i < count; i++) {
        printf("%s", lines[i]);
    }
    
    

    printf("%d\n", count);  

    puts("------------------------------------------------");
    puts("=====================================================");

    selection_sort_strings(lines, count);
    for(int i = 0; i < count; i++) {
        printf("%s", lines[i]);
    }

}