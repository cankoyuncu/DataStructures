#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node* next;	
};

void push(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;

	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void append(struct node** head_ref, int new_data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;

	struct node* last = *head_ref;
	new_node->next = NULL;

	if (*head_ref == NULL){
		*head_ref == new_node;
		return;
	}

	while (last->next != NULL){
		last = last->next;
	}

	last->next = new_node;
}

void printList(struct node* node){
	while (node != NULL){
		printf(" %d", node->data);
		node = node->next;
	}
}

int main(){
	struct node* head = NULL;

	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);

	printf("Created Linked List is: ");
	printList(head);

	append(&head,1);
	
	printf("\nAfter insterting 1 at the end: ");
	printList(head);

	return 0;
}
