#include <stdio.h>
#include "../../Utils/cursorbased.h"
#include "stack_cb.h"

/*
#define MAX 10
typedef struct {
    int elem;
    int next;
} Node;

typedef struct {
    Node elements[MAX];
    int avail;
} Vheap;
*/

int main() {

    Vheap vh;
    init(&vh);
    int myStack = -1;

    push(&vh, &myStack, 3);
    push(&vh, &myStack, 2);
    push(&vh, &myStack, 1);
    visualize(vh);

    display_and_delete_all(&vh, &myStack);




    return 0;
}