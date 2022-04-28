#ifndef BST_H
#define BST_H

typedef struct node {
    int elem;
    struct node *LC, *RC;
} NodeType, *BST;

void print_tree(BST root, int level);
void destroy_tree(BST *root);

#endif