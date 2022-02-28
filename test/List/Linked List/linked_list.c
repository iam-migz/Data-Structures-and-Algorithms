#include <stdio.h>
#include <stdlib.h>
#include "../../Utils/linkedlist.h"

/*
typedef struct node {
    int data;
    struct node *next; 
} NodeType, *NodePtr;
*/

void insert_first(NodePtr *L, int data) {
    NodePtr temp = malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = *L;
        *L = temp;
    }
}
void insert_last(NodePtr *L, int data) {
    for (;*L != NULL; L = &(*L)->next) {}
    *L = malloc(sizeof(NodeType));
    if (*L != NULL) {
        (*L)->data = data;
        (*L)->next = NULL;
    } 
}
void insert_after(NodePtr *L, int data, int after) {
    for (;*L != NULL && (*L)->data != after; L = &(*L)->next) {}
    NodePtr temp = malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = (*L)->next;
        (*L)->next = temp;
    }
}
void insert_before(NodePtr *L, int data, int before) {
    for (;*L != NULL && (*L)->data != before; L = &(*L)->next) {}
    NodePtr temp = malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = *L;
        *L = temp;
    }
}
void insert_sorted(NodePtr *L, int data) { /* Ascending */
    for (;*L != NULL && data > (*L)->data; L = &(*L)->next) {}
    NodePtr temp = malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = *L;
        *L = temp;
    }
}
void delete(NodePtr *L, int data) {
    for (;*L != NULL && (*L)->data != data; L = &(*L)->next){}
    if (*L != NULL) {
        NodePtr temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

int main() {

    return 0;
}