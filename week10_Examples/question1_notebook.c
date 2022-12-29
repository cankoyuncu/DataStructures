//Question: Write a function substract min that substructs thhe smallest node value from
//all nodes (including itselfs) in the linked list. Suppose the list stores the following elements.
//[8,4,7,2,9,4,5,3] 
//If you made the call of substract mih(head) the list would then store the elements:
//[6,2,5,0,7,2,3,1]

struct node *substractMin(struct node *head){
	if(head! = NULL){
		struct node *iter = head
		int min = head->data;
		iter=iter->next;
		while(iter!=NULL){
			if(min>iter->data)
				min=iter->data;
				iter=iter->next;
		}
		iter=head;
		while(iter!=NULL){
			iter->data=min;
			iter=iter->next;
		}
	}return head
}
