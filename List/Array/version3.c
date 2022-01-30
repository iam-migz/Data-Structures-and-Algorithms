/* 
Version 3: List is a structure containing a pointer 
to a dynamic array and count/last 
*/

#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

typedef struct {
    int *elements;
    int count;
    int max;
} List;

void init(List *L) {
    L->max = 10;
    L->elements = calloc(L->max, sizeof(int));
    L->count = 0;
}
void insert_at(List *L, int data, int index) {
    if (L->count < L->max) {
        if (index >= 0 && index <= L->count) {
            for (int i = L->count; i > index; i--) {
                L->elements[i] = L->elements[i-1];
            }
            L->elements[index] = data;
            L->count++;
        }
    } /*can also make the array bigger here, since it is dynamic*/
}
void insert_sorted(List *L, int data) { /*Ascending*/
    if (L->count < L->max) {
        int i;
        for (i = L->count; i >= 0 && data < L->elements[i-1]; i--) {
            L->elements[i] = L->elements[i-1];
        }
        L->elements[i] = data;
        L->count++;
    } /*else expand array*/
}
void delete(List *L, int index) {
    if (L->count > 0) {
        for (int i = index; i < L->count; i++) {
            L->elements[i] = L->elements[i+1];
        }
        L->count--;
    }
}
void make_null(List *L) {
    free(L->elements);
    L->elements = NULL;
    L->count = 0;
}

int main() {

    List L;
    init(&L);

    for (int i = 0; i < 10; i+=2)
        insert_at(&L, i, L.count);
    insert_sorted(&L, 5);
    delete(&L, 3);
    display(L.elements, L.count);

    make_null(&L);
    return 0;
}