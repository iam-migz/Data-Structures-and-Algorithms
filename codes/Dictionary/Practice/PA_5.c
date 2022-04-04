/*
    Closed Hashing Variation: Primes & Synonyms
*/
#include <stdio.h>

#define SIZE 20
#define PRIME_PCT .5 // 50% of the size is dedicated for prime data.
#define EMPTY -1
#define DELETED -2

typedef enum {FALSE, TRUE} Boolean;

typedef struct {
    int HTable[SIZE];
    int lastNdx;
} Dictionary;

int get_hash(int key) {
    int prime = SIZE * PRIME_PCT;
    return (key*32)%prime;
}

void init_dict(Dictionary *D) {
    int x, prime;
    prime = SIZE * PRIME_PCT;
    for (x = 0; x < prime; x++) {
        D->HTable[x] = EMPTY;
    }
    D->lastNdx = prime-1;
}

void insert_dict(Dictionary *D, int data) {
    int hash;

    hash = get_hash(data);
    if (D->HTable[hash] == EMPTY || D->HTable[hash] == DELETED) {
        D->HTable[hash] = data;
    } else {
        if (D->lastNdx < SIZE) {
            ++D->lastNdx;
            D->HTable[D->lastNdx] = data;
        } else {
            printf("Dictionary is full\n");
        }
    }
}

void delete_dict(Dictionary *D, int data) {

    int x, hash;

    hash = get_hash(data);

    if (D->HTable[hash] == data) {
        D->HTable[hash] = DELETED;
    } else {
        for (x = SIZE*PRIME_PCT; x <= D->lastNdx; x++) {
            if (D->HTable[x] == data) {
                D->HTable[x] = D->HTable[D->lastNdx];
                --D->lastNdx;
            }
        }
    }
}

Boolean is_member(Dictionary D, int data) {
    int x, hash;

    hash = get_hash(data);

    if (D.HTable[hash] == data) {
        return TRUE;
    } else {
        for (x = SIZE*PRIME_PCT; x <= D.lastNdx; x++) {
            if (D.HTable[x] == data) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

int main () {

    Dictionary D;
    init_dict(&D);
    insert_dict(&D, 2);
    insert_dict(&D, 23);
    insert_dict(&D, 34);
    insert_dict(&D, 3);
    insert_dict(&D, 4);
    insert_dict(&D, 45);
    insert_dict(&D, 5);
    insert_dict(&D, 51);
    
    printf("is 52 present: %s\n", is_member(D, 52) == TRUE ? "YES" : "NO");


    return 0;
}