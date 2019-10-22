#include <stdio.h>

int get_int() {
    int i, s_n;
    while ((s_n = scanf("%d", &i)) != 1)
    {
        puts("Enter a valid number!");
    }
    
    return i;
}

int main() {
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        sum += get_int();
    }

    printf("Sum: %d\n", sum); 

    return 0;    
}
