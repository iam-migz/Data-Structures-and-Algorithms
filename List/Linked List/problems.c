#include <stdio.h>
#include <stdlib.h>
#include "../../Utils/linkedlist.h"

/*
typedef struct node {
    int data;
    struct node *next; 
} NodeType, *NodePtr;
*/

/* problems found on the internet */ 

/* 1. Print in Reverse */
void print_reverse(NodePtr L) {
    if (L != NULL) {
        print_reverse(L->next);
        printf("%d ", L->data);
    }
}

/* 2. Find the middle node */ 
NodePtr find_middle(NodePtr L) {
    NodePtr fast, slow;
    fast = slow = L;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
} 

/* 3. Reverse a linked list */ 
void reverse_ll(NodePtr *L) {
    NodePtr trav, front, back;
    trav = *L;
    back = NULL;
    while (trav) {
        front = trav->next;
        trav->next = back;
        back = trav;
        trav = front;
    }
    *L = back;
}

/* 4. Merge two list into a sorted list, assume both list already sorted, "Union" */ 
NodePtr merge_lists(NodePtr A, NodePtr B) {
    NodePtr merge, *trav;
    trav = &merge;

    while (A && B) {
        if (A->data < B->data) {
            *trav = A;
            trav = &A->next;
            A = A->next;
        } else {
            *trav = B;
            trav = &B->next;
            B = B->next;
        }
    }
    if (A == NULL) {
        A = B;
    }
    while (A) {
        *trav = A;
        trav = &A->next;
        A = A->next;
    }
    return merge;    
}

int main() {

    NodePtr L = NULL;
    NodePtr B = NULL;

    int elements[] = {1, 3, 5};
    int elements2[] = {2, 4, 6};
    populate_list(&L, elements, 3);
    populate_list(&B, elements2, 3);
    NodePtr merge = merge_lists(L, B);    
    L = NULL;
    B = NULL;
    display(merge);
    make_null(&L);
    
    return 0;
}