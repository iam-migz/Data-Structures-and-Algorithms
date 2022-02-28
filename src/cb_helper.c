#include <stdio.h>
#include "../inc/cb_helper.h"

void cb_init(Vheap *vh) {
    int i;
    for (i = 0; i < MAX; i++) {
        vh->elements[i].elem = -1;
        vh->elements[i].next = i-1;
    }
    vh->avail = MAX-1;
}
int cb_allocate_space(Vheap *vh) {
    int index = vh->avail;
    if (index != -1) {
        vh->avail = vh->elements[vh->avail].next;
    }
    return index;
}   
int cb_deallocate_space(Vheap *vh, int index) {
    if (index >= 0 && index < MAX) {
        vh->elements[index].elem = -1;
        vh->elements[index].next = vh->avail;
        vh->avail = index;
    }
}
void cb_visualize(Vheap vh) {
    printf("index \t elem \t next\n");
    for (int i = 0; i < MAX; i++) {
        printf("%5d \t %5d \t %5d\n", i, vh.elements[i].elem, vh.elements[i].next);
    }
    printf("avail: %d\n", vh.avail);
}
void cb_display_list(Vheap vh, int list) {
    printf("list start @ index: %d. \t", list);
    printf("[");
    for (int i = list; i != -1; i = vh.elements[i].next) {
        printf("%d", vh.elements[i].elem);
        if (vh.elements[i].next != -1) {
            printf(", ");
        } 
    }
    printf("]");
    printf("\n");
}
void cb_populate_list(Vheap *vh, int *list, int array[], int array_size) {
    int temp;
    for (int i = 0; i < array_size; i++) {
        *list = cb_allocate_space(vh);
        vh->elements[*list].elem = array[i];
        vh->elements[*list].next = -1;
        list = &vh->elements[*list].next;
    }
}