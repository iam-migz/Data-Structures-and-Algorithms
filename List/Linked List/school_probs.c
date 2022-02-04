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

/*
Function changeLetter(): Given a list and 2 letters A and B, as parameters. The
    function will replace all occurrences of a given A to a given letter B. In addition,
    the function will return to the calling function total number of changes in the
    function.
*/ 
int changeNumber(NodePtr L, int a, int b) {
    int count = 0;

    for (;L != NULL; L = L->next) {
        if (L->data == a) {
            L->data = b;
            count++;
        }
    }
    return count;
}

/*
    Bubble sort a linked list
*/ 
void sort_ll(NodePtr L) {
    for (NodePtr first = L; first != NULL; first = first->next) {
        for (NodePtr second = first->next; second != NULL; second = second->next) {
            if (first->data > second->data) {
                int temp = first->data;
                first->data = second->data;
                second->data = temp;
            }
        }
    }
}


int main() {

    NodePtr L = NULL;
    int elements[] = {2, 1, 3, 6, 5, 4, 7};
    populate_list(&L, elements, 7);

 
    sort_ll(L);
    display(L);
    make_null(&L);
    
    return 0;
}