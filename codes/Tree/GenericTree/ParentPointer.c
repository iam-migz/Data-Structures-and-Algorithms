#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define ROOT -1
#define EMPTY -2 

typedef int Tree[MAX];

int parent(Tree T, int node){ // O(1), constant time
    return T[node] != ROOT && T[node] != EMPTY ? T[node] : -1;
}
void print_children(Tree T, int node) { // O(N), linear time
    int i;
    printf("\n");
    for (i = 0; i < MAX; i++) {
        if (T[i] == node) {
            printf("%d ", i);
        }
    }
}
int right_node(Tree T, int root) { // O(N)
    int i, r = -1;
    for (i = 0; i < MAX; i++) {
        if (T[i] == root) {
            r = i;
        }
    }
    return r;
}
int rightmost(Tree T, int root) { // ? O(N * Level)
    int r = right_node(T, root);
    if (r == -1) {
        return root;
    }
    return rightmost(T, r);
    // __builtin_unreachable();
}
void preorder(Tree T, int root) { // ? O(N * #elems)
    printf("%d ", root);
    for (int i = 0; i < MAX; i++) {
        if (root == T[i]) {
            preorder(T, i);
        }
    }
}

int main () {
    int root = 5;
    Tree T = {5, 6, 5, 6, 1, -1, 5, 1, 2, -2};
    printf("Parent of 9: %d\n", parent(T, 9));
    printf("Right Most Node: %d\n", rightmost(T, root));
    preorder(T, root);
    return 0;
}