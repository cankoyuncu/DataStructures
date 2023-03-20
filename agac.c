#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BTREE;

void inorder(BTREE*a){
    if(a != NULL){
        inorder(a->left);
        printf("%d ", a->data);
        inorder(a->right);
    }
}

BTREE *new_node(int x){
    BTREE *temp = (BTREE*)malloc(sizeof(BTREE));
    temp -> data = x;
    temp -> left = temp -> right = NULL;
    return temp;
}

BTREE *insert(BTREE *root, int x){
    if(root != NULL){
        if(x < root->data){
            root->left = insert(root->left, x);
        }
        else
            root->right = insert(root->right ,x);
    }
    else
        root = new_node(x);
    return root;    
    
}

int main(){
    BTREE *root = NULL;
    int x;
    printf("Deger giriniz: ");
    scanf("%d", &x);

    while(x != -1){
        
        root = insert(root, x);
        printf("Deger giriniz: ");
        scanf("%d", &x);
    }
    inorder(root);
}