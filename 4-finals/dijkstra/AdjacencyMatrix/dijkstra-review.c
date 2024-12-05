#include<stdio.h>
#include<limits.h>
#define V 6
#define X INT_MAX

typedef int LabeledAdjacencyMat[V][V];

int minDistance(int dist[], int visited[]){
  int i, min_index, min = X;
  for(i=0;i<V;i++){
    if(!visited[i] && dist[i] < min){
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

void dijkstra(LabeledAdjacencyMat graph, int src){
  // create dist array and visited set
  int dist[V];
  int visited[V]={0};

  int i;
  for(i=0;i<V;i++){
    dist[i] = X;
  }
  dist[src] = 0;
  
  for(i=0;i<V-1;i++){
    // smallest unvisited vertex in the dist array will be your current vertex
    int curr = minDistance(dist, visited);
    visited[curr] = 1;

    // update distance values based on the adjacent vertices to current vertex
    for(int y=0; y<V && dist[curr] != X; y++){
      if(!visited[y] && graph[curr][y] != X && dist[curr] + graph[curr][y] < dist[y]){
        dist[y] = dist[curr] + graph[curr][y];
      }
    }
  }

  for(i=0;i<V;i++){
    printf("Shortest path from 0 to %d: %d\n", i, dist[i]);
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