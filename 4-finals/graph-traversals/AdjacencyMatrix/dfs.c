#include<stdio.h>
#define V 6
#define X 9999

void dfs(int graph[V][V], int curr, int visited[]);

int main(void){
  int graph[V][V] = {
    {0, 2, X, 8, X, X},
    {2, 0, X, 5, 6, X},
    {X, X, 0, X, 9, 3},
    {8, 5, X, 0, 3, 2},
    {X, 6, 9, 3, 0, 1},
    {X, X, 3, 2, 1, 0},
  };

  int visited[V] = {0};

  dfs(graph, 0, visited);
  printf("\n");
  return 0;
}

void dfs(int graph[V][V], int curr, int visited[]){
  visited[curr] = 1;
  printf("%d ", curr);

  int y;
  for(y=0;y<V;y++){
    if(visited[y] == 0 && graph[curr][y] != X){
      dfs(graph, y, visited);
    }
  }
}