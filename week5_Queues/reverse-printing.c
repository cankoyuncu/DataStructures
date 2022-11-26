#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 100
#define STACK_SIZE 100
#define QUEUE_SIZE 100

struct node {
    int data;
    int struct node *next; //program kendisi int ekledi.
};

typedef struct {
    struct node *top;
    int cnt;
}stack;

typedef struct {
    int cnt;
    struct node *front;
    struct node *rear;
}queue;

void initialize_stack(stack *stk){
    stk -> top = NULL;
    stk -> cnt = 0;
}

void initialize_queue(queue *q){
    q -> cnt = 0;
    q -> front = q->rear = NULL;
}

typedef enum {false, true}boolean;

boolean isEmpty_stack(stack *stk){
    return(stk->cnt==0);
}

boolean isFull_stack(stack *stk){
    return(stk->cnt == STACK_SIZE);
}

void push(stack *stk, int c) {
    if(!isFull_stack(stk)){
        struct node *temp = (struct node *)malloc(sizeof(struct node));

        temp->data = c;
        temp->next = stk -> top;
        stk->top = temp;
        stk->cnt++;
    }
    else
        printf("Stack Dolu\n");
}
int pop(stack *stk){
    if(!isEmpty_stack(*stk)) {
        struct node *temp = stk->top->next;
        int x = temp -> data;
        free(temp);
        stk -> cnt--;
        return x;
    }
}
int isEmpty_queue(queue *q) {
    return(q->cnt==0);
}