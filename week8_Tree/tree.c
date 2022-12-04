#include <stdio.h>
#include <stdlib.h>

//leaf sayisini dugumlerin toplamini 
//agactaki herhangi bir dugumun depth 
//agacin yuksekligini

struct node{
	
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
