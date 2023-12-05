#include<stdio.h>
#include<math.h>

#define  MATRIX_BOYUTU 5

float determinant(float matrix[MATRIX_BOYUTU][MATRIX_BOYUTU], int size){
    int c;
    float det=0,s=1;
    float b[MATRIX_BOYUTU][MATRIX_BOYUTU];
    int i,j;
    int m,n;
    if(size == 1){
        return (matrix[0][0]);
    }

    else{
        det=0;
        for(c=0; c<size; c++){
            m=0;
            n=0;
            for(i=0; i<size; i++){
                for(j=0; j<size; j++){
                    b[i][j] = 0;
                    if(i!=0 && j !=c ){
                        b[m][n] = matrix[i][j];
                        if(n<(size-2)){
                            n++;
                        }
                        ,
                        else{
                            n=0;
                            m++;
                        }
                    }
                }
            }
            det = det + s*(matrix[0][c]*determinant(b,size-1));
            s = -1*s;
        }
    }
    return (det);
}

int main(){
    int n = MATRIX_BOYUTU;
    float matrix[MATRIX_BOYUTU][MATRIX_BOYUTU] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    float result = determinant(matrix, n);
    printf("Matrisin determinanti: %f", result);

    return 0;
}
