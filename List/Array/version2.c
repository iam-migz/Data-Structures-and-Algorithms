/* 
Version 2: List is a pointer to a dynamic structure
containing an array and count/last
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Utils/array.h"
#define MAX 10

typedef struct {
    int elements[MAX];
    int count;
} List;

void init(List **L) {
    *L = calloc(1, sizeof(List));
}
void insert_at(List **L, int data, int index) {
    if ((*L)->count < MAX) {
        if (index >= 0 && index <= (*L)->count) {
            for (int i = (*L)->count; i > index; i--) {
                (*L)->elements[i] = (*L)->elements[i-1];
            }
            (*L)->elements[index] = data;
            (*L)->count++;
        }
    }
}
void insert_sorted(List **L, int data) {/*Ascending*/
    if((*L)->count < MAX) {
        int i;
        for (i = (*L)->count; i >= 0 && data < (*L)->elements[i-1]; i--) {
            (*L)->elements[i] = (*L)->elements[i-1];
        }
        (*L)->elements[i] = data;
        (*L)->count++;
    }
}
void delete(List **L, int index) {
    if ((*L)->count > 0) {
        for(int i = index; i < (*L)->count; i++) {
            (*L)->elements[i] = (*L)->elements[i+1];
        }
        (*L)->count--;
    }
}
void make_null(List **L) {
    free(*L);
    *L = NULL;
}

int main() {

    List *L;
    init(&L);
    for (int i = 0; i < 10; i += 2)
        insert_at(&L, i, L->count);

    insert_sorted(&L, 5);
    delete(&L, 3);
    display(L->elements, L->count);


    make_null(&L);
    return 0;
}