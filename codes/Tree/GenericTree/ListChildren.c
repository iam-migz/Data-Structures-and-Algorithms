#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define MAX 10 

typedef struct {
    NodePtr data[MAX];
    int root;
} Tree;

// Utils
void init_tree(Tree *T) {
    for (int i = 0; i < MAX; i++) 
        T->data[i] = NULL;
}
// ADT
int parent(Tree T, int node) { // ~ O(N), linear time
    for(int i = 0; i < MAX; i++) {
        for (NodePtr trav = T.data[i]; trav != NULL; trav = trav->next) {
            if (trav->data == node) {
                return i;
            }
        }      
    }
    return -1;
}
void children_print(Tree T, int root) { // ~ O(1), constant time
    for (NodePtr trav = T.data[root]; trav != NULL; trav = trav->next) {
        printf("%d ", trav->data);
    }  
}
int rightmost(Tree T, int root) { // ?? ~ O(#elems)
    NodePtr trav;
    for (trav = T.data[root]; trav->next != NULL; trav = trav->next) {}
    if (T.data[trav->data] == NULL) {
        return trav->data;
    }
    return rightmost(T, trav->data);
}

void preorder(Tree T, int root) { // ? ~ O(#elems)
    printf("%d ", root);
    for (NodePtr trav = T.data[root]; trav != NULL; trav = trav->next) {
        preorder(T, trav->data);
    }
}
int main() {

    Tree T;
    init_tree(&T);
    T.root = 5;

    ll_populate_list(&T.data[1], (int[]){4, 7}, 2);
    ll_populate_list(&T.data[2], (int[]){8}, 1);
    ll_populate_list(&T.data[5], (int[]){0, 6, 2}, 3);
    ll_populate_list(&T.data[6], (int[]){3, 1}, 2);

    preorder(T, T.root);
    printf("\nThe rightmost element: %d", rightmost(T, T.root));
    ll_make_null(&T.data[1]);
    ll_make_null(&T.data[2]);
    ll_make_null(&T.data[5]);
    ll_make_null(&T.data[6]);

    printf("\n");
    for (int i = 0; i < MAX; i++) 
        if (T.data[i] == NULL) 
            printf("[%d]: NULL\n", i);

    return 0;
}