#include <stdio.h>
#include "array.h"

#define MAX 10
typedef struct {
    int elem[MAX];
    int last_index;
} Heap;

void insert(Heap *H, int data){ 
    int trav, parent;
    if (H->last_index+1 < MAX) {
        H->last_index++;
        trav = H->last_index;
        parent = (trav-1)/2;

        while (trav != 0 && data < H->elem[parent]) {
            H->elem[trav] = H->elem[parent];
            trav = parent;
            parent = (trav-1)/2;
        }
        H->elem[trav] = data;  
    }
}

int delete_min(Heap *H) {
    int child, trav_down, swap, min =-1;
    if (H->last_index != -1) {
        min = H->elem[0];
        H->elem[0] = H->elem[H->last_index];
        H->last_index--;

        // swim down
        trav_down = 0;
        child = 1;
        while (child <= H->last_index) {
            if (child+1 <= H->last_index && H->elem[child+1] < H->elem[child] ) {
                child++;
            }
            if (H->elem[trav_down] > H->elem[child]) {
                // swap
                swap = H->elem[trav_down];
                H->elem[trav_down] = H->elem[child];
                H->elem[child] = swap;

                // traverse
                trav_down = child;
                child = trav_down*2+1;
            } else {
                break;
            }
        }
    }
    return min;
}

// accepts a list stored in the given heap, transforms it into a proper heap
void heapify(Heap *H) {
    int parent_trav, down, child, swap;
    if (H->last_index != -1) {
        // start with the lowest parent
        parent_trav = (H->last_index-1)/2;
        // linear trav
        while (parent_trav >= 0) {
            down = parent_trav;
            child = down*2+1;
            // until there is still a valid child of down
            while (child <= H->last_index) {
                // find the minimum child
                if (child+1 <= H->last_index && H->elem[child] > H->elem[child+1]) 
                    child++;
                // swap|break 
                if (H->elem[down] > H->elem[child]) {
                    swap = H->elem[down];
                    H->elem[down] = H->elem[child];
                    H->elem[child] = swap;
                    // go deeper
                    down = child;
                    child = down*2+1;
                } else {
                    break;
                }
            }
            parent_trav--;
        }
    }
}

// accepts a list stored in the given heap, transforms the heap into a sorted list, descending order
void heapsort(Heap *H) {
    int old_last, temp;

    // 1. make the heap
    heapify(H);
    // 2. delete_min until empty and store in the last avail index
    old_last = H->last_index;
    while (H->last_index != -1) {
        temp = delete_min(H);
        H->elem[H->last_index+1] = temp;
    }
    H->last_index = old_last;
}


int main() {

    Heap H = {{9,7,8,1,2,7,5,6},7};


    heapsort(&H);
    visualize_array(H.elem, H.last_index+1);


    return 0;
}