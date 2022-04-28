#include <stdio.h>
#include "array.h"

#define MAX 10
typedef struct {
    int elem[MAX];
    int last_index;
} Heap;

void insert(Heap *H, int elem) {
    int index, parent_index;
    
    if (H->last_index < MAX-1) {
        H->last_index++;
        index = H->last_index;
        parent_index = (index-1)/2;

        while (index != 0 && H->elem[parent_index] < elem) {
            H->elem[index] = H->elem[parent_index];
            index = parent_index;
            parent_index = (index-1)/2; 
        }
        H->elem[index] = elem;
    }
}

// O(logn)
int delete_max(Heap *H) {  
    int max, trav, child, temp;

    if (H->last_index == -1) return -1;

    // delete max and replace it with the last element
    max = H->elem[0];
    H->elem[0] = H->elem[H->last_index];
    H->last_index--;

    // readjust the heap
    trav = 0;
    child = 1;
    while (child <= H->last_index) {
        // find the biggest child
        if (child+1 <= H->last_index && H->elem[child] < H->elem[child+1]) {
            child++;
        }

        // swap | break
        if (H->elem[trav] < H->elem[child]) {
            temp = H->elem[trav];
            H->elem[trav] = H->elem[child];
            H->elem[child] = temp;
            trav = child;
            child = trav*2+1;
        } else {
            break;
        }
    }
    return max;
}

// O(2nlogn) or O(nlogn)
void heapsort(Heap *H) {
    int i, orig_heap, catcher;

    // 1. create the heap O(nlogn)
    orig_heap = H->last_index;
    H->last_index = -1;
    for (i = 0; i <= orig_heap; i++) {
        insert(H, H->elem[i]);
    }

    // 2. delete and store it in-place O(nlogn)
    while (H->last_index != -1) {
        catcher = delete_max(H);
        H->elem[H->last_index+1] = catcher;
    }
    H->last_index = orig_heap;
}

// O(n)
void heapify(Heap *H) { 
    int parent, down, child, swap;
    if (H->last_index == -1) return;
    // start with the lowest level parent
    parent = (H->last_index-1)/2;
    while (parent >= 0) {
        down = parent;
        child = down*2+1;
        while (child <= H->last_index) {
            if (child+1 <= H->last_index && H->elem[child] < H->elem[child+1]) {
                child++;
            }
            if (H->elem[down] < H->elem[child]) {
                swap = H->elem[down];
                H->elem[down] = H->elem[child];
                H->elem[child] = swap;
                down = child;
                child = down*2+1;
            } else {
                child = H->last_index+1;
            }
        }
        --parent;
    }
}


// using heapify, O(nlogn)
void heapsort_v2(Heap *H) {
    int orig, catcher;
    orig = H->last_index;
    heapify(H);
    while (H->last_index != -1) {
        catcher = delete_max(H);
        H->elem[H->last_index+1] = catcher;
    }
    H->last_index = orig;
}

int main() {

    printf("Heapsort v1\n");
    Heap H1 = {{5, 4, 8, 10, 1, 7, 25}, 6};
    heapsort(&H1);
    visualize_array(H1.elem, H1.last_index+1);  

    printf("\n");

    printf("Heapsort v2\n");
    Heap H2 = {{5, 4, 8, 10, 1, 7, 25}, 6};
    heapsort_v2(&H2);
    visualize_array(H2.elem, H2.last_index+1);
    return 0;
}