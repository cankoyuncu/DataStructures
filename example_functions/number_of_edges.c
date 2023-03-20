//write a function that returns the total number of edges in a directed graph 
//with n vertices which is represented by adjency list.

//TR Komsuluk listesi ile temsil edilen n tepeli bir yönlü
//graftaki toplam ayrıt sayısnı döndüren fonksiyon.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

int countEdges(struct node* adjacency_list[], int n) {
    int i, count = 0;
    struct node* temp;

    for (i = 0; i < n; i++) {
        temp = adjacency_list[i];
        while (temp) {
            count++;
            temp = temp->next;
        }
    }

    return count;
}