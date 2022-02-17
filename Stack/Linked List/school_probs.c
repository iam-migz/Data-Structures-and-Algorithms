#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

/*
typedef struct node{
    int data;
    struct node *next;
} NodeType, *Stack;
*/

void insert_bottom(Stack *S, int data) {
    Stack temp, new_stack;
    new_stack = NULL;

    while (*S != NULL) {
        temp = *S;
        *S = (*S)->next;
        temp->next = new_stack;
        new_stack = temp; 
    }
    temp = (Stack)malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = *S;
        *S = temp;
    }
    while (new_stack != NULL) {
        temp = new_stack;
        new_stack = new_stack->next;
        temp->next = *S;
        *S = temp;
    }
}

void insert_sorted(Stack *S, int data) {
    Stack temp, new_stack;
    new_stack = NULL;

    while (*S != NULL && data > (*S)->data) {
        temp = *S;
        *S = (*S)->next;
        temp->next = new_stack;
        new_stack = temp;
    }
    if (*S == NULL || (*S)->data != data) {
        temp = (Stack)malloc(sizeof(NodeType));
        if (temp != NULL) {
            temp->data = data;
            temp->next = *S;
            *S = temp;
        }
    }
    while (new_stack != NULL) {
        temp = new_stack;
        new_stack = new_stack->next;
        temp->next = *S;
        *S = temp;
    }

}

void delete_sorted(Stack *S, int data) {
    Stack temp, new_stack;
    new_stack = NULL;

    while (*S != NULL && data > (*S)->data) {
        temp = *S;
        *S = temp->next;
        temp->next = new_stack;
        new_stack = temp;
    }
    if (*S != NULL && data == (*S)->data) {
        temp = *S;
        *S = temp->next;
        free(temp);
    }
    while (new_stack != NULL) {
        temp = new_stack;
        new_stack = temp->next;
        temp->next = *S;
        *S = temp;
    }
}

int main() {

    Stack S;
    init_stack(&S);
    int sample[] = {10,8,6,4,2};
    populate_stack(&S, sample, 5);
    // insert_bottom(&S, 5);
    insert_sorted(&S, 11);
    delete_sorted(&S, 11);
    delete_sorted(&S, 6);
    delete_sorted(&S, 2);
    delete_sorted(&S, 4);
    delete_sorted(&S, 10);

    display_and_delete_all(&S);


    return 0;
}