#include <stdio.h>

struct student
{
    char name[20];
    int number;
    float midterm;
    float final;
    double avarage;
    struct student *next;
};

typedef struct student node;




int main(){
    node *head=(node *) malloc(sizeof(node))
    
    
    return 0;
}