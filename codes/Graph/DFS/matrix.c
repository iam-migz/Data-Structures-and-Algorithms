#include <stdio.h>


#define INF 9999
#define MAX_VERTEX 9

typedef int Graph[MAX_VERTEX][MAX_VERTEX];

void DFS(Graph G, int visited[], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < MAX_VERTEX; i++) 
        if (visited[i] == 0 && G[vertex][i] != INF) 
            DFS(G, visited, i);
}

int main() {

    Graph G = {
        {INF,100,INF,100,100,INF,INF,INF,INF},
        {INF,INF,INF,INF,INF,100,INF,INF,INF},
        {INF,100,INF,100,INF,INF,INF,INF,INF},
        {INF,INF,100,INF,INF,INF,INF,100,INF},
        {INF,INF,INF,INF,INF,INF,INF,100,INF},
        {INF,INF,INF,INF,INF,INF,100,INF,100},
        {INF,100,INF,INF,INF,INF,INF,INF,INF},
        {INF,INF,INF,INF,INF,INF,INF,INF,INF},
        {INF,INF,INF,INF,INF,INF,INF,100,INF}
    }; 

    
    int visited[MAX_VERTEX] = {0};
    DFS(G, visited, 0);

    return 0;
}