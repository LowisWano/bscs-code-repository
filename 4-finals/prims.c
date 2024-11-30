#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 5  // Number of vertices
#define INF 999

void printMST(int MST[V][V]);

int checkIfAllVisited(int visited[]){
  int i;
  for(i=0;i<V && visited[i] == 1;i++){}
  return (i == V) ? 1: 0;
}

void primMST(int graph[V][V]) {
    int MST[V][V] = {0};
    int visited[V] = {0};
    
    visited[0] = 1; 
    
    while (!checkIfAllVisited(visited)) {
        int min_weight = INF;
        int from_vertex = -1;
        int to_vertex = -1;
        
        // Check all edges from MST to non-MST vertices
        for (int i = 0; i < V; i++) {
            if (visited[i]) {  // If vertex is in MST
                for (int j = 0; j < V; j++) {
                    // Find minimum weight edge to unvisited vertex
                    if (!visited[j] && graph[i][j] != 0 && graph[i][j] < min_weight) {
                        min_weight = graph[i][j];
                        from_vertex = i;
                        to_vertex = j;
                    }
                }
            }
        }
        
        if (to_vertex != -1) {
            MST[from_vertex][to_vertex] = min_weight;
            MST[to_vertex][from_vertex] = min_weight;
            visited[to_vertex] = 1;
        }
    }
    
    printMST(MST);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}

void printMST(int MST[V][V]) {
    printf("Edge \tWeight\n");
    
    // Only need to check upper triangle of matrix since undirected
    for(int i = 0; i < V; i++) {
        for(int j = i + 1; j < V; j++) {
            if(MST[i][j] != 0) {  // If edge exists
                printf("%d - %d \t%d\n", i, j, MST[i][j]);
            }
        }
    }
}