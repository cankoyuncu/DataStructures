// Write the function that converts a given binary tree to an AVL tree. 

// Parametre olarak verilen bir binary tree'yi AVL tree'ye donusturen fonk yaziniz.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int height;
    struct node* left;
    struct node* right;
};

int max(int a, int b) {
    return (a > b)? a : b;
}

int height(struct node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(struct node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* newNode(int key) {
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return node;
}

struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

struct node* insert(struct node* node, int key) {
    // Perform the normal BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left),
                           height(node->right));

    // Get the balance factor of this ancestor
    // node to check whether this node became
    // unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right
