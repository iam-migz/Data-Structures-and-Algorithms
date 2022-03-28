#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define SIZE 7

// implement load factor
// load factor = number of entries/total size of arrays
// lf = 0, empty
// lf = 1, full
// lf = .75, ideal 

// typedef struct node{
//     int data;
//     struct node *next;
// } *NodePtr;

typedef NodePtr Dict[SIZE];

void init_Dict(Dict D) {
    int i;
    for (i = 0; i < SIZE; i++) {
        D[i] = NULL;
    }
}

int hash_func(int num) {
    return (num * 32) % SIZE;  
}

void insert(Dict D, int num) {
    NodePtr *trav;
    int hash;

    hash = hash_func(num);
    for (trav = &D[hash]; *trav != NULL && (*trav)->data != num; trav = &(*trav)->next) {}
    if (*trav == NULL) { // make sure data to insert is unique, follow set properties.
        *trav = (NodePtr)calloc(1, sizeof(NodeType));
        if (*trav != NULL) {
            (*trav)->data = num;
        }
    }
}

void delete(Dict D, int num) {
    NodePtr *trav, temp;
    int hash;

    hash = hash_func(num);
    for (trav = &D[hash]; *trav != NULL && (*trav)->data != num; trav = &(*trav)->next) {}
    if (*trav != NULL) { 
        temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}

int member(Dict D, int num) {
    int hash = hash_func(num);
    NodePtr trav = D[hash];

    while (trav != NULL) {
        if (trav->data == num) {
            return 1;
        }
        trav = trav->next;
    }
    return 0;
}

void display(Dict D) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d: ",i);
        if (D[i] != NULL) {
            ll_display(D[i]);
        } else {
            printf("NULL\n");
        }
    }
}

void make_null(Dict D) {
    NodePtr trav,temp;
    int i;
    for (i = 0; i < SIZE; i++) {
        trav = D[i];
        while (trav != NULL) {
            temp = trav;
            trav = trav->next;
            free(temp);
        }
        D[i] = NULL;
    }
}

int main () {

    Dict D;
    init_Dict(D);
    insert(D, 2);
    insert(D, 3);
    insert(D, 1);
    insert(D, 13);
    insert(D, 15);

    delete(D, 15);
    display(D);
    printf("Is 15 a Member? %s\n", member(D, 15) == 1 ? "YES" : "NO");

    make_null(D);
    return 0;
}