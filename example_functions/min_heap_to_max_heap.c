//Write a function that converts a given min heap which is implemented by arrays to a max heap.
//The prototype of the function is queue *convert(queue *q). 

//Dizi ile implemente edilmis bir min heap i max heap e donusturunuz.

queue* convert(queue* q) {
    int i;
    for (i = (q->size - 2) / 2; i >= 0; i--) {
        max_heapify(q, i);
    }
    return q;
}

void max_heapify(queue* q, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < q->size && q->elements[l] > q->elements[i]) {
        largest = l;
    }
    if (r < q->size && q->elements[r] > q->elements[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = q->elements[i];
        q->elements[i] = q->elements[largest];
        q->elements[largest] = temp;
        max_heapify(q, largest);
    }
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}
