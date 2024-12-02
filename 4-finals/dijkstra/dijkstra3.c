#include<stdio.h>
#define V 6
#define X 9999

typedef int LabeledAdjacencyMat[V][V];

int minDistance(int visited[], int dist[]){
  int i, min_index = -1, min_weight = X;
  for(i=0;i<V;i++){
    if(!visited[i] && dist[i] < min_weight){
      min_index = i;
      min_weight = dist[i];
    }
  }
  return min_index;
}

void dijkstra(LabeledAdjacencyMat graph, int src){
  int visited[V];
  int dist[V];

  for(int i=0;i<V;i++){
    visited[i] = 0;
    dist[i] = X;
  }

  dist[src] = 0;

  for(int count = 0; count < V-1; count++){
    // find smallest weight from dist set and mark as visited
    int x = minDistance(visited, dist);
    visited[x] = 1;

    // update dist values based on the connected nodes to the current node
    for(int y = 0; y < V && dist[x] != X ; y++){
      if(!visited[y] && graph[x][y] != X && dist[x] + graph[x][y] < dist[y]){
        dist[y] = dist[x] + graph[x][y];
      }
    }
  }

  printf("Vertex \t Distance from Source\n");
  for (int i = 0; i < V; i++) {
      printf("%d \t\t %d\n", i, dist[i]);
  }
}

int main(void){

  LabeledAdjacencyMat graph = {
    {X, 2, X, 8, X, X},
    {2, X, X, 5, 6, X},
    {X, X, X, X, 9, 3},
    {8, 5, X, X, 3, 2},
    {X, 6, 9, 3, X, 1},
    {X, X, 3, 2, 1, X},
  };

  dijkstra(graph, 0);
  return 0;
}