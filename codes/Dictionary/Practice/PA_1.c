#include <stdio.h>
#include <stdlib.h>

#define SIZE 0xA

typedef struct node {
    int data;
    struct node *link;
} NodeType, *NodePtr;

typedef NodePtr Dictionary[SIZE];
typedef int Set[SIZE];

int Hash(int x) {
    return x % 10;
}

void initDic(Dictionary D) {
    int x;
    for (x = 0; x < SIZE; x++) 
        D[x] = NULL;
}
void displayDic(Dictionary D) {
    for (int x = 0; x < SIZE; x++) {
        printf("[%d]: ",x);
        for (NodePtr trav = D[x]; trav != NULL; trav = trav->link) {
            printf("%5d", trav->data);
        }        
        printf("\n");
    }
}
void insert(Dictionary D, int data) {
    NodePtr *trav;
    int hash;

    hash = Hash(data);
    for (trav = &D[hash]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->link) { }
    if (*trav == NULL) {
        *trav = (NodePtr)calloc(1, sizeof(NodeType));
        (*trav)->data = data;
    }   
}

void populateDic(Dictionary D, Set A, int set_size) {
    int i;
    for (i = 0; i < set_size; i++) {
        insert(D, A[i]);
    }
}

void delete(Dictionary D, int data) {
    int hash;
    NodePtr *trav, temp;
    hash = Hash(data);

    for (trav = &D[hash]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->link){}
    if (*trav != NULL) {
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    }
}
int member(Dictionary D, int data) {
    int hash;
    NodePtr trav;
    hash = Hash(data);

    for (trav = D[hash]; trav != NULL && trav->data != data; trav = trav->link) {}
    return trav != NULL ? 1 : 0;
}
int main() {

    Dictionary D;
    Set A = {0, 13, 20, 28, 30, 33, 45, 48, 108};
    initDic(D);
    populateDic(D, A, 9);
    // displayDic(D);
    printf("%d", member(D, 13));

    return 0;

}