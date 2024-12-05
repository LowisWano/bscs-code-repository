#include<stdio.h>
#define V 5
#define MAX_ELEMS 40
#define X 999

typedef struct{
  int from_vertext;
  int to_vertex;
  int cost;
}edgeType;

typedef struct{
  edgeType edges[MAX_ELEMS];
  int count;
  int totalCost;
}edgeList;

void displayEdges(edgeList e){
  int i;
  for(i=0;i<e.count;i++){
    printf("(%d, %d) -> %d\n", e.edges[i].from_vertext, e.edges[i].to_vertex, e.edges[i].cost);
  }
  printf("\n");
}

int checkIfAllVisited(int visited[]){
  int i;
  for(i=0;i<V && visited[i] == 1;i++){}
  return (i==V) ? 1: 0;
}

edgeList primMST(int graph[V][V]){
  edgeList MST;
  MST.count = 0;
  MST.totalCost = 0;

  int visited[V] = {0};
  visited[0] = 1;

  while(!checkIfAllVisited(visited)){
    int min_weight = X;
    int from = X;
    int to = X;

    int row;
    for(row=0; row<V; row++){
      if(visited[row] == 1){
        int col;
        for(col=0; col<V; col++){
          if(visited[col] == 0 && graph[row][col] != X && graph[row][col] < min_weight){
            min_weight = graph[row][col];
            from = row;
            to = col;
          }
        }
      }
    }

    if(min_weight != X){
      edgeType e;
      e.cost = min_weight;
      e.from_vertext = from;
      e.to_vertex = to;

      MST.edges[MST.count++] = e;
      MST.totalCost += e.cost;

      visited[to] = 1;
    }
  }

  return MST;
}

int main(void){
  int graph[V][V] = {
    {X, 9, X, 6, X},
    {9, X, 3, 8, 5},
    {X, 3, X, X, 7},
    {6, 8, X, X, 9},
    {X, 5, 7, 9, X}
  };

  edgeList e = primMST(graph);
  displayEdges(e);
  return 0;
}
