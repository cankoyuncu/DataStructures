#include <stdio.h>
#include <stdlib.h>

typedef struct n node; //typedef old-name new-name;

struct n{
	int x;
	struct n *next;
};

int main(){
	
	node *root;
	
	root = (node *)malloc(sizeof(node));
	root -> x = 10;
	
	root -> next = (node *)malloc(sizeof(node));
	root -> next -> x = 20;
	
	root -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> x = 30;
	
	root -> next -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> next -> x = 40;
	
	root -> next -> next -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> next -> next -> x = 90;
	
	node *iter;
	iter = root;
	printf("%d\t",iter->x);
	
	iter = iter -> next;
	printf("%d\t",iter->x);
	
	iter = iter -> next;
	printf("%d\t",iter->x);
	
	iter = iter -> next;
	printf("%d\t",iter->x);
	
	iter = iter -> next;
	printf("%d",iter->x);
	
}

