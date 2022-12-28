#include <stdio.h>
#include <stdlib.h>


//21.10.22
struct node{
	int data;
	struct node *next;
};

struct node *delete_func(struct node *head, int key){
	if(head==NULL){
		printf("list is empty");
		return NULL;
	}
	struct node *temp=head;
	if(head->data==key){
		head=head->next;
		head->prev=NULL;
		free(temp);
	}else{
		while(temp->next!=NULL && temp->next->data!=key){
			temp=temp->next;
		temp->prev->next=temp->next;
		if(temp->next!=NULL){
			temp->next->prev=temp->prev;
			
			
			struct node *deleted = temp->next;
			temp->next=deleted->next;
			free(deleted);
			
			}
		}
		return head;
	}
}


