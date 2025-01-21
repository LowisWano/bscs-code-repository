#include<stdio.h>
#define V 6
#define X 9999

typedef int LabeledAdjacencyMat[V][V];

typedef struct{
  int distance;
  int prev;
}DistSet;

int minDistance(DistSet dist[], int visited[]){
  int i, min_index, min_weight = X;
  for(i=0;i<V;i++){
    if(!visited[i] && dist[i].distance < min_weight){
      min_index = i;
      min_weight = dist[i].distance;
    }
  }
  return min_index;
}

char numToLetter(int num) {
    return (char)('A' + num);
}


void displayPath(DistSet visited[], int src){
  if(visited[src].prev != -1){
    printf("\t<- %c", numToLetter(visited[src].prev));
    displayPath(visited, visited[src].prev);
  }
}

// only difference is input x together when updating dist
void dijkstra(LabeledAdjacencyMat graph, int src) {
  int visited[V];
  DistSet dist[V];

  for(int i=0;i<V;i++){
    visited[i] = 0;
    dist[i].distance = X;
    dist[i].prev = -1;
  }
  dist[src].distance = 0;

  for(int count=0; count < V-1; count++){
    // get min distance from dist set
    int x = minDistance(dist, visited);
    visited[x] = 1;

    // update dist values based from information on the weights of the currently connected nodes
    for(int y=0; y<V && dist[x].distance != X; y++){
      if(!visited[y] && graph[x][y] != X && dist[x].distance + graph[x][y] < dist[y].distance){
        dist[y].distance = dist[x].distance + graph[x][y];
        dist[y].prev = x;
      }
    }
  }

  // display path
  printf("Vertex \t Distance from Source\n");
  for(int i=0;i<V; i++){
    printf("%c \t\t %d ", numToLetter(i), dist[i].distance);
    displayPath(dist, i);
    printf("\n");
  }
}


// goal is to output the shortest path from a src vertex and its corresponding path taken
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