#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX  0xA

typedef struct node {
    int elem[MAX];
    int last;       // index of last element, -1 if list is empty  
} *List;

typedef enum {FALSE, TRUE} boolean;


/*
    1. Write the code of the function that will return TRUE of the given element is found in the given Sorted list, 
    otherwise return FALSE.
*/
boolean isFoundArray(List L, int elem) {
    int i;
    for (i = 0; i <= L->last && elem > L->elem[i]; i++){}
    return i <= L->last && L->elem[i] == elem ? TRUE : FALSE;
}
/*
    Note:   1.  If "Sorted" Assume list is in Ascending order if problem does not specify.       
            2.  Use relational operators when finding an element in a sorted list or use a Binary Search. 
*/

/*
    2. Get Even + insert sorted:  
            Write the code of the function that will delete all even numbers in the given linked list 
            and put them in a newly created linked list.
            The elements in the newly created linked list is sorted in ascending order, 
            hence each element will be inserted in the sorted list. In addition, 
            the newly created list will be returned to the calling function.
*/ 
List getEvens(List L) {
    int i, j;
    i = 0;

    List evens = (List)malloc(sizeof(struct node));
    if (evens != NULL) {
        evens->last = -1;
        while (i <= L->last) {
            if (L->elem[i] % 2 == 0) {
                /*insert sorted in the new list*/  
                for (j = 0; j <= evens->last && L->elem[i] > evens->elem[j]; j++) {}
                evens->elem[j] = L->elem[i];

                /*delete from current list*/
                for (j = i; j < L->last; j++) {
                    L->elem[j] = L->elem[j+1];
                }
            } else {
                i++;
            }
        }
    }

    return evens;
}

/*
    3. In mathematics, a set is a collection of elements which
    are unique. The intersection of two sets, is a set containing
    elements that are common to both set. The set will be represented
    in the computer's memory using an array which ends with a -1, which 
    will serve as a sentinel value.

    Given two arrays representing two sets containing positive integers, 
    the function will return to the calling function the set representing
    the intersection of the two given sets.
*/ 

int *get_intersection(int *A, int *B) {
    int temp[50]; // 50 == arbitrary number
    int k = 0;

    for (int i = 0; A[i] != -1; i++) {
        for (int j = 0; B[j] != -1; j++) {
            if (A[i] == B[j]) {
                temp[k] = A[i];
                k++;
            }
        }
    }
    temp[k] = -1;
    int *C = malloc(sizeof(int) * (k+1));
    memcpy(C, temp, sizeof(int) * (k+1));
    return C;
}


int main() {
    printf("hello world");
    return 0;
}