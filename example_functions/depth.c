//Write a function that finds the outdegree of a given vertex in a directed graph which is represented by adjaceny lists.

//Komsuluk listeleri ile temsil edilmis yonlu bir grafta verilen bir tepenin cikis derecesini bulan bir fonk yaz.

int depth(struct node *root, int d){
    if(root == NULL)
        return 0;
    if(d == 0)
        return root->data;
    return depth(root->left, d-1)+depth(root->right, d-1);
}