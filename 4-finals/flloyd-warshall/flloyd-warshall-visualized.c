#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX

void printStep(int dist[][V], int k, int i, int j) {
    printf("\nChecking path from %d to %d through %d:\n", i, j, k);
    printf("Current distance: %d\n", dist[i][j] == INF ? -1 : dist[i][j]);
    printf("Path through k: %d + %d = %d\n", 
           dist[i][k] == INF ? -1 : dist[i][k],
           dist[k][j] == INF ? -1 : dist[k][j],
           (dist[i][k] == INF || dist[k][j] == INF) ? -1 : dist[i][k] + dist[k][j]);
    
    printf("\nCurrent Matrix:\n");
    for (int x = 0; x < V; x++) {
        for (int y = 0; y < V; y++) {
            if (x == i && y == j)
                printf("[%2d] ", dist[x][y] == INF ? -1 : dist[x][y]);
            else
                printf(" %2d  ", dist[x][y] == INF ? -1 : dist[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void floydWarshallVisualized(int graph[][V]) {
    int dist[V][V];
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        printf("\n=== Using vertex %d as intermediate ===\n", k);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    printStep(dist, k, i, j);
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        printf("Path updated! New value: %d\n", dist[i][j]);
                    }
                }
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {  0,  5,INF, 10},
        {INF,  0,  3,INF},
        {INF,INF,  0,  1},
        {INF,INF,INF,  0}
    };

    printf("Initial Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf(" %2d ", graph[i][j] == INF ? -1 : graph[i][j]);
        printf("\n");
    }

    floydWarshallVisualized(graph);
    return 0;
}