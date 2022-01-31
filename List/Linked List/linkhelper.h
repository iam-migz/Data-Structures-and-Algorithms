#ifndef LINKHELPER_H
#define LINKHELPER_H

typedef struct node {
    int data;
    struct node *next; 
} NodeType, *NodePtr;

void display(NodePtr L) {
    for (;L ;L = L->next) {
        printf("%d", L->data);
        if (L->next) {
            printf(", ");
        }
    }
}
void make_null(NodePtr *L) {
    NodePtr temp;
    while (*L) {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
void populate_list(NodePtr *L, int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        *L = malloc(sizeof(NodeType));
        (*L)->data = array[i];
        (*L)->next = NULL;
        L = &(*L)->next;
    }
}

#endif