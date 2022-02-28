#include <stdio.h>

// #include "./Array/queue_array_v1.h"
// #include "./Array/queue_array_v2.h"
// #include "./Linked List/queue_ll.h"
// #include "../Utils/array.h"
#include "./Cursor Based/queue_cb.h"

int main() {

    Queue q;
    init_queue(&q);
    // initialize_array(q.array, 10);

    enqueue(&q, 1);
    dequeue(&q);
    enqueue(&q, 2);
    enqueue(&q, 3);
    dequeue(&q);
    enqueue(&q, 4);
    printf("%d ", peek(q)); // 3
    dequeue(&q);
    printf("%d ", peek(q)); // 4
    // 3 4
    // visualize_array(q.array, 10);
    // display_array_list(q.array, q.front, q.back);
    // printf("Q Front: %d\t", q.front);
    // printf("Q Back: %d\n", q.back);
    return 0;
} 