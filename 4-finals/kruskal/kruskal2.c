#include<stdio.h>
#define MAX 6
#define X 999
#define MAX_ELEMS 99

typedef int Matrix[MAX][MAX];

typedef struct {
  int source;
  int destination;
  int cost;
}Flight;

typedef struct{
  Flight flights[MAX_ELEMS];
  int count;
  int totalCost;
}edgeList;

edgeList convertMatrixToEdgeList(Matrix M);
void getKruskalMST(edgeList E);
void displayEdgeList(edgeList E);
int findRoot(int subsets[], int v);

int main(void){

  Matrix M = {
    {X, 2, X, 8, X, X},
    {2, X, X, 5, 6, X},
    {X, X, X, X, 9, 3},
    {8, 5, X, X, 3, 2},
    {X, 6, 9, 3, X, 1},
    {X, X, 3, 2, 1, X},
  };

  edgeList E = convertMatrixToEdgeList(M);

  displayEdgeList(E);
  getKruskalMST(E);
  return 0;
}

// find root vertex
int findRoot(int subsets[], int v){
  int i;
  for(i=v; subsets[i] != i; i=subsets[i]){}
  return i;
}

void unionComponents(int subsets[], int x, int y){
  int prevValue = subsets[y];
  int newValue = subsets[x];

  int i;
  for(i=0;i<MAX;i++){
    if(subsets[i] == prevValue){
      subsets[i] = newValue;
    }
  }
}

void getKruskalMST(edgeList E){
  edgeList MST;
  MST.count = 0;
  MST.totalCost = 0;

  int subsets[MAX];
  int i;
  for(i=0;i<MAX;i++){
    subsets[i] = i;
  }

  for(i=0;i<E.count;i++){
    if(findRoot(subsets, E.flights[i].source) != findRoot(subsets, E.flights[i].destination)){
      unionComponents(subsets, E.flights[i].source, E.flights[i].destination);
      MST.flights[MST.count++] = E.flights[i];
      MST.totalCost+= E.flights[i].cost;
    }
  }

  displayEdgeList(MST);
}

edgeList convertMatrixToEdgeList(Matrix M) {
  edgeList E;
  E.count = 0;
  E.totalCost = 0;

  int x, y;
  for(x=0;x<MAX;x++){
    for(y=x+1;y<MAX;y++){
      if(M[x][y] != X){
        Flight F;
        F.destination = x;
        F.source = y;
        F.cost = M[x][y];

        int i;
        for(i=E.count-1;i>=0 && E.flights[i].cost > F.cost; i--){
          E.flights[i+1] = E.flights[i];
        }
        E.flights[i+1] = F;
        E.count++;
        E.totalCost += F.cost;
      }
    }
  }

  return E;
}

void displayEdgeList(edgeList E) {
    printf("Count: %d\n", E.count);
    printf("Total cost: %d\n", E.totalCost);
    for (int i = 0; i < E.count; i++) {
        printf("Edge %d: (%d, %d) Weight: %d\n", i, E.flights[i].source, E.flights[i].destination, E.flights[i].cost);
    }
    printf("\n");
}