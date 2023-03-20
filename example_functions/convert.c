//Write a function that converts a given min heap to a max heap. If you use any other functions which is not pre..ed in the class, you need to write it explictly. The protoype of the function is queue *convert(queue *q)

queue *convert(queue *q){
    int size = q->size;
    for (int i = size/2 - 1; i >= 0; i--)
        heapify(q->arr, size, i);
    return q;
}

void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
