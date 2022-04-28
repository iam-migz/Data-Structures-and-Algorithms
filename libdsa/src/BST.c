#include <stdio.h>
#include <stdlib.h>
#include "../inc/BST.h"
// preorder traversal
void print_tree(BST root, int level) { 
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf(i == level - 1 ? "|-" : "  ");
    }
    printf("%d\n", root->elem);
    print_tree(root->LC, level + 1);
    print_tree(root->RC, level + 1);
}
// postorder traversal
void destroy_tree(BST *root) {
    if (*root != NULL) {
        destroy_tree(&(*root)->LC);
        destroy_tree(&(*root)->RC);
        free(*root);
    }
}