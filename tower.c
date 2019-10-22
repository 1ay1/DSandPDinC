//tower of honoi;
#include <stdio.h>

void tower (int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Moving disk %d from peg %c to peg %c using %c!\n", n, from, to, aux);
        return;
    }

    tower(n-1, from, aux, to);
    printf("Moving disk %d from peg %c to peg %c using %c!\n", n, from, aux, to);
    tower(n-1, aux, to, from);

}

int main() {
    puts("Enter the number of disks!");
    int ch;
    scanf("%d", &ch);
    tower(ch, 'A', 'C', 'B');

    return 0;
}