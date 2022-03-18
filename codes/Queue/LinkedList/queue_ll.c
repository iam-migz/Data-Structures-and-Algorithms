#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} NodeType, *NodePtr;

typedef struct {
    NodePtr front;
    NodePtr back;
} Queue;

void init_queue(Queue *q) {
    q->front = NULL;
    q->back = NULL;
}

int isFull() {
    return 1;
}

int isEmpty(Queue q) {
    return q.front == NULL ? 1 : 0;
}

void enqueue(Queue *q, int data) {
    NodePtr temp = malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = NULL;

        if (q->front == NULL) {
            q->front = temp;
        } else {
            q->back->next = temp;
        }
        q->back = temp;
    }
}

int dequeue(Queue *q) {
    int retval = -1;
    NodePtr temp;
    if (!isEmpty(*q)) {
        temp = q->front;
        q->front = temp->next;
        retval = temp->data;
        if (q->front == NULL) {
            q->back = NULL;
        }
        free(temp);
    }
    return retval;
}

void display_queue(Queue q) {
    while (q.front != NULL) {
        printf("%d ", q.front->data);
        q.front = q.front->next;
    }
}

// using a temp queue
void insert_sorted(Queue *q, int data) {
    Queue c;
    NodePtr temp;
    init_queue(&c);
    
    while (q->front != NULL && data > q->front->data) {
        temp = q->front;

        // dequeue in the orig. queue
        q->front = temp->next;

        // enqueue to the temp queue
        if (c.front == NULL) {
            c.front = temp;
        } else {
            c.back->next = temp;
        }
        c.back = temp;
    }

    // *insert_last to the new queue 
    temp = malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = NULL;
        if (c.back == NULL) {
            c.front = temp;
        } else {
            c.back->next = temp;
        }
        c.back = temp;
    }

    // empty the orig queue if there is any left
    while (q->front != NULL) {
        temp = q->front;
        q->front = temp->next;

        c.back->next = temp;
        c.back = temp;
    }

    // return all contents back to the orig. queue
    while (c.front != NULL) {
        temp = c.front;
        c.front = temp->next;
        if (q->front == NULL) {
            q->front = temp;
        } else {
            q->back->next = temp;
        }
        q->back = temp;
    }
}


void ll_make_null(NodePtr *L) {
    NodePtr temp;
    while (*L != NULL) {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

int main() {

    Queue q;
    init_queue(&q);
    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 6);
    insert_sorted(&q, 5);
    ll_make_null(&q.front);
    return 0;
}