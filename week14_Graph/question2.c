#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int outDegree(struct node *head[], int V){
    int result = 0;
    struct node *temp = head[V]->next;
    while(temp!=NULL){
        result++;
        temp=temp->next;
    }
    return result;
}

// int inDegree(struct node *head[], int V){
//     int result = 0;
//     struct node *temp = head[V]->next;
//     while(temp!=NULL){
//         result++;
//         temp=temp->next;
//     }
//     return result;
// }

struct node *addEdge(struct node *head, int x){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else {
		struct node *last=head;
		while(last->next!=NULL)
			last=last->next;
		last->next=temp;
	}
	return head;
}

void print(struct node *heads[]){
    int i;
    for(i=0;i<5;i++){
        struct node *temp=heads[i];
        while(temp!=NULL){
            printf("%4d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    int i;
    int n = 5;

    struct node* heads[5]={NULL};
    heads[0]=addEdge(heads[0],1);
    heads[0]=addEdge(heads[0],2);

    heads[1]=addEdge(heads[1],2);
    heads[1]=addEdge(heads[1],4);

    heads[2]=addEdge(heads[2],3);
    heads[2]=addEdge(heads[2],1);
    heads[2]=addEdge(heads[2],4);
    heads[2]=addEdge(heads[2],5);

    heads[3]=addEdge(heads[3],4);
    heads[3]=addEdge(heads[3],1);
    heads[3]=addEdge(heads[3],3);
    heads[3]=addEdge(heads[3],5);

    heads[4]=addEdge(heads[4],5);
    
    print(heads);

    for(i=0;i<n;i++){
        printf("Out-Degree %d = %d\n", i+1, outDegree(heads,i));
    }
    
}