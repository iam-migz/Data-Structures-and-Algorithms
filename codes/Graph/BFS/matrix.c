#include <stdio.h>

#define INF 999
#define MAX_VERTEX 9
#define Q_SIZE MAX_VERTEX*(MAX_VERTEX-1)

typedef int Graph[MAX_VERTEX][MAX_VERTEX];

void BFS(Graph G, int start) {

    int visited[MAX_VERTEX] = {0};
    // circular queue
    int queue[Q_SIZE], front = 1, back = 0;

    // enqueue start
    queue[++back] = start;

    // queue not empty
    while ((back+1)%(Q_SIZE) != front) {
        // dequeue
        int curr = queue[front];
        front = (front+1)%(Q_SIZE);

        if (visited[curr] == 0) {
            printf("%d ", curr);
            visited[curr] = 1;        
        }

        for (int i = 0; i < MAX_VERTEX; i++) {
            if (visited[i] == 0 && G[curr][i] == 100) {
                // enqueue
                back = (back+1)%(Q_SIZE);
                queue[back] = i;
            }
        }
    }
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

    BFS(G, 0);

    return 0;
}