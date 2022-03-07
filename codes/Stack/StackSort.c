// Sorting a stack using a temp stack

#include <stdio.h>
#include "stack.h"

void sortStack(Stack *S) {
    Stack temp_stack;
    stack_init(&temp_stack);
    stack_push(&temp_stack, stack_top(*S));
    stack_pop(S);
    int orig_front, temp_front;
    while (stack_is_empty(*S) == 0) {
        orig_front = stack_top(*S);
        temp_front = stack_top(temp_stack);
        if (orig_front < temp_front) {
            stack_pop(S);
            while (stack_is_empty(temp_stack) == 0 && orig_front < temp_front) {
                stack_push(S, temp_front);
                stack_pop(&temp_stack);
                temp_front = stack_top(temp_stack);
            }
            stack_push(&temp_stack, orig_front);
        } else {
            stack_pop(S);
            stack_push(&temp_stack, orig_front);
        }
    }

    // restore stack
    while (stack_is_empty(temp_stack) == 0) {
        stack_push(S, stack_top(temp_stack));
        stack_pop(&temp_stack);
    }
}

int main() {

    Stack S;
    stack_init(&S);
    stack_push(&S, 2);
    stack_push(&S, 1);
    stack_push(&S, 5);
    stack_push(&S, 3);
    stack_push(&S, 4);
    sortStack(&S);

    stack_display(S);   


    return 0;
}