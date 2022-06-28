// using an integer (32 bits) to store a set

#include <stdio.h>
#include <stdint.h>


void display_32bits(int32_t x){
    int32_t num_bits = (sizeof(int32_t)*8)-1;
    int mask;
    for (int i = 0; i <= num_bits; i++) { // we can't use bit mask as a counter, it's not big enough
        mask = 1 << (num_bits-i);
        printf("%d ", x & mask ? 1 : 0);
    }
    printf("\n");
}

int32_t set_intersection(int32_t A, int32_t B) {
    return A & B;
}
void insert_member(int32_t *A, int32_t pos) {
    int32_t total_bits = (sizeof(int32_t)*8); // 32 
    int32_t bucket = pos / total_bits;
    int32_t bit_pos = pos % total_bits;
    A[bucket] |= 1 << bit_pos;
}

void delete_member(int32_t *A, int32_t pos) {
    int32_t total_bits = (sizeof(int32_t)*8); 
    int32_t bucket = pos / total_bits;
    int32_t bit_pos = pos % total_bits;
    A[bucket] &= ~(1 << bit_pos);
}

int main() {

    // 32 * 3 = 96 set size
    // we have 96 set size using only 3 ints
    int32_t set[3] = {0};

    insert_member(set, 33);
    delete_member(set, 33);
    insert_member(set, 22);
    display_32bits(set[0]);
    display_32bits(set[1]);
    display_32bits(set[2]);
    return 0;
}

// hex notes
// 32 bits 
// 1 hex = 4 bits
// 2 hex = 8 bits
// every 2 hex there is 8 bits

// set[0] = 0x45;
// first eight bits 0100 0101