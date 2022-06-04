#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define MAX_VERTEX 9 
// #define MAX_EDGES 72 // n(n-1) 

typedef NodePtr Graph[MAX_VERTEX];

void init_and_populate(Graph G) {
    for (int i = 0; i < MAX_VERTEX; i++)
        G[i] = NULL;
    
    ll_populate_list(&G[0], (int[]){1, 3, 4}, 3);
    ll_populate_list(&G[1], (int[]){5}, 1);
    ll_populate_list(&G[2], (int[]){1, 3}, 2);
    ll_populate_list(&G[3], (int[]){2, 7}, 2);
    ll_populate_list(&G[4], (int[]){7}, 1);
    ll_populate_list(&G[5], (int[]){8, 6}, 2);
    ll_populate_list(&G[6], (int[]){1, 2}, 2);
    ll_populate_list(&G[8], (int[]){7}, 1);
}
void graph_make_null(Graph G) {
    for (int i = 0; i < MAX_VERTEX; i++)
        ll_make_null(&G[i]);
}

void DFS(Graph G, int visited[], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (NodePtr trav = G[vertex]; trav != NULL; trav = trav->next) 
        if (visited[trav->data] == 0)
            DFS(G, visited, trav->data);
}

void DFS_iterative(Graph G, int start) {

    int vis[MAX_VERTEX] = {0};

    vis[start] = 1;
    printf("%d ", start);

    int stack[1000];
    int top = -1;

    stack[++top] = start;

    while (top >= 0) {
        int curr = stack[top--];
        if (vis[curr] == 0) {
            vis[curr] = 1;
            printf("%d ", curr);
        }
        for (NodePtr trav = G[curr]; trav != NULL; trav = trav->next) {
            if (vis[trav->data] == 0) {
                stack[++top] = trav->data;
            }
        }
    }
}

int main() {

    Graph G;
    init_and_populate(G);

    int visited[MAX_VERTEX] = {0};
    DFS(G, visited, 0);
    printf("\n");
    DFS_iterative(G, 0);

    graph_make_null(G);
    return 0;
}