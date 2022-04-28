#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BST.h"

/*
typedef struct node {
    int elem;
    struct node *LC, *RC;
} NodeType, *BST;
*/

void insert(BST *B, int elem) {
    BST *trav;
    for (trav = B; *trav != NULL && (*trav)->elem != elem;) {
        trav = (*trav)->elem > elem ? &(*trav)->LC : &(*trav)->RC;
    }
    if (*trav == NULL) {
        *trav = calloc(1, sizeof(NodeType));
        if (*trav != NULL) {
            (*trav)->elem = elem;
        }
    }
}

// returns a pointer to pointer to node
BST* min_node(BST *B) {
    BST *trav;
    for (trav = B; (*trav)->LC != NULL; trav = &(*trav)->LC) {}
    return trav;
}

void delete(BST *B, int elem) {
    BST *trav, temp;
    for (trav = B; *trav != NULL && (*trav)->elem != elem;){
        trav = (*trav)->elem > elem ? &(*trav)->LC : &(*trav)->RC;
    }
    
    if (*trav != NULL) {
        if ((*trav)->LC == NULL) {
            temp = *trav;
            *trav = temp->RC;
        } else if ((*trav)->RC == NULL) {
            temp = *trav;
            *trav = temp->LC;
        } else {
            // for (trav2 = &(*trav)->RC; trav2 != NULL; trav2 = &(*trav2)->LC) {}
            // temp = *trav2;
            // *trav2 = temp->RC;
            // (*trav)->elem = temp->elem;
            BST *successor = min_node(&(*trav)->RC);
            (*trav)->elem = (*successor)->elem;
            temp = *successor;
            *successor = temp->RC;
        }
        free(temp);
    }
}

int member(BST B, int elem) {
    BST trav;
    for (trav = B; trav != NULL && trav->elem != elem;) {
        trav = (trav->elem > elem) ? trav->LC : trav->RC;
    }
    return (trav != NULL)?1:0;
}

int main() {
 
    BST myBST = NULL;
    insert(&myBST, 5);
    insert(&myBST, 7);
    insert(&myBST, 2);
    insert(&myBST, 1);
    insert(&myBST, 4);
    insert(&myBST, 6);
    insert(&myBST, 10);
    insert(&myBST, 8);

    delete(&myBST, 2);
    // printf("is 4 a member of the BST: %s\n", member(myBST, 4)==1?"YES":"NO");
    // BST *temp = min_node(&(myBST));
    // printf("the minimum of this root is %d\n", (*temp)->elem);

    print_tree(myBST, 1);
    destroy_tree(&myBST);
    return 0;
}