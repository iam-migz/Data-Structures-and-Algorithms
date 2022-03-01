/* 
Version 1:  List is a structure containing an array of 
            elemtype and count/last.
*/

#include <stdio.h>

#define MAX 10

typedef struct {
    int elements[MAX];
    int count;
} List;

void init(List *L) {
    L->count = 0;
}
void insert_at(List *L, int data, int index) {
    if (L->count < MAX) {
        if (index >= 0 && index <= L->count) {
            for (int i = L->count; i > index; i--) {
                L->elements[i] = L->elements[i-1];
            }
            L->elements[index] = data;
            L->count++;
        } 
    }
}
void insert_sorted(List *L, int data) { /*Ascending*/
    if (L->count < MAX) {
        int i;
        for (i = L->count; i >= 0 && data < L->elements[i-1]; i--) {
            L->elements[i] = L->elements[i-1];
        }
        L->elements[i] = data;
        L->count++;
    }
}
void delete(List *L, int index) {
    if (L->count > 0 && index < L->count) {
        for (int i = index; i < L->count; i++) {
            L->elements[i] = L->elements[i+1];
        }
        L->count--;
    }
}

int main() {

    return 0;
}