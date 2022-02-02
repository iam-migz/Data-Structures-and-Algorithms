#include <stdio.h>
#include <stdlib.h>
#include "../../Utils/linkedlist.h"

/*
typedef struct node {
    int data;
    struct node *next; 
} NodeType, *NodePtr;
*/

/* 
    Get Even: returns all the even numbers as a list and removes it from the original list,
                remaining only odd numbers.
*/
NodePtr get_even(NodePtr *L) {
    NodePtr evens, temp;
    evens = NULL;
    while(*L) {
        if ((*L)->data % 2 == 0) {
            temp = *L;
            *L = (*L)->next;
            temp->next = evens;
            evens = temp;
        } else {
            L = &(*L)->next;
        }
    } 
    return evens;
}
/* delete all occurence of an element in the list */
void delete_all_occurence(NodePtr *L, int data) {
    NodePtr temp;
    while (*L) {
        if (data == (*L)->data) {
            temp = *L;
            *L = (*L)->next;
            free(temp);
        } else {
            L = &(*L)->next;
        }
    }
}
/* reverse linked list */
void reverse(NodePtr *L) {
    NodePtr trav, slow, fast;
    trav = *L;
    slow = NULL;

    while (trav) {
        fast = trav->next;
        trav->next = slow;
        slow = trav;
        trav = fast;
    }
    *L = slow;
}


int main() {

    NodePtr L = NULL;
    int elements[] = {1,1,2,1,3,1,1};
    populate_list(&L, elements, 7);
    NodePtr evens = get_even(&L);
    make_null(&L);
    
    return 0;
}