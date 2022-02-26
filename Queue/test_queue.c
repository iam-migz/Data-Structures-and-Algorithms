#include <stdio.h>

#include "./Array/queue_array_v1.h"
#include "../Utils/array.h"


int main () {

    Queue q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(q.array, 10);

    return 0;
}