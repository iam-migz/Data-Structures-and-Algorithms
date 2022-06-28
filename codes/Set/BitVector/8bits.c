// using char (8 bits) to store a set
// Computer Word 

// in computer word we use a char datatype to store a set
// 1 char = 8 bits
// word size is 8
// boolean values (0,1)
// 2^8 = 256 or 0 - 255 values

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

typedef char SET;

SET array_to_8bits(int A[], int size) {
    SET x = 0;
    for (int i = 0; i < size; i++) {
        x |= 1 << A[i];
    }
    return x;
}

int* _8bits_to_array(SET x) {
    int *array = malloc(sizeof(int)*8);
    int num_bits = (sizeof(x)*8)-1;
    int i = 0;
    for (unsigned int mask = 1 << num_bits; mask > 0; mask >>= 1) {
        array[i] = (mask & x) ? 1 : 0;
        i++;
    }
    return array;
}

void display_8bits(SET x) {
    printf("%5s: %c","char",x);
    printf("\n%5s: ", "index");
    int i;
    for (i = 7; i >= 0; i--) {
        printf(" %d ", i);
    }
    // displaying the bits
    printf("\n%5s: ", "bits");
    int num_bits = (sizeof(x)*8)-1;
    for (unsigned int mask = 1 << num_bits; mask > 0; mask >>= 1) { // using bit mask as the counter
        printf(" %d ", (x & mask) ? 1 : 0);
    }
    printf("\n%5s: ", "value");
    i = 7;
    for (unsigned int mask = 1 << num_bits; mask > 0; mask >>= 1) {
        if (x & mask) {
            printf(" %d ", i);
        }
        i--;
    }
    printf("\n\n");
}

SET get_union(SET A, SET B) {
    return A | B;
}
SET get_intersection(SET A, SET B) {
    return A & B;
}
SET get_difference(SET A, SET B) {
    return A & ~B;
}
void insert_member(SET *A, int pos) {
    *A |= 1 << pos;
}
void delete_member(SET *A, int pos) {
    *A = *A & ~(1 << pos);
}
int is_member(SET A, int pos) {
    char mask = 1 << pos;
    return (A & mask) == 0 ? 0 : 1;
}
int main() {
                       
    int A[] = {1,2,3,4,5,6,7}; 
    int B[] = {1,2,4}; 
    SET A_bits = array_to_8bits(A, 7);
    SET B_bits = array_to_8bits(B, 3);

    display_8bits(A_bits);
    display_8bits(B_bits);
    return 0;
}