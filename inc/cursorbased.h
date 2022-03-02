#ifndef CURSORBASED_H
#define CURSORBASED_H

#define MAX 10

typedef struct {
    int elem;
    int next;
} Node;

typedef struct {
    Node elements[MAX];
    int avail;
} Vheap;

void cb_init(Vheap *vh);
int cb_allocate_space(Vheap *vh);
void cb_deallocate_space(Vheap *vh, int index);
void cb_visualize(Vheap vh);
void cb_display_list(Vheap vh, int list);
void cb_populate_list(Vheap *vh, int *list, int array[], int array_size);

#endif