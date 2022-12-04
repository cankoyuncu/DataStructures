#include <stdio.h>
#include <stdlib.h>

//leaf sayisini dugumlerin toplamini 

//agacin yuksekligini

struct node{
	int data;
	struct node *left, *right;
};

typedef struct node BTREE;

//leaf sayisini

int leafCount(BTREE *node){
	if(node==NULL)
		return 0;
	else if(node->left==NULL && node->right==NULL)
		return 1;
	else 
		return leafCount(node->left)+leftCount(node->right)
}

BTREE *new_node(int data){
	BTREE *node = (BTREE*)malloc(sizeof(BTREE));
	node->data=data;
	node->left=node->right=NULL;
	return node;
}

BTREE *insert(BTREE *root, int data){
	if(root!=NULL){
		if(data<root->data)
			root->left = insert (root->left,data);
		else
			root->right = insert(root->right,data);
		
	}else //root yoksa, root==NULL ise sunlari yapariz
		root=new_node(10);
	return root;
}

int sumBTREE(BTREE *root){
	if(root=NULL)
		return 0;
	return (root->data + sumBTREE(root->left)+sumBTREE(root->right));
	
}

//agactaki herhangi bir dugumun derinligini hesaplamak

int find_depth()









