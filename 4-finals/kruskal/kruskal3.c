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

typedef struct{
  int parent;
  int rank;
}Subset;

void displayEdges(edgeList e);

edgeList createEdges(int graph[V][V]){
  edgeList E;
  E.count = 0;
  E.totalCost = 0;

  int x, y;
  for(x=0; x<V; x++){
    for(y=x+1; y<V; y++){
      if(graph[x][y] != X){
        edgeType e;
        e.from_vertext = x;
        e.to_vertex = y;
        e.cost = graph[x][y];

        // insert sorted
        int i;
        for(i=E.count-1; i>=0 && E.edges[i].cost > e.cost; i--){
          E.edges[i+1] = E.edges[i];
        }
        E.edges[i+1] = e;
        E.count++;
        E.totalCost += e.cost;
      }
      
    }
  }

  return E;
}

int findRoot(Subset subsets[], int v){
  int i=v;
  while(i != subsets[i].parent){
    i=subsets[i].parent;
  }
  return i;
}

void unionSet(Subset subsets[], int u, int w){
  if(subsets[u].rank > subsets[w].rank){
    subsets[w].parent = u;
  }else if(subsets[u].rank < subsets[w].rank){
    subsets[u].parent = w;
  }else{
    subsets[w].parent = u;
    subsets[u].rank++;
  }
}

edgeList kruskalMST(edgeList E){
  edgeList MST;
  MST.count = 0;
  MST.totalCost = 0;

  // create subsets and initialize
  Subset subsets[V];
  int i;
  for(i=0;i<V;i++){
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }

  // traverse E
  for(i=0; i<E.count; i++){
    int uRoot = findRoot(subsets, E.edges[i].from_vertext);
    int wRoot = findRoot(subsets, E.edges[i].to_vertex); 
    if(uRoot != wRoot){
      unionSet(subsets, uRoot, wRoot);
      // add to MST
      MST.edges[MST.count++] = E.edges[i];
      MST.totalCost += E.edges[i].cost;
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

  edgeList E = createEdges(graph);
  displayEdges(E);

  edgeList MST = kruskalMST(E);
  displayEdges(MST);
  return 0;
}

void displayEdges(edgeList e){
  int i;
  for(i=0;i<e.count;i++){
    printf("(%d, %d) -> %d\n", e.edges[i].from_vertext, e.edges[i].to_vertex, e.edges[i].cost);
  }
  printf("\n");
}