#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 5
#define HEAP_SIZE 20

typedef struct node{
  int label;
  int cost;
  struct node *next;
}*Vertex, VType;

typedef struct{
  Vertex connections[MAX_VERTICES];
  int edgeCount;
}AdjList;

typedef struct {
    int u, v;
    int weight;
} EdgeType;

typedef struct {
    EdgeType edges[HEAP_SIZE];
    int lastNdx;
} MinHeapList;

typedef struct {
    MinHeapList eList;
    int cost;
} MST;

void displayList(AdjList L);
void initAdjList(AdjList *L);
void insertEdge(AdjList *L, int entry[3]);

void insertHeapify(MinHeapList *H, EdgeType edge){
  H->edges[++(H->lastNdx)] = edge;

  int ch = H->lastNdx;
  int p = (ch-1)/2;

  while(p >= 0 && H->edges[ch].weight < H->edges[p].weight){
    EdgeType temp = H->edges[ch];
    H->edges[ch] = H->edges[p];
    H->edges[p] = temp;
    ch = p;
    p = (ch-1)/2;;
  }

}

// createMinHeap
MinHeapList createMinHeap(AdjList L){
  MinHeapList H;
  H.lastNdx = -1;

  int i;
  Vertex trav;
  for(i=0;i<MAX_VERTICES;i++){
    for(trav=L.connections[i]; trav!=NULL; trav=trav->next){
      EdgeType e;
      e.u = i;
      e.v = trav->label;
      e.weight = trav->cost;
      insertHeapify(&H, e);
    }
  }
  
  return H;
}

void heapifySubtree(MinHeapList *H, int subroot){
  int min = subroot;
  int LC = (2*min) + 1;
  int RC = (2*min) + 2;

  if(LC <= H->lastNdx && H->edges[LC].weight < H->edges[min].weight){
    min = LC;
  }

  if(RC <= H->lastNdx && H->edges[RC].weight < H->edges[min].weight){
    min = RC;
  }

  if(min != subroot){
    EdgeType temp = H->edges[min];
    H->edges[min] = H->edges[subroot];
    H->edges[subroot] = temp;
    heapifySubtree(H, min);
  }
}

// deleteMin
EdgeType deleteMin(MinHeapList *H){
  EdgeType temp = H->edges[0];
  H->edges[0] = H->edges[(H->lastNdx)--];
  heapifySubtree(H, 0);
  return temp;
}

//isComponentOne
int isComponentOne(int subsets[]){
  int i;
  for(i=1; i<MAX_VERTICES && subsets[i] == subsets[i-1]; i++){}
  printf("i: %d\n", i);
  return (i==(MAX_VERTICES)) ? 1 : 0;
}

// findRoot
int findRoot(int subsets[], int x) {
  while (x != subsets[x]) {
    x = subsets[x];
  }
  return x;
}

// union components
void unionSubsets(int subsets[], int u, int v){
  int prevValue = v;
  int newValue = u;
  for(int i=0; i<MAX_VERTICES; i++){
    if(subsets[i] == prevValue){
      subsets[i] = newValue;
    }
  }
}

void displayMinHeap(MinHeapList PQ, int totalCost) {
  printf("\n");
  for(int i = 0; i <= PQ.lastNdx; i++) {
      printf("(%d, %d): %d\n", PQ.edges[i].u, PQ.edges[i].v ,PQ.edges[i].weight);
  }
  printf("\nTotal cost: %d", totalCost);
  printf("\n");
}

// use minHeap
void kruskalMST(AdjList L){
  MST resultMST;
  resultMST.eList.lastNdx = -1;
  resultMST.cost = 0;
  
  MinHeapList H = createMinHeap(L);

  int subsets[MAX_VERTICES];
  for(int i=0; i<MAX_VERTICES; i++){
    subsets[i] = i;
  }

  while(H.lastNdx >= 0) {
    EdgeType e = deleteMin(&H);

    int uRoot = findRoot(subsets, e.u);
    int vRoot = findRoot(subsets, e.v);

    if(uRoot != vRoot){
      unionSubsets(subsets, e.u, e.v);
      insertHeapify(&(resultMST.eList), e);
      resultMST.cost += e.weight;
    }
  }

  displayMinHeap(resultMST.eList, resultMST.cost);
}

int main(void){
  AdjList L;
  initAdjList(&L);

  // burst fade parin to ya? oo burst fade yan kaso lang v cut
  int data[][3] = {
    {0, 1, 9},  // First row
    {0, 3, 6},
    {1, 2, 3},  // Second row
    {1, 3, 8},
    {1, 4, 5},
    {2, 4, 7},  // Third row
    {3, 4, 9}   // Fourth row
  };
  int dataCount = sizeof(data) / sizeof(data[0]);

  for(int i=0; i<dataCount; i++){
    insertEdge(&L, data[i]);
  }

  displayList(L);

  kruskalMST(L);

  return 0;
}


void insertEdge(AdjList *L, int entry[3]){
  Vertex temp = (Vertex) malloc(sizeof(VType));

  // (source, destination, weight)
  if(temp!=NULL){
    temp->next = L->connections[entry[0]];
    L->connections[entry[0]] = temp;

    temp->label = entry[1];
    temp->cost = entry[2];
  }

  temp = (Vertex) malloc(sizeof(VType));

  if(temp!=NULL){
    temp->next = L->connections[entry[1]];
    L->connections[entry[1]] = temp;

    temp->label = entry[0];
    temp->cost = entry[2];
  }
}

void initAdjList(AdjList *L){
  L->edgeCount = 0;
  int i;
  for(i=0;i<MAX_VERTICES;i++){
    L->connections[i] = NULL;
  }
}

void displayList(AdjList L) {
    for(int i = 0; i < MAX_VERTICES; i++) {
        printf("Node %d: ", i);
        for(Vertex curr = L.connections[i]; curr != NULL; curr = curr->next) {
            printf("(v: %d, cost: %d) ", curr->label, curr->cost);
        }
        printf("\n");
    }
}