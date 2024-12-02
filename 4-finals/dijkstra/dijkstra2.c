#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // Number of vertices

// Find vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Distance array
    int visited[V];  // Visited vertices

    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;    // Set all distances to infinity
        visited[i] = 0;       // Mark all nodes as unvisited
    }
    dist[src] = 0;  // Source distance = 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Get minimum distance vertex not yet processed
        int u = minDistance(dist, visited);
        visited[u] = 1;  // Mark as visited

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            // Update dist[v] if:
            // - Not visited
            // - Edge exists
            // - Path through u is smaller
            if (!visited[v] && 
                graph[u][v] && 
                dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print results
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
  };

    dijkstra(graph, 0);  // Find shortest paths from vertex 0
    return 0;
}