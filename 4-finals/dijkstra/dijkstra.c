#include<stdio.h>
#define V 5
#define INF 9999

int minDistance(int visited[], int dist[]){
  int i, min_index = -1, min_weight = INF;
  for(i=0;i<V;i++){
    if(!visited[i] && dist[i] < min_weight){
      min_index = i;
      min_weight = dist[i];
    }
  }
  return min_index;
}

void dijkstra(int graph[V][V], int src){
  int visited[V];
  int dist[V];

  for(int i=0;i<V;i++){
    dist[i] = INF;
    visited[i] = 0;
  }

  dist[src] = 0;

  int count;
  for(count=0;count<V-1;count++){
    // get smallest weight from distance set
    int x = minDistance(visited, dist);
    visited[x] = 1;

    // update distance set based on currently connected nodes
    int y;
    for(y=0;y<V;y++){
      if(!visited[y] && graph[x][y] != INF && dist[x] != INF && dist[x] + graph[x][y] < dist[y]){
        dist[y] = dist[x] + graph[x][y];
      }
    }
  }

  printf("Vertex \t Distance from Source\n");
  for (int i = 0; i < V; i++) {
      printf("%d \t\t %d\n", i, dist[i]);
  }
}

int main() {
    int graph[V][V] = {
    {INF, 2, INF, 6, INF},
    {2, INF, 3, 8, 5},
    {INF, 3, INF, INF, 7},
    {6, 8, INF, INF, 9},
    {INF, 5, 7, 9, INF}
  };

    dijkstra(graph, 0);  // Find shortest paths from vertex 0
    return 0;
}