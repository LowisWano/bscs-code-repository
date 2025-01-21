#include<stdio.h>
#define V 6
#define X 9999

typedef int LabeledAdjacencyMat[V][V];

typedef struct{
  int distance;
  int prev;
}DistSet;

int minDistance(int visited[], DistSet dist[]){
  int i, min_index, min = X;
  for(i=0;i<V;i++){
    if(visited[i] == 0 && dist[i].distance < min){
      min = dist[i].distance;
      min_index = i;
    }
  }
  return min_index;
}

void dijkstras(LabeledAdjacencyMat graph, int src){
  DistSet dist[V];
  int visited[V];
  
  // init dist and visited
  int i;
  for(i=0;i<V;i++){
    visited[i] = 0;
    dist[i].distance = X;
    dist[i].prev = -1;
  }
  dist[src].distance = 0;

  for(i=0;i<V-1;i++){
    int x = minDistance(visited, dist);
    visited[x] = 1;
    
    int y;
    for(y=0;y<V;y++){
      if(visited[y] == 0 && graph[x][y] != X && dist[x].distance + graph[x][y] < dist[y].distance){
        dist[y].distance = dist[x].distance + graph[x][y];
        dist[y].prev = x;
      }
    }
  }

  printf("Shortest path from %d\n", src);
  for(i=0;i<V;i++){
    printf("%c\t%d\t", 'A' + i, dist[i].distance);
    
    int j=i;
    while(dist[j].prev != -1){
      printf(" <- %c", 'A' + dist[j].prev);
      j=dist[j].prev;
    }
    printf("\n");
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

  dijkstras(graph, 0);
  return 0;
}