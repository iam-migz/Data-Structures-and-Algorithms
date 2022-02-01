#include <stdio.h>
#include "./util.h"

/*
typedef struct {
    int elem;
    int next;
} Node;

typedef struct {
    Node elements[MAX];
    int avail;
} Vheap;
*/

/* 
    Get Even: returns all the even numbers as a list and removes it from the original list,
                remaining only odd numbers.
*/

/* delete all occurence of an element in the list */

int main (){

    Vheap vh;
    int list = -1;
    init(&vh);
    int elements[] = {1,2,3,4,5,6};
    populate_list(&vh, &list, elements, 6);

    
    visualize(vh);
    display_list(vh, list);
    return 0;
}