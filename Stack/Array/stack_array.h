#ifndef STACK_ARRAY
#define STACK_ARRAY

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
}Stack;

void init_stack(Stack *S) {
    S->top = -1;
}

int top(Stack S) {
    return S.top != -1 ? S.data[S.top] : -1;  
}

void push(Stack *S, int data) {
    if (S->top < MAX-1) {
        ++S->top;
        S->data[S->top] = data;
    }
}

void pop(Stack *S) {
    if (S->top != -1) {
        --S->top;
    }
}

void display_and_delete(Stack *S) {
    while (S->top != -1) {
        printf("%d ", top(*S));
        pop(S);
    } 
}

void populate_stack(Stack *S, int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        push(S, array[i]);
    }
}

#endif