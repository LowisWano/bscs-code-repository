#include<stdio.h>
#define MAX 6
#define MAX_SIZE 20
#define X 999

typedef int Vertex;
typedef int LabelAdjMat[MAX][MAX];

typedef struct {
  int u, v;
  int weight;
}edgetype;

typedef struct {
  edgetype edges[MAX_SIZE];
  int lastNdx;
}minHeapOrList;

typedef struct {
  minHeapOrList eList;
  int cost;
}MST;

void displayMinHeap(minHeapOrList H);
void insertHeapify(minHeapOrList *H, edgetype e);
minHeapOrList createMinHeap(LabelAdjMat graph);
void heapifySubtree(minHeapOrList *H, int subroot);
edgetype deleteMin(minHeapOrList *H);

void displayMST(MST H){
  int i;
  for(i=0;i<=H.eList.lastNdx; i++){
      printf("%d | (%d, %d) : %d\n", i, H.eList.edges[i].u, H.eList.edges[i].v, H.eList.edges[i].weight);
  }
  printf("Total Cost: %d", H.cost);
  printf("\n \n");
}

int findRoot(int subsets[], int x){
	int i=x;
	while(i != subsets[i]){
		i = subsets[i];
	}
	return i;
}

void unionSubsets(int subsets[], int u, int w){
	int prevValue = subsets[w];
	int newValue = subsets[u];
	int i;
	for(i=0;i<MAX;i++){
		if(subsets[i] == prevValue){
			subsets[i] = newValue;
		}
	}
}

void kruskalMST(minHeapOrList H){
	MST M;
	M.eList.lastNdx = -1;
	M.cost = 0;
	
	int subsets[MAX];
	
	int i;
	for(i=0;i<MAX; i++){
		subsets[i] = i;
	}
	
	for(i=0; i<=H.lastNdx+1;){
		edgetype edge = deleteMin(&H);
		int uRoot = findRoot(subsets, edge.u);
		int vRoot = findRoot(subsets, edge.v);
		if(uRoot != vRoot){
			unionSubsets(subsets, uRoot, vRoot);
			M.eList.edges[++M.eList.lastNdx] = edge;
			M.cost += edge.weight;
			i++;
		}
	}
	
	displayMST(M);
}

void primsMST(minHeapOrList H){
	
}

int main(void){
  LabelAdjMat graph = {
    {X, 2, X, 8, X, X},
    {2, X, X, 5, 6, X},
    {X, X, X, X, 9, 3},
    {8, 5, X, X, 3, 2},
    {X, 6, 9, 3, X, 1},
    {X, X, 3, 2, 1, X},
};

  minHeapOrList H = createMinHeap(graph);
  displayMinHeap(H);
  kruskalMST(H);
  return 0;
}

edgetype deleteMin(minHeapOrList *H){
	edgetype temp = H->edges[0];
	H->edges[0] = H->edges[H->lastNdx--];
	heapifySubtree(H, 0);
	return temp;
}

void heapifySubtree(minHeapOrList *H, int subroot){
	int min = subroot;
	int LC = min*2 + 1;
	int RC = min*2 + 2;
	
	if(LC <= H->lastNdx && H->edges[LC].weight < H->edges[min].weight){
		min = LC;
	}
	
	if(RC <= H->lastNdx && H->edges[RC].weight < H->edges[min].weight){
		min = RC;
	}
	
	if(min != subroot){
		edgetype temp = H->edges[min];
		H->edges[min] = H->edges[subroot];
		H->edges[subroot] = temp;
		heapifySubtree(H, min);
	}
}

void insertHeapify(minHeapOrList *H, edgetype e){
  H->edges[++(H->lastNdx)] = e;
  int ch = H->lastNdx;
  int p = (ch-1) / 2;
  while(H->edges[ch].weight < H->edges[p].weight){
      edgetype temp = H->edges[ch];
      H->edges[ch] = H->edges[p];
      H->edges[p] = temp;
      ch = p;
      p=(ch-1)/2;
  }	
}


minHeapOrList createMinHeap(LabelAdjMat graph){
  minHeapOrList H;
  H.lastNdx = -1;
  int x, y;
  for(x=0; x<MAX; x++){
      for(y=x+1; y<MAX; y++){
        if(graph[x][y] != X){
          edgetype e;
            e.u = x;
            e.v = y;
            e.weight = graph[x][y];
            insertHeapify(&H, e);	
    }
      }
  }

  return H;
}

void displayMinHeap(minHeapOrList H){
  int i;
  for(i=0;i<=H.lastNdx; i++){
      printf("%d | (%d, %d) : %d\n", i, H.edges[i].u, H.edges[i].v, H.edges[i].weight);
  }
  printf("\n \n");
}