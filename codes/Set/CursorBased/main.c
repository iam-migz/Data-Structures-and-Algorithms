#include <stdio.h>
#include <stdlib.h>
#include "cursorbased.h"

typedef int SET;

SET get_intersection(Vheap *vs, SET A, SET B) {
    SET trav, C = -1; 

    for (; A != -1; A = vs->elements[A].next) {
        for (trav = B; 
        trav != -1 && vs->elements[trav].elem != vs->elements[A].elem; 
        trav = vs->elements[trav].next) {}
        
        if (vs->elements[trav].elem == vs->elements[A].elem) {
            SET temp = cb_allocate_space(vs);
            if (temp != -1) {
                vs->elements[temp].elem = vs->elements[A].elem;
                vs->elements[temp].next = C;
                C = temp;
            }
        }
    }
    return C;
}
SET get_union_unsorted(Vheap *vs, SET A, SET B) {
    SET temp, trav, C = -1;

    for (trav = A; trav != -1; trav = vs->elements[trav].next) {
        temp = cb_allocate_space(vs);
        if (temp != -1) {
            vs->elements[temp].elem = vs->elements[trav].elem;
            vs->elements[temp].next = C;
            C = temp;
        }
    }

    for (;B != -1; B = vs->elements[B].next) {
        for (trav = C; 
        trav != -1 && vs->elements[B].elem != vs->elements[trav].elem; 
        trav = vs->elements[trav].next) {}
        
        if (trav == -1) {
            temp = cb_allocate_space(vs);
            if (temp != -1) {
                vs->elements[temp].elem = vs->elements[B].elem;
                vs->elements[temp].next = C;
                C = temp;
            }
        }
    }

    return C;
}
SET get_union_sorted(Vheap *vs, SET A, SET B) {
    SET temp, C = -1;

    while (A != -1 && B != -1) {
        if (vs->elements[A].elem < vs->elements[B].elem) {
            temp = cb_allocate_space(vs);
            if (temp != -1) {
                vs->elements[temp].elem = vs->elements[A].elem;
                vs->elements[temp].next = C;
                C = temp;
            }
            A = vs->elements[A].next;
        } else {
            if (vs->elements[A].elem == vs->elements[B].elem) {
                A = vs->elements[A].next;
            }
            temp = cb_allocate_space(vs);
            if (temp != -1) {
                vs->elements[temp].elem = vs->elements[B].elem;
                vs->elements[temp].next = C;
                C = temp;
            }
            B = vs->elements[B].next;
        }
    }

    if (B != -1) {
        A = B;
    }

    while (A != -1) {
        temp = cb_allocate_space(vs);
        if (temp != -1) {
            vs->elements[temp].elem = vs->elements[A].elem;
            vs->elements[temp].next = C;
            C = temp;
        }
        A = vs->elements[A].next;
    }

    return C;
}
SET get_difference(Vheap *vs, SET A, SET B) {
    SET trav, C = -1; 

    for (; A != -1; A = vs->elements[A].next) {
        for (trav = B; 
        trav != -1 && vs->elements[trav].elem != vs->elements[A].elem; 
        trav = vs->elements[trav].next) {}
        
        if (trav == -1) {
            SET temp = cb_allocate_space(vs);
            if (temp != -1) {
                vs->elements[temp].elem = vs->elements[A].elem;
                vs->elements[temp].next = C;
                C = temp;
            }
        }
    }
    return C;
}

int main() {

    Vheap vs;
    cb_init(&vs);
    SET A, B;

    cb_populate_list(&vs, &A, (int[]){1,2,3,4}, 4);
    cb_populate_list(&vs, &B, (int[]){2,4,6,8}, 4);

    printf("SET A\n");
    cb_display_list(vs, A);

    printf("\n");
    
    printf("SET B\n");
    cb_display_list(vs, B);

    printf("\n");

    printf("SET C\n");
    SET C = get_intersection(&vs, A, B);
    // SET C = get_union_unsorted(&vs, A, B);
    // SET C = get_union_sorted(&vs, A, B);
    // SET C = get_difference(&vs, A, B);
    cb_display_list(vs, C);

    return 0;
}