struct node *addlist(){
	struct node *temp = (struct node *)malloc(size of (Struct node))
	temp->data=x
	temp->next=NULL
	if(head==NULL)
		head=temp;
	else {
		struct node *last=head;
		while(last->next!=NULL)
			last=last->next;
		last->next=temp;
	}
	return head;
}
