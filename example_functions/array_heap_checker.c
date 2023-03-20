//write a function to check if a given array is a min heap or not. The prototype of the function is as follows

//Verilen bir dizinin min heap olup olmadıgini belirleyen bir fonk yaziniz. 

int isMintleap(int A[], int size){
        int i;
        for(i=1; i<size; i++){
            if(2*i<size && A[i] > A[2*i])
                return 0;
            if(2*i+1<size && A[i] > A[2*i+1])
                return 0;
        }
        return 1;
}