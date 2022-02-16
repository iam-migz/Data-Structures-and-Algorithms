#ifndef STACK_CB
#define STACK_CB

void push(Vheap *vh, int *stack, int elem) {
    int temp = allocate_space(vh);
    if (temp != -1) {
        vh->elements[temp].elem = elem;
        vh->elements[temp].next = *stack;
        *stack = temp;
    }
}

void pop(Vheap *vh, int *stack) {
    if (*stack != -1) {
        int temp = *stack;
        *stack = vh->elements[*stack].next;        
        deallocate_space(vh, temp);
    }
}

int top(Vheap vh, int stack) {
    return stack != -1 ? vh.elements[stack].elem : -1;
}

void display_and_delete_all(Vheap *vh, int *stack) {
    while (*stack != -1) {
        printf("%d, ", top(*vh, *stack));
        pop(vh, stack);
    }
    printf("\n");
}



#endif
