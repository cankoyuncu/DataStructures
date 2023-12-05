#include<stdio.h>
#include<math.h>

#define  MATRIX_BOYUTU 5

float determinant(float matrix[MATRIX_BOYUTU][MATRIX_BOYUTU], int size){
    int c; //sutunlar uzerinde rekursif icin c 
    float det=0,s=1; //isaret carpani s
    float b[MATRIX_BOYUTU][MATRIX_BOYUTU]; //alt matris b 
    int i,j;
    int m,n; //altmatris indisleri icin m ve n 
    if(size == 1){
        return (matrix[0][0]); // burada matrisim 1x1 boyutuna geldiyse matrisim tek elemanlı demektir ve fonksiyon bu degeri dondurur.
    }

    else{ //buraya giren her matrise rekursif uygulanir.  
        det=0;
        for(c=0; c<size; c++){
            //matrisin her sutunu c degiskeni ile yinelenir.
            m=0;
            n=0;
            for(i=0; i<size; i++){

                for(j=0; j<size; j++){

                    //mevcut sutun ve ilk satır haric tutularak alt matrisimiz b olusturulur.
                    b[i][j] = 0;
                    if(i!=0 && j !=c ){ //ilgili eleman ilk satırda mı ve c sutununda mı kontrolu
                        b[m][n] = matrix[i][j];
                        if(n<(size-2)){ //n sutununun indeksinin artmasi ilk boyut ve 1-1 b alt matrisine dahil edilmesini saglar
                            n++;
                        }
                        else{ //b alt matrisinin bir sonraki satira gecmesini saglar
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
        {1, 2, 3, 4, 1},
        {0, -1, 2, 4, 2},
        {0, 0, 4, 0, 0},
        {-3, -6, -9, -12, 4},
        {0, 0, 1, 1, 1}
    };
    //Determinant daha sonra determinant fonksiyonu kullanılarak hesaplanır 
    //ve sonuc yazdırılır.
    float result = determinant(matrix, n);
    printf("Matrisin determinanti: %f", result);

    return 0;
}
