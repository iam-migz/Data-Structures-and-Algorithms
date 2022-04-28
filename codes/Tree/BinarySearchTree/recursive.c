#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void insert(BST *B, int elem) { 
    if (*B == NULL) {
        *B = (BST)calloc(1, sizeof(NodeType));
        if (*B != NULL) {
            (*B)->elem = elem;
        }
    } else if ((*B)->elem == elem) {
        printf("%d is not unique\n", elem);
    } else if ((*B)->elem > elem) {
        insert(&(*B)->LC, elem);
    } else {
        insert(&(*B)->RC, elem);
    }
}

int delete_min(BST *B) {
    BST temp;
    int ret;
    if ((*B)->LC == NULL) {
        temp = *B;
        *B = temp->RC;
        ret = temp->elem;
        free(temp);
        return ret;
    } else {
        return delete_min(&(*B)->LC);
    }
}

void delete(BST *B, int elem) {
    BST temp;
    if (*B == NULL) {
        printf("node not found\n");
    } else if (elem == (*B)->elem) {
        if ((*B)->RC == NULL) {
            temp = *B; 
            *B = temp->LC;
            free(temp);
        } else if ((*B)->LC == NULL) {
            temp = *B; 
            *B = temp->RC;
            free(temp);
        } else {
            (*B)->elem = delete_min(&(*B)->RC);
        }
    } else if (elem < (*B)->elem) {
        delete(&(*B)->LC, elem);
    } else {
        delete(&(*B)->RC, elem);
    }
}

int member(BST B, int elem) {
    if (B == NULL){
        return 0;
    } else if (B->elem == elem) {
        return 1;
    } else if (B->elem > elem) {
        return member(B->LC, elem);
    } else {
        return member(B->RC, elem);
    }
}
int get_max(BST B) {
    if (B->RC == NULL) {
        return B->elem;
    } else {
        return get_max(B->RC);
    }
}
int get_min(BST B) {
    if (B->LC == NULL) {
        return B->elem;
    } else {
        return get_min(B->LC);
    }
}
void preorder(BST B) {
    if (B != NULL) {
        printf("%d ", B->elem);
        preorder(B->LC);
        preorder(B->RC);
    }
}
void inorder(BST B) {
    if (B != NULL) {
        inorder(B->LC);
        printf("%d ", B->elem);
        inorder(B->RC);
    }
}
void postorder(BST B) {
    if (B != NULL) {
        postorder(B->LC);
        postorder(B->RC);
        printf("%d ", B->elem);
    }
}


int main() {

    BST myBST = NULL;
    insert(&myBST, 10);
    insert(&myBST, 5);
    insert(&myBST, 12);
    insert(&myBST, 1);
    insert(&myBST, 8);
    insert(&myBST, 11);
    insert(&myBST, 14);

    printf("preorder: ");
    preorder(myBST);
    printf("\n");

    printf("inorder: ");
    inorder(myBST);
    printf("\n");

    printf("postorder: ");
    postorder(myBST);
    printf("\n");
    
    // delete(&myBST, 5);
    // printf("is 4 a member of the BST: %s\n", member(myBST, 4)==1?"YES":"NO");
    // printf("Maximum is %d\n", get_max(myBST));
    // printf("Minimum is %d\n", get_min(myBST));
    print_tree(myBST, 1);
    destroy_tree(&myBST);
    return 0;
}