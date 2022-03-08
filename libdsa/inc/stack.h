#ifndef STACK_H
#define STACK_H

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
}Stack;

void stack_init(Stack *S);

int stack_top(Stack S);

void stack_push(Stack *S, int data);

void stack_pop(Stack *S);

int stack_is_empty(Stack S);

void stack_populate(Stack *S, int array[], int array_size);

void stack_display(Stack S);

#endif