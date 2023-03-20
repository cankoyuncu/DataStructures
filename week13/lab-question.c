#include <stdio.h>
#include <time.h>

struct node{  //dugum yapısı
	int data;
	struct node *next;
};

void addFront(struct node **start_ref);

void bubbleSort(struct node *head);

void swap(struct node *a, struct node *b);

void printList(struct node *head);

int main(){
	int i;
	srand(time(NULL));
	
	struct node *head = NULL;   //liste boş
	
	//listeye 100 adet eleman eklenecek
	for (i = 0; i< 100; i++)
		addFront(&head);
		
	printf("\nListe siralanmadan once:");
	printList(head);
	
	bubbleSort(head); //lıste bubble sort ile sıralanır
	
	printf("\nListe siralandiktan sonra:");
	printList(head);
	
}

void addFront(struct node **start_ref)  
{
	int data = rand()%1000+1;      //1 ile 999 arasında rastgele sayı uretır
	struct node *yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = data;
	yeni->next = *start_ref;  //head
	*start_ref = yeni;
}

void printList(struct node *head)
{
	struct node *temp = head;  //listenin basından 
	printf("\n");
	while (temp!=NULL)    //listenin sonuna kadar  
	{
		printf("%d ", temp->data); //tüm elemanları yazdırsın
		temp = temp->next;
	}
}

void bubbleSort(struct node *head)
{
	int swapped, i;
	struct node *ptr1;
	struct node *ptr2 = NULL;

	if (head == NULL)  //lıste boşsa
		return;
	do
	{
		swapped = 0;    //swap kontrol
		ptr1 = head;

		while (ptr1->next != ptr2) //null degils
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);  //swap fonk git
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		ptr2 = ptr1; 
	}
	while (swapped);
}

void swap(struct node *a, struct node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}








