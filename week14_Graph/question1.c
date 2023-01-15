#include <stdio.h>

int degree(int A[5][5], int V, int n){
    int result = 0, i;
    for(i=0; i<n; i++)
        result += A[V][i];
    return result;
}

int edges(int A[5][5], int n){
    int result = 0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            result += A[i][j];
        } 
    }
   return result; 
}

int main(){

    int n = 5,i;
    int A[5][5] = {
        {0,1,1,1,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {1,1,1,0,1},
        {0,0,1,1,0},
    };

    int degree_sum = 0;
    for(i=0; i<n; i++){
        printf("Degree of vertex: %d = %d\n", i+1,degree(A,i,n));
        degree_sum += degree(A,i,n);   
    }
    printf("Total degree of vertices = %d\n", degree_sum);
    printf("Total number of edges = %d\n", edges(A, n));
}