#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef NodePtr SET;

SET get_intersection(SET A, SET B) {
    SET B_trav, C = NULL;
    for (; A != NULL; A = A->next) {
        for (B_trav = B; B_trav != NULL && B_trav->data != A->data; B_trav = B_trav->next) {}
        if (B_trav != NULL && B_trav->data == A->data) {
            SET temp = malloc(sizeof(NodeType));
            if (temp != NULL) {
                temp->data = A->data;
                temp->next = C;
                C = temp;
            }
        }
    }    
    return C;
}
SET get_union_unsorted(SET A, SET B) {
    SET temp, C = NULL;
    SET trav, travC;
    // insert all elements of A
    for (trav = A; trav != NULL; trav = trav->next) {
        temp = malloc(sizeof(NodeType));
        if (temp != NULL) {
            temp->data = trav->data;
            temp->next = C;
            C = temp;
        }
    }

    // insert last unique
    for (trav = B; trav != NULL; trav = trav->next) {
        // check every element of B if it is already present in Set C
        for (travC = C; travC != NULL && travC->data != trav->data; travC = travC->next) {}
        if (travC == NULL) {
            temp = malloc(sizeof(NodeType));
            if (temp != NULL) {
                temp->data = trav->data;
                temp->next = C;
                C = temp;
            }
        }
    }
    return C;
}
SET get_union_sorted(SET A, SET B) {
    SET temp, C = NULL;

    while (A != NULL && B != NULL) {
        if (A->data < B->data) {
            temp = malloc(sizeof(NodeType));
            if (temp != NULL) {
                temp->data = A->data;
                temp->next = C;
                C = temp;
            }
            A = A->next;
        } else {
            if (A->data == B->data) {
                A = A->next;
            } 
            temp = malloc(sizeof(NodeType));
            if (temp != NULL) {
                temp->data = B->data;
                temp->next = C;
                C = temp;
            }
            B = B->next;
        }
    }

    if (B != NULL) {
        A = B;
    }

    while (A != NULL) {
        temp = malloc(sizeof(NodeType));
        if (temp != NULL) {
            temp->data = A->data;
            temp->next = C;
            C = temp;
        }
        A = A->next;
    }

    return C;
}

// whats in A that not in B
SET get_difference(SET A, SET B) {
    SET temp, trav, C = NULL;
    for (; A != NULL; A = A->next) {
        for (trav = B; trav != NULL && trav->data != A->data; trav = trav->next) {}
        if (trav == NULL) {
            temp = malloc(sizeof(NodeType));
            if (temp != NULL) {
                temp->data = A->data;
                temp->next = C;
                C = temp;
            }
        }
    }
    return C;
}

int main() {

    SET A = NULL;
    SET B = NULL;

    // anonymous array allowed using typecast
    ll_populate_list(&A, (int[]){1,2,3,4}, 4);
    ll_populate_list(&B, (int[]){2,4,6,8}, 4);
    
    printf("Set A: ");
    ll_display(A);

    printf("Set B: ");
    ll_display(B);
    
    printf("Set C: ");
    SET C = get_difference(A, B); // 1, 3
    ll_display(C);

    ll_make_null(&A);
    ll_make_null(&B);
    ll_make_null(&C);
    return 0;
}