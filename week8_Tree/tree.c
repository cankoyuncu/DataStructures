#include <stdio.h>
#include <stdlib.h>

//leaf sayisini dugumlerin toplamini bulan fonk

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

int find_depth(BTREE *root, int data){
	if(root==NULL){
		printf("there is no %d\n",data);
		return -1000;
	}
	if(roo->data==data) //bu durumda kok dugumun derinligi 0'dir.
		return 0;
	else if(data < root->data)
		return 1+ find_depth(root->left,data);
	else 
		return 1+ find_depth(root->right,data);
	
	
}

//agacin yuksekligini bulan fonk

int tree_height(BTREE *root){
	if(!root)
		return -1;
	else{
		left_height=tree_height(root->left);
		right_height=tree_height(root->right);
		
		if(left_height > right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
}

int main(){
	BTREE *myroot = new_node(10);
	myroot = insert(myroot,8);
	myroot = insert(myroot,3);
	myroot = insert(myroot,6);
	myroot = insert(myroot,15);
	myroot = insert(myroot,7);
	myroot = insert(myroot,16);
	myroot = insert(myroot,1);
	myroot = insert(myroot,5);
	
	printf("Leaf count on tree: %d\n",leafCount(myroot));
	
	
}





