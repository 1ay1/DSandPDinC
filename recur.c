#include <stdio.h>
#include <stdlib.h>

#define MAXITEMS 10

struct queue
{
    int front, rear;
    int items[MAXITEMS];
};

int is_empty(struct queue *qu) {
    return(qu->rear == qu->front );
}

int is_full(struct queue *qu) {
    return ((((qu->rear) + 1) % MAXITEMS) == qu->front);
}

struct queue * init_queue() {
    struct queue * qu = malloc(sizeof(struct queue));
    qu->front = 0;
    qu->rear = 0;
    return qu;
}

void insert ( struct queue * qu, int item) {
    if(is_full(qu)) {
        return;
    }

    if(is_empty(qu)) {
        qu->items[qu->rear] = item;
        qu->rear = (qu->rear + 1) % MAXITEMS;
        return;
    } 

    for(int i = qu->front; i != qu->rear; i = (i +1)%MAXITEMS) {
        if(item < qu->items[i]) {
            for(int j = qu->rear; j != i; j = (j - 1) %MAXITEMS) {
                qu->items[j] = qu->items[(j-1)%MAXITEMS];
            }
            qu->items[i] = item;
            qu->rear = (qu->rear + 1) % MAXITEMS;
            return;
        }
    }

    qu->items[qu->rear] = item;
    qu->rear = (qu->rear + 1)% MAXITEMS;

    /* (qu->rear++);
    qu->rear = qu->rear % MAXITEMS;
    qu->items[qu->rear] = item; */
}

int removeq (struct queue *qu) {
    if(is_empty(qu)) {
        return EXIT_FAILURE;
    }
    
    int val = qu->items[qu->front];
    qu->front = (qu->front + 1)%MAXITEMS;
    return val;
} 

int main() {
    struct queue *qu = init_queue();

    int i;
    int item;
    while(1) {
        puts("1 for removing, 2 for inserting");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            if(is_empty(qu)) {
                puts("Queue is empty, try inserting first!");
                puts("----------------------------------------");
                continue;
            }
            printf("Removed %d\n", removeq(qu));

                puts("----------------------------------------");
            break;

        case 2:
            if(is_full(qu)) {
                puts("Queue is full, try removing some item!");

                puts("----------------------------------------");
                continue;
            }
            puts("Enter the number to insert!");
            scanf("%d", &item);
            insert(qu, item);
            puts("Item Inserted!");       
            
                puts("----------------------------------------"); 
        default:
            break;
        }
    }

    return 0;
}