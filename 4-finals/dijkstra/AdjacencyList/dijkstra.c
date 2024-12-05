#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 9999

typedef int Set[MAX];

typedef struct node {
  int label;
  int weight;
  struct node *next;
} *Vertex;

typedef Vertex AdjList[MAX];

/*
  AdjList M:
  source - destination
  [0] ->   (dest: 1, weight: 2) -> (dest: 2, weight: 4)
  [1] ->   (dest: 0, weight: 2) -> (dest: 2, weight: 1) -> (dest: 3, weight: 7)
  [2] ->   (dest: 0, weight: 4) -> (dest: 1, weight: 1) -> (dest: 4, weight: 3)
  [3] ->   (dest: 1, weight: 7) -> (dest: 4, weight: 2)
  [4] ->   (dest: 2, weight: 3) -> (dest: 3, weight: 2)

*/

int* dijkstras(AdjList M, int root);
void displayDjk(int arr[], int root);
void initList(AdjList M);
void insertEdge(AdjList M, int edge[3]);
void displayList(AdjList M);

int minDistance(int dist[], Set visited){
  int i, min_index, min=INF;
  for(i=0;i<MAX;i++){
    if(!visited[i] && dist[i] < min){
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

int* dijkstras(AdjList M, int src){
  int i;
  
  Set visited = {0};

  int *dist = malloc(sizeof(int)*MAX);
  for(i=0;i<MAX;i++){
    dist[i] = INF;
  }
  dist[src] = 0;

  for(i=0; i < MAX-1; i++){
    int curr = minDistance(dist, visited);
    visited[curr] = 1;

    Vertex trav;
    for(trav=M[curr]; trav!=NULL; trav=trav->next){
      if(visited[trav->label] == 0 && dist[curr] + trav->weight < dist[trav->label]){
        dist[trav->label] = dist[curr] + trav->weight;
      }
    }
  }

  return dist;
}

int main(void){
  int edges[][3] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3}, 
        {4, 3, 2}   
    };

    int numOfEdges = sizeof(edges) / sizeof(edges[0]);
    
    AdjList M;
    initList(M);

    for(int i = 0; i < numOfEdges; i++) {
        insertEdge(M, edges[i]);
    }

    displayList(M);

    int root = 0;
    int *djk = dijkstras(M, root);
    displayDjk(djk, root);

    return 0;

  return 0;
}

void displayDjk(int arr[], int root) {
    printf("\nLUIS: Dijkstra's Paths from %d:\n", root);
    for(int i = 0; i < MAX; i++) {
        
        printf("Path from %d to %d: ", root, i);
        (arr[i] == 0) ? printf("NONE\n") : printf("%d\n", arr[i]);
    }
}

void initList(AdjList M) {
    for(int i = 0; i < MAX; i++) {
        M[i] = NULL;
    }
}

// insert first, both at two positions, 
void insertEdge(AdjList M, int edge[3]) {
    Vertex temp = (Vertex) malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->label = edge[1];
        temp->weight = edge[2];
        temp->next = M[edge[0]];
        M[edge[0]] = temp;
    }

    temp = (Vertex) malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->label = edge[0];
        temp->weight = edge[2];
        temp->next = M[edge[1]];
        M[edge[1]] = temp;
    }
}

void displayList(AdjList M) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(Vertex curr = M[i]; curr != NULL; curr = curr->next) {
            printf("%d ", curr->label);
        }
        printf("\n");
    }
}