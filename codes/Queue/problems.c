#include <stdio.h>
#include "queue.h"

// in place
void insert_sorted_v1(Queue *q, int data) {
    if (queue_is_empty(*q) == 0) {
        int new_front = q->back+1;
        while (q->front != new_front && data > queue_front(*q)) {
            queue_enqueue(q, queue_front(*q));
            queue_dequeue(q);
        }
        queue_enqueue(q, data);
        while (q->front != new_front) {
            queue_enqueue(q, queue_front(*q));
            queue_dequeue(q);
            printf("head: %d, tail: %d\n", q->front, q->back);
        }
    }
}

// using another queue 
Queue insert_sorted_v2(Queue *q, int data) {
    Queue temp_queue;
    queue_init(&temp_queue);
    int temp_data = queue_front(*q);
    while (queue_is_empty(*q) == 0 && data > temp_data) {
        queue_enqueue(&temp_queue, temp_data);
        queue_dequeue(q);
        temp_data = queue_front(*q);
    }
    queue_enqueue(&temp_queue, data);
    while (queue_is_empty(*q) == 0) {
        queue_enqueue(&temp_queue, temp_data);
        queue_dequeue(q);
        temp_data = queue_front(*q);
    }
    return temp_queue;
}


int main () { 

    Queue q; 
    queue_init(&q);
    
    queue_enqueue(&q, 2);
    queue_enqueue(&q, 4);
    queue_enqueue(&q, 6);
    queue_enqueue(&q, 8);
    queue_enqueue(&q, 10);

    // insert_sorted(&q, 5);
    Queue new_queue = insert_sorted_v2(&q, 5);

    while (queue_is_empty(new_queue) == 0) {
        printf("%d ", queue_front(new_queue));
        queue_dequeue(&new_queue);
    }
    return 0;
}