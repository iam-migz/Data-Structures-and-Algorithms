#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

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

int isFull(Queue q) {
    return 1;
}

int isEmpty(Queue q) {
    return q.front == NULL ? 1 : 0;
}

#endif