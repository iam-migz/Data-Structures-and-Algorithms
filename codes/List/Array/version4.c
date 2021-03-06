/* 
Version 4: List is a pointer to a dynamic structure 
containing a pointer to a dynamic array and count/last
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    int count;
    int max;
} List;

void init(List **L) {
    (*L)->max = 10;
    (*L)->count = 0;
    (*L)->elements = calloc((*L)->max, sizeof(int));
}
void insert_at(List **L, int data, int index) {
    if ((*L)->count < (*L)->max) {
        if (index >= 0 && index >= (*L)->count) {
            for (int i = (*L)->count; i > index; i--) {
                (*L)->elements[i] = (*L)->elements[i-1];
            }
            (*L)->elements[index] = data;
            (*L)->count++;
        }
    } /* can expand array*/
}
void insert_sorted(List **L, int data) { /*Ascending*/ 
    if ((*L)->count < (*L)->max) {
        int i;
        for (i = (*L)->count; i >= 0 && data < (*L)->elements[i-1]; i--) {
            (*L)->elements[i] = (*L)->elements[i-1];
        }        
        (*L)->elements[i] = data;
        (*L)->count++;
    } /* can expand array */
}
void delete(List **L, int index) {
    if ((*L)->count > 0) {
        for (int i = index; i < (*L)->count; i++) {
            (*L)->elements[i] = (*L)->elements[i+1];
        }
        (*L)->count--;
    }
}
void make_null(List **L) {
    (*L)->max = 0;
    (*L)->count = 0;
    free((*L)->elements);
    (*L)->elements = NULL;
}

int main() {
    
    return 0;
}