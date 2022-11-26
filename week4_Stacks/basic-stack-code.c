#define STACK_SIZE 4
typedef struct {
    int data[STACK_SIZE];
    int top;
}stack;

//push fonksiyonu

void push(stack *stk, int c){
    if(stk -> top == STACK_SIZE - 1)
        printf("\nStack Dolu\n");
    else {
        stk -> top++;
        stl-> data[stk->top] = c;
    }
}

//reset fonksiyonu

void reset(stack *stk){
    stk -> top = -1;
}

//pop fonksiyonu

int pop(stack *stk) {
    if(stk->top==-1)
        printf("Stack bos");
    else {
        int x = stk -> top--;
        return x;
    }
}

//boolean ile enumaa gerek kalmadan dolu boş kontrolü yapılabiliyor.

boolean isEmpty(stack *stk) {
    return(stk->cnt==0);
}

//stakin dolu olup olmadığının kontrolü

boolean isFull(stack *stk) {
    return(stk->cnt == STACK_SIZE);
}

//stack'e ekleme yapan fonksiyon
void push(stack *stk, int c){
    if(!isFull(stk)) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp -> data = c;
        temp -> next = stk ->top;
        stk -> top = temp;
        stk -> cnt++;
    }
    else 
        printf("Stack Dolu!");
}