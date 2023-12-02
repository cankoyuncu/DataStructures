#include <stdio.h>
#include <stdlib.h>

typedef struct n node; //typedef old-name new-name;

struct n{
	int x;
	struct n *next;
};
void print(node *r){
	while(r!=NULL){
		printf("%d ",r->x);
		r = r->next;
	}
}

int main(){
	
	node *root;
	
	root = (node *)malloc(sizeof(node));
	root -> x = 50;
	
	root -> next = (node *)malloc(sizeof(node));
	root -> next -> x = 40;
	
	root -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> x = 30;
	root -> next -> next -> next = NULL;
	
	node *iter;
	iter = root;
	printf("%d\t",iter->x);
	
	iter = iter -> next;
	printf("%d\t",iter->x);
	
	iter = iter -> next;
	printf("%d\t\n",iter->x);
	
	iter=root;
	int i = 0;
	while(iter != NULL){
		i++;
		printf("\n%d. eleman: %d\n",i,iter->x);
		iter = iter -> next;
	}
	iter = root->next->next;
	
	for(i=0;i<10;i++){
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
		iter->x = i*10;
		iter->next = NULL;
	}
	print(root);
}

