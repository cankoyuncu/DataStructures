// Komsuluk listesi ile temsil edilen yonsuz bir grafta verilen iki dugumun arasında ayrit varsa true, 
// yoksa false yazan bir fonksiyon yaziniz.

int edge(struct node *heads[], int u, int v){
    struct node *temp = heads[u];
    while(temp != NULL){
        if(temp->data == v)
            return 1;
        temp = temp->next;
    }
    return 0;
}
