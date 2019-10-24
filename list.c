#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node * next;
};

typedef struct node * NODEPTR;

NODEPTR getnode() {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}

void freenode(NODEPTR p) {
    free(p);
}

void insafter(NODEPTR p, int x) {
    NODEPTR q;
    if(p == NULL){
        puts("Void insertion!");
        return;
    }
    q = getnode();
    q->item = x;
    q->next = p->next;
    p->next = q;
}

void delafter(NODEPTR p, int *px){ //px will have the implicit return value 
    NODEPTR q;
    if((p == NULL) || (p->next == NULL)) {
        puts("Void deletion!");
        return;
    }

    q = p->next;
    *px = q->item;
    p->next = q->next;
    freenode(q);
}

struct queue {
    NODEPTR front, rear;
    int num;
};

int empty_queue(struct queue *pq) {
    return ((pq->front == NULL)? 1: 0);
}

void insert_node(struct queue *pq, int x) {
    NODEPTR p;
    p = getnode();
    p->item = x;
    p->next = NULL;
    if( pq->rear == NULL) {
        pq->front = p;
    }
    else {
        pq->rear->next = p;
    }
    pq->rear = p;
    pq->num++;
}

int remove_queue(struct queue * qp){
    if(empty_queue(qp)){
        puts("Queue Empty!");
        return EXIT_FAILURE;
    }

    NODEPTR p = qp->front;
    int x = p->item;
    qp->front = qp->front->next;
    if(qp->front == NULL) {
        qp->rear = NULL;
    }
    freenode(p);
    qp->num++;
    return x;
}

struct queue * init_queue() {
    struct queue * q = malloc(sizeof(struct queue));
    q->rear = NULL;
    q->front = NULL;
    q->num = 0;
    return q;
}

int main () {
    struct queue * q = init_queue();
    int ans;
    int x;
    while (1)
    {
            puts("1 for deleting, 2 for adding!");
                scanf("%d", &ans);

        switch (ans)
        {
        case 1:
            if(empty_queue(q)){
                puts("Queue is EMPTY");
                puts("====================================");
                break;
            }
            printf("%d Removed\n", remove_queue(q));
            puts("====================================");
            printf("Items remaining: %d\n---------------------------------\n", q->num );
            break;

        case 2:
            puts("Enter the number to insert!");
            puts("======================");
            scanf("%d", &x);
            insert_node(q, x);
            printf("%d added\n", x);
            printf("Items remaining: %d\n----------------------------------------\n", q->num);
            break;
        
        default:
            break;
        }
    }

    return 0;
    
}

