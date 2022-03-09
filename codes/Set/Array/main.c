#include <stdio.h>
#include "array.h"

// list implementations
// doing operations requires traversal 
// CRUD O(N)
#define SET_MAX 10
typedef struct {
    int data[SET_MAX];
    int count;
} SET;

// unsorted
SET get_intersection(SET A, SET B) {
    SET C = {.count = 0};
    int i, k;
    for (i = 0; i < A.count; i++) {
        for (k = 0; k < B.count && A.data[i] != B.data[k]; k++) {}

        if (k < B.count && A.data[i] == B.data[k]) {
            C.data[C.count++] = A.data[i];
        }
    }

    return C;
}

SET get_union_unsorted(SET A, SET B) { // O(N^2)
    SET C = {.count = 0};
    int i, k;
    // insert elements of set A
    for (i = 0; i < A.count; i++) {
        C.data[C.count++] = A.data[i];
    }

    // for elements of b, insert last unique
    for (i = 0; i < B.count; i++) {
        for (k = 0; k < C.count; k++) {
            if (B.data[i] == C.data[k]) 
                break;
        }
        if (k == C.count)
            C.data[C.count++] = B.data[i];
    }

    return C;
}

SET get_union_sorted(SET A, SET B) { // O(N+N) == O(N)
    SET C = {.count = 0};   
    int a_ctr, b_ctr;
    a_ctr = b_ctr = 0;

    while (a_ctr < A.count && b_ctr < B.count) {
        if (A.data[a_ctr] < B.data[b_ctr]) {
            C.data[C.count++] = A.data[a_ctr++];
        } else {
            if (A.data[a_ctr] == B.data[b_ctr]) {
                a_ctr++;
            }
            C.data[C.count++] = B.data[b_ctr++];
        }
    }

    if (b_ctr < B.count) {
        A = B;
        a_ctr = b_ctr;
    }

    while (a_ctr < A.count) {
        C.data[C.count++] = A.data[a_ctr++];
    }

    return C;
}

// what's in A thats not in B
SET get_difference(SET A, SET B) {
    SET C = {.count = 0};
    int i, k;
    for (i = 0; i < A.count; i++) {
        for (k = 0; k < B.count && A.data[i] != B.data[k]; k++) {}
        if (k == B.count || A.data[i] != B.data[k]) {
            C.data[C.count++] = A.data[i];
        }
    }   

    return C;
}

SET get_merge(SET A, SET B) {
    SET C = {.count = 0};

    C = get_intersection(A, B);
    
    if (C.count == 0) {
        C = get_union_unsorted(A, B);
    } else {
        printf("disjoint set\n");
        C.count = 0;
    }

    return C;
}


int main() {

    SET A = {.count = 4, .data = {1,2,3,4}};
    printf("SET A:\n");
    visualize_array(A.data, A.count);
    printf("\n");

    SET B = {.count = 4, .data = {2,4,6,8}};
    printf("SET B:\n");
    visualize_array(B.data, B.count);
    printf("\n");

    SET C = get_intersection(A,B);
    printf("A intersection B:\n");
    visualize_array(C.data, C.count);
    printf("\n");

    // SET D = get_union_unsorted(A,B);
    // printf("A union unsorted B:\n");
    // visualize_array(D.data, D.count);
    // printf("\n");

    // SET E = get_union_sorted(A,B);
    // printf("A union sorted B:\n");
    // visualize_array(E.data, E.count);
    // printf("\n");

    // SET F = get_difference(A,B);
    // printf("A difference B:\n");
    // visualize_array(F.data, F.count);
    // printf("\n");

    // SET G = get_merge(A,B);
    // printf("A merge B:\n");
    // visualize_array(G.data, G.count);
    // printf("\n");


    return 0;
} 