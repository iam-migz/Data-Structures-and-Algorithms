#include <stdio.h>
#include <stdlib.h>
#include "../../Utils/linkedlist.h"

/*
typedef struct node {
    int data;
    struct node *next; 
} NodeType, *NodePtr;
*/

/* problems received in class */ 

/* 
    Delete all occurence of an element in the list 
*/
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
    Get Even:   returns all the even numbers as a list and removes it from the original list,
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

/*
    Get Even + insert sorted:  
            Write the code of the function that will delete all even numbers in the given linked list 
            and put them in a newly created linked list.
            The elements in the newly created linked list is sorted in ascending order, 
            hence each element will be inserted in the sorted list. In addition, 
            the newly created list will be returned to the calling function.
*/ 

NodePtr get_even_v2(NodePtr *L) {
    NodePtr evens, temp, *trav;
    evens = NULL;

    while (*L != NULL) {
        if ((*L)->data % 2 == 0) {
            temp = *L;
            *L = (*L)->next;
            for (trav = &evens; *trav != NULL && temp->data > (*trav)->data; trav = &(*trav)->next) {}
            temp->next = *trav;
            *trav = temp;
        } else {
            L = &(*L)->next;
        }
    }
    
    return evens;
}

/*
    changeLetter:   Given a list and 2 letters A and B, as parameters. The
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
    int elements[] = {7, 1, 3, 9, 5, 2, 4, 6, 10, 8};
    populate_list(&L, elements, 10);
    
    NodePtr evens = get_even_v2(&L);
 
    display(L);
    display(evens);

    make_null(&L);
    make_null(&evens);
    
    return 0;
}