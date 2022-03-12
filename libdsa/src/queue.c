#include "../inc/queue.h"

void queue_init(Queue *q) {
    q->front = 0;
    q->back = SIZE-1;
}

int queue_is_full(Queue q) {
    return (q.back+2)%SIZE == q.front;
}

int queue_is_empty(Queue q) {
    return (q.back+1)%SIZE == q.front;
}

void queue_enqueue(Queue *q, int data) {
    if ((q->back+2)%SIZE != q->front) {
        q->back = (q->back + 1) % SIZE;
        q->array[q->back] = data;
    }
}

void queue_dequeue(Queue *q) {
    if ((q->back+1)%SIZE != q->front) {
        q->front = (q->front + 1) % SIZE;
    }
}

int queue_front(Queue q) {
    return (q.back+1)%SIZE != q.front ? q.array[q.front] : -1;
}