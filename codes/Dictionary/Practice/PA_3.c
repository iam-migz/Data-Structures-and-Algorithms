// Closed Hashing (Linear Hashing)
#include <stdio.h>
#include <stdlib.h>

#define SIZE 23
#define EMPTY 0
#define DELETED -1

typedef int Dictionary[SIZE];

int hashVal(int data) {
    int hash, i;
    hash = 0;
    for (i = 0; data != 0 && i < 4; i++) {
        hash += data % 10;
        data /= 10;
    }
    return hash % SIZE;
} 

void initHashTable(Dictionary D) {
    for (int i = 0; i < SIZE; i++) 
        D[i] = EMPTY;
}

void displayHashTable(Dictionary D) {
    int hash;
    printf("Index \t Content \t Hash Value \t Search Length\n");
    for (int i = 0; i < SIZE; i++) {
        if (D[i] == EMPTY) {
            printf("%5d \t %7s \t %10s \t %13s\n", i, "EMPTY", "", "");
        } else if (D[i] == DELETED) {
            printf("%5d \t %7s \t %10s \t %13s\n", i, "DELETED", "", "");
        } else {
            hash = hashVal(D[i]);
            printf("%5d \t %7d \t %10d \t %13d\n", i, D[i], hash, (i+1)-hash);
        }

    }
}
void insert(Dictionary D, int data) {
    int hash, i;
    hash = hashVal(data);

    // improve this part, in the event when everything is occupied it wont stop., lacking terminator
    for (i = hash; D[i] != EMPTY && D[i] != DELETED; i = (i + 1) % SIZE) {
        if (D[i] == data) return; // insert unique
    } 
    if (D[i] == EMPTY || D[i] == DELETED) {
        D[i] = data;
    }
    
}
void delete(Dictionary D, int data) {
    int hash, i;
    hash = hashVal(data);

    for (i = hash; D[i] != EMPTY && D[i] != data; i = (i + 1) % SIZE) {}
    if (D[i] == data) {
        D[i] = DELETED;
    }
}

int member(Dictionary D, int data) {
    int hash, i;

    hash = hashVal(data);
    for (i = hash; D[i] != EMPTY && D[i] != data; i = (i + 1) % SIZE) {}
    if (D[i] == data) {
        return 1;
    }
    return 0;
}

int main() {

    // Task 1
    Dictionary D;
    initHashTable(D);

    // Task 2
    int SET_A[] = {4057,3042,3205,848,1864,987,3082,414,1728,1400,1223,2710,2486,2885,1192,4057};
    for (int i = 0; i < 16; i++) 
        insert(D, SET_A[i]);

    // Task 3
    int SET_B[] = {4057,3205,1728,2486,1192,5595};
    for (int i = 0; i < 6; i++) 
        delete(D, SET_B[i]);

    // Task 4
    int SET_C[] = {1400,5595,121,139,1532,596,2800,1167,213};
    for (int i = 0; i < 9; i++) 
        insert(D, SET_C[i]);

    // Task 5
    printf("5595 is a member: %s\n", member(D, 5595) == 1 ? "TRUE" : "FALSE");
    printf("4057 is a member: %s\n", member(D, 4057) == 1 ? "TRUE" : "FALSE");

    displayHashTable(D);

    return 0;

}