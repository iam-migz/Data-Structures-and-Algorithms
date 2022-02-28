#include <stdio.h>

#include "ll_helper.h"

int main() {

    int array[] = {1,2,3};
    NodePtr head = NULL;
    ll_populate_list(&head, array, 3);
    ll_display(head);
    ll_make_null(&head);
    printf("head: %p", head);

    return 0;
}