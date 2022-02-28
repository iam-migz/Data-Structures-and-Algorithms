#include "../../Utils/cursorbased.h"

#ifndef QUEUE_CB_H
#define QUEUE_CB_H

typedef struct {
    Vheap vh;
    int front;
    int back;
} Queue;

void init_queue(Queue *q) {
    cb_init(&q->vh);
    q->front = -1;
    q->back = -1;
}

int isFull(Queue q) {
    return q.vh.avail == -1 ? 1: 0;
}

int isEmpty(Queue q) {
    return q.front == -1 ? 1: 0;
}

int peek(Queue q) {
    return q.front != -1 ? q.vh.elements[q.front].elem : -1;
}

void enqueue(Queue *q, int data) {
    if (!isFull(*q)) {
        int temp = cb_allocate_space(&q->vh);
        q->vh.elements[temp].elem = data;
        q->vh.elements[temp].next = -1;

        if (q->front == -1) {
            q->front = temp;
        } else {
            q->vh.elements[q->back].next = temp;
        }
        q->back = temp;
    }   
}

int dequeue(Queue *q) {
    if(!isEmpty(*q)) {
        int temp = q->front;
        q->front = q->vh.elements[temp].next;
        cb_deallocate_space(&q->vh, temp);
        if (q->front == -1) {
            q->back = -1;
        }
    }
}

int 


#endif