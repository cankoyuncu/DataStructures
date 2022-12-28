void concatenate(struct node*& list_1, node* list_2) { // parametrelere dikkat
    if(list_l == NULL)
        list_1 = list_2;
    else
        last(list_l) -> next = list_2; // last isimli fonksiyona çağrı yapılıyor
}