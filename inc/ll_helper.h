#ifndef LINKEDLIST_HELPER_H
#define LINKEDLIST_HELPER_H

typedef struct node {
    int data;
    struct node *next; 
} NodeType, *NodePtr;

void ll_display(NodePtr L);
void ll_make_null(NodePtr *L);
void ll_populate_list(NodePtr *L, int *array, int array_size);

#endif