#include <stdio.h>
#define QUEUE_SIZE 10

struct priority_queue{
    int A[QUEUE_SIZE+1];
    int cnt;
};
typedef struct priority_queue pqueue;
void initialize(pqueue *p){
    p->cnt=0;
}

void insert (pqueue *p, int key){
    if(p->cnt==QUEUE_SIZE)
        printf("Queue is full");
    else{
        p->cnt++;
        p->A[p->cnt]=key;
        int iter=p->cnt;
        while(iter!=1 && p->A[iter]<p->A[iter/2]){
            int temp = p->A[iter];
            p->A[iter]=p->A[iter/2];
            p->A[iter/2]=temp;
            iter = iter/2;
        }
    }
}

void print(pqueue *p){
    if(p->cnt==0)
        printf("Queue is empty");
    else{
        int i;
        for(i=1;i<=p->cnt;i++)
            printf("%5d", p->A[i]);
    }
}

void swap(int *p,int *q)
{
    int tmp;
    tmp = *p; 
    *p=*q;    
    *q=tmp;   
}

int delete(pqueue *p){
    if(p->cnt==0){    
        printf("Queue is empty");
        return -100;
    }else{
        int key = p->A[1];
        p->A[1]=p->A[p->cnt];
        p->cnt--;
        int iter = 1;
        while(2*iter<=p->cnt && (p->A[iter]>p->A[2*iter] || p->A[iter]>p->A[2*iter+1])){
            if(p->A[2*iter]<p->A[2*iter+1]){
                swap(&p->A[iter], & p->A[2,iter]);
                iter = 2*iter;
            }else{
                swap(&p->A[iter], & p->A[2*iter+1]);
                iter = 2*iter+1;
            }
        }
        return key;
    }
}

int main(){
    pqueue p;
    initialize(&p);
    insert(&p,3);
    insert(&p,6);
    insert(&p,15);
    insert(&p,42);
    insert(&p,4);
    insert(&p,34);
    insert(&p,9);
    insert(&p,23);
    delete(&p);
    delete(&p);
    delete(&p);
    print(&p);

}