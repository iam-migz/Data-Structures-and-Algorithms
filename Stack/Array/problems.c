#include <stdio.h>
#include "stack_array.h"

/*
#define MAX 10
typedef struct {
    int data[MAX];
    int top;
} Stack;
*/


int main() {

    Stack S;
    init_stack(&S);
    int sample[] = {1,2,3,4,5};
    populate_stack(&S, sample, 5);

    display_and_delete_all(&S);
    
    return 0;
}