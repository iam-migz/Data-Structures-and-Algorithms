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
    int sample[] = {1,2,3,4,5};
    populate_stack(&S, sample, 5);
    
    display_and_delete_all(&S);


    return 0;
}