#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

/*
typedef struct node{
    int data;
    struct node *next;
} NodeType, *Stack;
*/


int main() {

    Stack S;
    init_stack(&S);
    int sample[] = {10,8,6,4,2};
    populate_stack(&S, sample, 5);

    display_and_delete_all(&S);
    return 0;
}