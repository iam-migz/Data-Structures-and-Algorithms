// Computer Word or Bit array is an implementation of Bit-Vector

// we used an integer to hold a boolean value 0 or 1
// an interger can be 4 bytes or 32 bits
// a char can be 1 byte or 8 bits
// however, 1 bit is enough to hold a boolean value

// in computer word we use a char datatype to store a set
// 1 char = 8 bits
// word size is 8
// boolean values (0,1)
// 2^8 = 256 or 0 - 255 values

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

typedef char SET;

SET array_to_bitvector(int A[], int size) {
    SET x = 0;
    for (int i = 0; i < size; i++) {
        x |= 1 << A[i];
    }
    return x;
}

int *bitvector_to_array(SET x) {
    int *array = malloc(sizeof(int)*8);
    int num_bits = (sizeof(x)*8)-1;
    int i = 0;
    for (unsigned int mask = 1 << num_bits; mask > 0; mask >>= 1) {
        array[i] = (mask & x) ? 1 : 0;
        i++;
    }
    return array;
}

void display_bitvector(SET x) {
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
    SET A_bits = array_to_bitvector(A, 7);
    SET B_bits = array_to_bitvector(B, 3);
    // SET C_bits = get_union(A_bits, B_bits);
    // SET C_bits = get_intersection(A_bits, B_bits);
    // SET C_bits = get_difference(A_bits, B_bits);
    // insert_member(&C_bits, 1);
    // delete_member(&C_bits, 5);
    display_bitvector(A_bits);
    display_bitvector(B_bits);
    printf("\n");
    printf("is 6 a member of A?: %d\n", is_member(A_bits, 6));
    // display_bitvector(C_bits);

    return 0;
}