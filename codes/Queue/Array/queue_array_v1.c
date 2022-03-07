// A Circular Array using a count variable

#define SIZE 10
typedef struct {
    int array[SIZE];
    int front;
    int back;
    int count;
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->back = SIZE-1;
    q->count = 0;
}

int isFull(Queue q) {
    return q.count == SIZE-1 ? 1 : 0;
}

int isEmpty(Queue q) {
    return q.count == 0 ? 1 : 0;
}

void enqueue(Queue *q, int data) {
    if (!isFull(*q)) {
        q->back = (q->back + 1) % SIZE;
        q->count++;
        q->array[q->back] = data;
    }
}

int dequeue(Queue *q) {
    int temp = -1;
    if (!isEmpty(*q)) {
        q->array[q->front] = -1;
        temp = q->array[q->front];
        q->front = (q->front + 1) % SIZE;
    }
    return temp;
}

int main() {

    return 0;
}