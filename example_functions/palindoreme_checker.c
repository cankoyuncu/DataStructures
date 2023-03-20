//Assume that you have a linear singly linked list and the values in the list are sorted in ascending order.
//Write  a function to insert a given value into the list so that the order will not be changed.

//Integer tipinden degerlerin kucukten buyuge dogru sirali oldugu tek yonlu bir bagli listenin oldugunu varsayalım.
//Buna gore parametre olarak eklenecek sayı ve bagli listenin baslangic adresinin geldigi ve gelen bu sayiyi siralamayi 
//bozmayacak sekilde bagli listeye ekleyen bir fonk yaziniz.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* next;
    struct node* prev;
} node;

int isPalindrome(node* head) {
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* secondHalf = NULL;
    if (fast != NULL) {
        // Odd number of elements
        secondHalf = slow->next;
        slow->next = NULL;
    } else {
        // Even number of elements
        secondHalf = slow;
    }

    // Reverse the second half of the list
    node* current = secondHalf;
    node* prev = NULL;
    node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    secondHalf = prev;

    // Compare the first and second half of the list
    node* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return 0;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;
}

