#ifndef QUEUE_H
#define QUEUE_H


#define SIZE 10
typedef struct {
    int array[SIZE];
    int front;
    int back;
    int count;
} Queue;

void queue_init(Queue *q);

int queue_is_full(Queue q);

int queue_is_empty(Queue q);

void queue_enqueue(Queue *q, int data);

int queue_front(Queue q);

int queue_dequeue(Queue *q);


#endif