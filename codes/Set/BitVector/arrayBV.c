// an array of 1's and 0's to represent a set

// pros - time-complexity
// 1. CRUD O(1)
// 2. union, intersection, difference O(N)

// cons - space-complexity
// 1. size of set is proportional to the size of the universal set.
// 2. elements need to be integers, so that is can easily be mapped.


#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define MAX 10


enum {false, true};
typedef int SET[MAX];

void init_set(SET A) {
    for (int i = 0; i < MAX; i++) {
        A[i] = false;
    }
}

void create_set(SET A, int data[], int size) {
    for (int i = 0; i < size; i++) {
        A[data[i]] = true; 
    }
}

void insert_member(SET A, int pos) {
    A[pos] |= 1;
}

void delete_member(SET A, int pos) {
    A[pos] &= 0;
}

char arrayBV_to_8bits(int A[]) {
  char c = 0;
  unsigned int mask = 1;
  for(int i = 0; i < MAX; i++) {
    if (A[i] == true) {
      c = c | mask;
    }
    mask = mask << 1; 
  }
  return c;
}

// p's way, where C is a pointer to an array. an array is a pointer to it's first component
// so C is a pointer to a pointer to the first component.
SET* get_union(SET A, SET B) {
    SET *C = malloc(sizeof(int) * MAX);

    for (int i = 0; i < MAX; i++) {
        (*C)[i] = A[i] | B[i];
    }
    return C;
}

int* get_intersection(SET A, SET B) { 
    int *C = malloc(sizeof(int) * MAX);

    for (int i = 0; i < MAX; i++) {
        C[i] = A[i] & B[i];
    }
    return C;
}

int* get_difference(SET A, SET B) {
    int *C = malloc(sizeof(int) * MAX);

    for (int i = 0; i < MAX; i++) {
        C[i] = A[i] & ~B[i];
    }
    return C;
}

int main() {
    
    SET A;
    init_set(A);
    create_set(A, (int[]){0,3,5,7}, 4);
    printf("\n\nArray BitVector\n");
    visualize_array(A, MAX);
    return 0;
}