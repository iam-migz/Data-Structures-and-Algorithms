#include "../inc/queue.h"

void queue_init(Queue *q) {
    q->front = 0;
    q->back = SIZE-1;
    q->count = 0;
}

int queue_is_full(Queue q) {
    return q.count == SIZE-1;
}

int queue_is_empty(Queue q) {
    return q.count == 0;
}

void queue_enqueue(Queue *q, int data) {
    if (!queue_is_full(*q)) {
        q->back = (q->back + 1) % SIZE;
        q->count++;
        q->array[q->back] = data;
    }
}

int queue_dequeue(Queue *q) {
    int temp = -1;
    if (!queue_is_empty(*q)) {
        q->array[q->front] = -1;
        temp = q->array[q->front];
        q->front = (q->front + 1) % SIZE;
        q->count--;
    }
    return temp;
}

int queue_front(Queue q) {
    return q.count != 0 ? q.array[q.front] : -1;
}