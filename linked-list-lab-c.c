#include <stdio.h>
#include <stdlib.h>

struct student{
	int ogrenci_no;
	char isim[20];
	int vize;
	int final;
	struct student *next;
};

typedef struct student node;
node *head;

node *createList(){
	
	int o_sayi,sayac;
	node *p;
	printf("Listede kac ogrenci var?");
	scanf("%d",&o_sayi);
	
	for(sayac=0;sayac<o_sayi;sayac++){
		if(sayac==0){
			head = (node*)malloc(sizeof(node));
			p=head;
		}
		else{
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
		}
		
		printf("%d. ogrencinin numarasi: ", sayac+1);
		scanf("%d",&p->ogrenci_no);
		
		printf("%d. ogrencinin ismi: ", sayac+1);
		scanf("%s",&p->isim);
		
		printf("%d. ogrencinin vize notu: ", sayac+1);
		scanf("%d",&p->vize);
		
		printf("%d. ogrencinin final notu: ", sayac+1);
		scanf("%d", &p->final);
	}
	return head;
}

void print(node *head){
	if(head==NULL)
		printf("Liste BOS");
	else{
		node *p;
		p=head;
		while( p != NULL){
			printf("%d %s %d %d ",p->ogrenci_no, p->isim, p->vize, p->final);
			p = p->next;
		}
		
	}
}

int main(){
	createList();
	print(head);
	
	return 0;
}
