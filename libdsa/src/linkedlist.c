#include <stdio.h>
#include <stdlib.h>
#include "../inc/linkedlist.h"

void ll_display(NodePtr L) {
    for (;L != NULL;L = L->next) {
        printf("%d", L->data);
        if (L->next) {
            printf(", ");
        }
    }
    printf("\n");
}
void ll_make_null(NodePtr *L) {
    NodePtr temp;
    while (*L != NULL) {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
void ll_populate_list(NodePtr *L, int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        *L = malloc(sizeof(NodeType));
        (*L)->data = array[i];
        (*L)->next = NULL;
        L = &(*L)->next;
    }
}