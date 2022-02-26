#ifndef QUEUE_ARRAY_V2_H
#define QUEUE_ARRAY_V2_H

// A Circular Array without count
// Queue is empty if front is ahead by 1
// Queue is full if front is ahead by 2

#define SIZE 10
typedef struct {
    int array[SIZE];
    int front;
    int back;
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->back = SIZE-1;
}

int isFull(Queue q) {
    return (q.back + 2)%SIZE == q.front ? 1 : 0;
}

int isEmpty(Queue q) {
    return (q.back + 1)%SIZE == q.front ? 1 : 0;
}

void enqueue(Queue *q, int data) {
    if (!isFull(*q)) {
        q->back = (q->back + 1) % SIZE;
        q->array[q->back] = data;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(*q)) {
        q->front = (q->front + 1)  % SIZE;
    }
}


#endif