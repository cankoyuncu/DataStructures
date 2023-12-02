#include <stdio.h>
#include <stdlib.h>

typedef struct n node; //typedef old-name new-name;

struct n{
	int x;
	struct n *next;
};

void bastir(node *r){
	while(r!=NULL){
		printf("%d ",r->x);
		r = r->next;
	}
}
void ekle(node *r, int x){
	while(r->next!=NULL){
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}
int main(){
	
	node *root;
	root = (node*)malloc(sizeof(node));
	root -> next = NULL; //her zaman linked list'in son elemani null gostermeli.
	root -> x = 500;
	int i = 0;
	
	for(i=0;i<7;i++){
		ekle(root, i*10);
	}
	bastir(root);
}

