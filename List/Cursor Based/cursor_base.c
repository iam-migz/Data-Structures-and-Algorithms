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

/* Operations */ 
void insert_first(Vheap *vh, int *list, int elem) {
    int index = allocate_space(vh);
    if (index != -1) {
        vh->elements[index].elem = elem;
        vh->elements[index].next = *list;
        *list = index; 
    }
}
void insert_last(Vheap *vh, int *list, int elem) {
    int index = allocate_space(vh);
    if (index != -1) {
        for (; *list != -1; list = &vh->elements[*list].next) {}
        vh->elements[index].elem = elem;
        vh->elements[index].next = -1;
        *list = index;
    }
}
void delete_first(Vheap *vh, int *list) {
    if (*list != -1) {
        int temp = *list;
        *list = vh->elements[*list].next;
        deallocate_space(vh, temp);
    }
}
void delete_last(Vheap *vh, int *list) {
    if (*list != -1) {
        for (; vh->elements[*list].next != -1; list = &vh->elements[*list].next){}
        int temp = *list;
        *list = -1;
        deallocate_space(vh, temp);
    }
}
void delete_elem(Vheap *vh, int *list, int elem) {
    if (*list != -1) {
        for (; *list != -1 && vh->elements[*list].elem != elem; list = &vh->elements[*list].next){}
        if (*list != -1) {
            int temp = *list;
            *list = vh->elements[*list].next;
            deallocate_space(vh, temp);
        }
    }
}

int main (){

    Vheap vh;
    int myList = -1;
    init(&vh);
    insert_first(&vh, &myList, 3);
    insert_first(&vh, &myList, 2);
    insert_first(&vh, &myList, 1);
    insert_last(&vh, &myList, 4);
    delete_elem(&vh, &myList, 4);
    visualize(vh);
    display_list(vh, myList);

    return 0;
}