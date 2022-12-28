#define QUEUE_SIZE 10

//kuyruk boyutu belirlenip gerekli tanımlamalar yapildi.

typedef struct{
    int front;
    int rear;
    int cnt;
    int data[QUEUE_SIZE];
}queue;

void initialize(queue *q) {
    q->cnt = 0;
    q->rear = -1; //ilk olarak bir arttırılıp ardından işleme alinacagi icin.
    q->cnt = 0;
}

boolean doluMu(queue *q) {
    return(q->cnt == QUEUE_SIZE);
}

void enqueu(queue *q, int x){
    if(doluMu(q)){
        q->rear++;
        q->cnt++;

        if(q->rear==QUEUE_SIZE)
            q->rear=0;
        q->data[q->rear] = x; //dizide tasma olmasin diye eger son indise gelindiyse rear tekrardan 0'a set ediliyor.
    }
}

void dequeue(queue *q,){
    if(!bosMu(q)) {
        struct node *temp = q ->front;
        int x = temp->data; //Silmeden once dondurulmesi gereken veriler tutuluyor.
        q->front = temp->next;
        free(temp); //Daha önce front’un gösterdiği adres belleğe geri veriliyor.
        q->cnt--;
        return x; //Cikarilan elemanin data degeriyle cagrildigi yere geri donuyor.
    }
}
