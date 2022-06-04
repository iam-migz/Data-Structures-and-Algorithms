/*
    Edsger Dijkstra
    Single Source Shortest Paths
    Running Time:
    Adj. Matrix: O(n2)
    Adj. List with a priority queue: O(elogn)
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 999
#define MAX_VERTEX 6

typedef int Graph[MAX_VERTEX][MAX_VERTEX];

int *dijkstra(Graph G, int source, int vertices[]) {

    // 1. A bit-vector implementation of set
    int visited[MAX_VERTEX] = {0};

    // 2. initialize distance, set the edges of source vertex & mark it as visited
    int *distance = (int*)malloc(MAX_VERTEX * sizeof(int));
    if (distance == NULL) return NULL;

    for (int i = 0; i < MAX_VERTEX; i++) 
        distance[i] = G[source][i];

    visited[source] = 1;
 
    int next_vertex = source;
    for (int i = 1; i < MAX_VERTEX; i++) {
        int min_distance = INF;

        // 3. find the smallest edge that is not yet visited
        for (int x = 0; x < MAX_VERTEX; x++) {
            if (visited[x] == 0 && distance[x] < min_distance) {
                min_distance = distance[x];
                next_vertex = x;
            }
        }

        visited[next_vertex] = 1;

        // 4. update distance, minimum cost
        for (int x = 0; x < MAX_VERTEX; x++) {
            if (visited[x] == 0 && distance[x] > distance[next_vertex] + G[next_vertex][x]) {
                distance[x] = distance[next_vertex] + G[next_vertex][x];
            }
        }
    }
    distance[source] = 0;
    return distance;
}




int main() {

    Graph G = {
        {INF,  4,  2,INF,INF,INF},
        {  4,INF,INF,INF,  3,INF},
        {  2,INF,INF,  2,INF,  4},
        {INF,INF,  2,INF,  3,  1},
        {INF,  3,INF,  3,INF,  1},
        {INF,INF,  4,  1,  1,INF}
    }; 

    int vertices[MAX_VERTEX] = {0,1,2,3,4,5};
    int *distance = dijkstra(G, 0, vertices);
    for (int i = 0; i < MAX_VERTEX; i++) 
        printf("%d ", distance[i]);
    free(distance);

    return 0;
}