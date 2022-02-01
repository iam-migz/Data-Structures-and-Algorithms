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
int get_even(Vheap *vh, int *list) {
    int temp;
    int evens = -1;

    while (*list != -1) {
        if (vh->elements[*list].elem % 2 == 0) {
            temp = *list;
            *list = vh->elements[*list].next;
            vh->elements[temp].next = evens;
            evens = temp;
        } else {
            list = &vh->elements[*list].next;
        }
    }

    return evens;
}


/* delete all occurence of an element in the list */
void delete_all_occurence(Vheap *vh, int *list, int elem) {
    int temp;
    while (*list != -1) {
        if (vh->elements[*list].elem == elem) {
            temp = *list; 
            *list = vh->elements[*list].next;
            deallocate_space(vh, temp);
        } else {
            list = &vh->elements[*list].next;
        }
    }
}

int main (){

    Vheap vh;
    int list = -1;
    init(&vh);
    int elements[] = {1,2,3,4,5,6};
    populate_list(&vh, &list, elements, 6);

    int evens = get_even(&vh, &list);
    visualize(vh);
    display_list(vh, list);
    display_list(vh, evens);
    return 0;
}