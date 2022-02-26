#include <stdio.h>

#include "./Array/queue_array_v1.h"
#include "../Utils/array.h"


int main () {

    Queue q;
    init_queue(&q);
    initialize_array(q.array, 10);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    visualize_array(q.array, 10);
    display_array_list(q.array, 10, q.front, q.back);

    return 0;
}