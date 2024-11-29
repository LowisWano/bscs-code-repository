#include<stdio.h>
#define MAX 6
#define MAX_ELEMS 99
#define X 999

/**
 * KRUSKAL'S ALGORITHM
 * 1. pick the edges with the smallest weight until all vertices have an edge
 * 2. no cycle
 */

typedef int AdjacencyMatrix[MAX][MAX];

typedef struct{
  int u;
  int w;
  int weight;
}edgeType;

typedef struct{
  edgeType edges[MAX_ELEMS];
  int count;
}edgeList;

typedef struct{
  edgeType edges[MAX_ELEMS];
  int count;
  int totalCost;
}MST;

edgeList createEdgeList(AdjacencyMatrix M);
void displayEdgeList(edgeList E);
MST MST_Kruskal(AdjacencyMatrix M);
void combineComponent(int comp[], int u, int w);
void displayMST(MST E);

int find(int comp[], int x) {
    while(comp[x] != x) {
        x = comp[x];
    }
    return x;
}

int main(void){

  AdjacencyMatrix M = {
    {0, 2, X, 8, X, X},
    {2, 0, X, 5, 6, X},
    {X, X, 0, X, 9, 3},
    {8, 5, X, 0, 3, 2},
    {X, 6, 9, 3, 0, 1},
    {X, X, 3, 2, 1, 0},
  };
  edgeList E = createEdgeList(M);
  displayEdgeList(E);


  MST T = MST_Kruskal(M);
  displayMST(T);
  return 0;
}

void combineComponent(int comp[], int u, int w) {
    int oldComponent = comp[w];
    int newComponent = comp[u];
    
    for(int i = 0; i < MAX; i++) {
        if(comp[i] == oldComponent) {
            comp[i] = newComponent;
        }
    }
}

MST MST_Kruskal(AdjacencyMatrix M){
  edgeList E = createEdgeList(M);
  MST mst;
  mst.count = 0;
  mst.totalCost = 0;

  int i;

  // initialize comp
  int comp[MAX];
  for(i=0;i<MAX; i++){
    comp[i] = i;
  }

  for(i=0; i<E.count; i++){
    int u = E.edges[i].u;
    int w = E.edges[i].w;
    int rootU = find(comp, u);
    int rootW = find(comp, w);
    if(rootU != rootW){
      combineComponent(comp, u, w);
      mst.edges[mst.count++] = E.edges[i];
      mst.totalCost += E.edges[i].weight;
    }
  }

  return mst;
}

edgeList createEdgeList(AdjacencyMatrix M){
   edgeList E;
   E.count = 0;

   int x, y;

   for(x=0;x<MAX;x++){
    for(y=x+1; y<MAX; y++){
      if(M[x][y] != X){
        edgeType edge;
        edge.u = x;
        edge.w = y;
        edge.weight = M[x][y];

        if(E.count < MAX_ELEMS){
          int i, j;
          for(i=0; i<E.count && edge.weight > E.edges[i].weight; i++){}
          for(j=E.count; j>i; j--){
            E.edges[j] = E.edges[j-1];
          }
          E.edges[i] = edge;
          E.count++;
        }
      }
    }
   }

   return E;
}

void displayMST(MST E) {
    printf("MST:\n");
    printf("Count: %d\n", E.count);
    printf("Total cost: %d\n", E.totalCost);
    for (int i = 0; i < E.count; i++) {
        printf("Edge %d: (%d, %d) Weight: %d\n", i, E.edges[i].u, E.edges[i].w, E.edges[i].weight);
    }
    printf("\n");
}

void displayEdgeList(edgeList E) {
    printf("Edge List:\n");
    printf("Count: %d\n", E.count);
    for (int i = 0; i < E.count; i++) {
        printf("Edge %d: (%d, %d) Weight: %d\n", i, E.edges[i].u, E.edges[i].w, E.edges[i].weight);
    }
    printf("\n");
}