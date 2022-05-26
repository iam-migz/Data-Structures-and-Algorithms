#include <stdio.h>
#include <string.h>
#define MAX 0xA
typedef struct {
    char priority[5];
    char name[25];
    int price;
}Food;
typedef struct {
    Food data[MAX];
    int last_index;
}Heap; //minheap


// 1. insert
void insert(Heap *H, Food F) {
    int trav, parent;
    if (H->last_index+1 < MAX) {
        H->last_index++;
        trav = H->last_index;
        parent = (trav-1)/2;
        while (trav > 0 && strcmp(F.priority, H->data[parent].priority) < 0) {
            H->data[trav] = H->data[parent];
            trav = parent;
            parent = (trav-1)/2;
        }
        H->data[trav] = F;
    }
}

// 2. delete
Food delete_min(Heap *H) {
    Food ret, swap;
    int trav, child;
    if (H->last_index >= 0) {
        ret = H->data[0];
        H->data[0] = H->data[H->last_index];
        H->last_index--;
        trav = 0;
        child = 1;
        // swim down
        while (trav < H->last_index && strcmp(H->data[trav].priority, H->data[child].priority) > 0) {
            if (child+1 < H->last_index && strcmp(H->data[child].priority, H->data[child+1].priority) < 0) {
                child++;
            }   
            if (strcmp(H->data[trav].priority, H->data[child].priority) > 0) {
                swap = H->data[trav];
                H->data[trav] = H->data[child];
                H->data[child] = swap;
            }
        }
    }
    return ret;
}

// 3. Heapify


// Utils
void visualize_array(Food foods[], int count) {
    printf("INDX:");
    for (int i = 0; i < count; i++) {
        printf("%6d", i);
    }
    printf("\n");
    printf("DATA:");
    for (int i = 0; i < count; i++) {
        printf("%6s", foods[i].priority);
    }
    printf("\n");
}

int main() {
    
    Heap H = {.last_index=-1};
    Food myFood[] = {
        {"A8", "adobo", 50},
        {"A1", "sisig", 50},
        {"A5", "humba", 60},
        {"A3", "sinigang", 60},
    };

    for(int i = 0; i < 4; i++) 
        insert(&H, myFood[i]);
        
    Food temp;
    
    temp = delete_min(&H);
    printf("%s\n", temp.priority);
    visualize_array(H.data, H.last_index+1);
    return 0;
}