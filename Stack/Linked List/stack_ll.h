#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST

typedef struct node{
    int data;
    struct node *next;
} NodeType, *Stack;


void init_stack(Stack *S) {
    *S = NULL;
}

void push(Stack *S, int data) {
    Stack temp = (Stack)malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = *S;
        *S = temp;
    }
}

void pop(Stack *S) {
    if (*S != NULL) {
        Stack temp = *S;
        *S = (*S)->next;
        free(temp);
    }
}

int top(Stack S) { 
    return S != NULL ? S->data : -1;
}

void populate_stack(Stack *S, int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        push(S, array[i]);
    }
}

void display_and_delete_all(Stack *S) {
    while (*S != NULL) {
        printf("%d, ", top(*S));
        pop(S);
    }
}




#endif