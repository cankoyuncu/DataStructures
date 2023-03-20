//We suppose that an AVL tree. Complete the following function that performs right rotation. Note that height member of some nodes should be updated.

struct node *rightRotate(struct node *y){
    struct node *temp=head[u];
    while(temp->next!=NULL){
        if(temp->next->data==v)
        return 1;

        else
        temp=temp->next;
    }
    return 0;
    
}s