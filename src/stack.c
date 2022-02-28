#include <stdio.h>
#include "../inc/stack.h"

void stack_init(Stack *S) {
    S->top = -1;
}

int stack_top(Stack S) {
    return S.top == -1 ? -1 : S.data[S.top];  
}

void stack_push(Stack *S, int data) {
    if (S->top < MAX-1) {
        ++S->top;
        S->data[S->top] = data;
    }
}

void stack_pop(Stack *S) {
    if (S->top != -1) {
        --S->top;
    }
}

int stack_is_empty(Stack S) {
    return S.top == -1;
}

void populate_stack(Stack *S, int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        stack_push(S, array[i]);
    }
}
