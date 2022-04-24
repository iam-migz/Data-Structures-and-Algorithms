#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define MAX 10

typedef struct {
    int parent;
    NodePtr child;
} Cell;

typedef struct {
    Cell data[MAX];
    int root;
} Tree;

// util functions
void init_tree(Tree *T) {
    for (int i = 0; i < MAX; i++) {
        T->data[i].parent = -1;
        T->data[i].child = NULL;
    }
    T->root = -1;
}
void populate_data(Tree *T) {
    T->root = 5;
    int parents[] = {5,6,5,6,1,-1,5,1,2,-1};
    for(int i = 0; i < MAX; i++) {
        T->data[i].parent = parents[i];
    }
    ll_populate_list(&T->data[1].child, (int[]){4, 7}, 2);
    ll_populate_list(&T->data[2].child, (int[]){8}, 1);
    ll_populate_list(&T->data[5].child, (int[]){0,6,2}, 3);
    ll_populate_list(&T->data[6].child, (int[]){3,1}, 2);
}   
void empty_tree(Tree *T) {
    for (int i = 0; i < MAX; i++) {
        if (T->data[i].child != NULL) {
            ll_make_null(&T->data[i].child);
        }
    }
}
void check_tree_empty(Tree T) {
    for (int i = 0; i < MAX; i++) 
        if (T.data[i].child == NULL) 
            printf("[%d]: NULL\n", i);
}
// ADT
void preorder(Tree T, int root) {
    printf("%d ", root);
    for (NodePtr trav = T.data[root].child; trav != NULL; trav=trav->next){
        preorder(T, trav->data);
    }
}

int main() {

    Tree T;
    init_tree(&T);
    populate_data(&T);
    preorder(T, T.root);
    printf("\n");
    empty_tree(&T);
    check_tree_empty(T);
    return 0;
}