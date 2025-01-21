#include <stdio.h>
#include <stdlib.h>
#define MAX_V 6
#define INF 9999

typedef int AdjacencyMatrix[MAX_V][MAX_V];
typedef int Set[MAX_V];

typedef struct node {
  int label;
  int weight;
  struct node *next;
} *Vertex;

typedef Vertex AdjList[MAX_V];

typedef struct {
  int orderLine[MAX_V];
  int front;
  int rear;
}Queue;

void initList(AdjList M);
void insertEdge(AdjList M, int edge[3]);
void displayList(AdjList M);
void bfs(AdjList L, int src);

int isEmpty(Queue Q){
  return (Q.rear + 1) % MAX_V == Q.front ? 1 : 0;
}

int isFull(Queue Q){
  return (Q.rear + 2) % MAX_V == Q.front ? 1 : 0;
}

void enqueue(Queue *Q, int v){
  if(!isFull(*Q)){
    Q->rear = (Q->rear + 1) % MAX_V;
    Q->orderLine[Q->rear] = v;
  }
}

void dequeue(Queue *Q){
  if(!isEmpty(*Q)){
    Q->front = (Q->front + 1) % MAX_V;
  }
}

void bfs(AdjList L, int src){
  Queue Q;
  Q.front = 0;
  Q.rear = -1;

  int visited[MAX_V]={0};
  visited[src] = 1;
  enqueue(&Q, src);

  // while queue is not empty
  while((Q.rear + 1) % MAX_V != Q.front){
    int x = Q.orderLine[Q.front];
    printf("%d ", x);
    dequeue(&Q);

    Vertex trav;
    for(trav=L[x]; trav!=NULL; trav=trav->next){
      if(visited[trav->label] == 0){
        enqueue(&Q, trav->label);
        visited[trav->label] = 1;
      }
    }
  }
  printf("\n");
}

/*
  AdjList M:
  source - destination
  [0] ->   (dest: 1, weight: 2) -> (dest: 2, weight: 4)
  [1] ->   (dest: 0, weight: 2) -> (dest: 2, weight: 1) -> (dest: 3, weight: 7)
  [2] ->   (dest: 0, weight: 4) -> (dest: 1, weight: 1) -> (dest: 4, weight: 3)
  [3] ->   (dest: 1, weight: 7) -> (dest: 4, weight: 2)
  [4] ->   (dest: 2, weight: 3) -> (dest: 3, weight: 2)
*/

int main(void){
  int edges[][3] = {
    {0, 1, 2},
    {0, 3, 8},
    {1, 0, 2},
    {1, 3, 5},
    {1, 4, 6},
    {2, 4, 9},
    {2, 5, 3},
    {3, 0, 8},
    {3, 1, 5},
    {3, 4, 3},
    {3, 5, 2},
    {4, 1, 6},
    {4, 2, 9},
    {4, 3, 3},
    {4, 5, 1},
    {5, 2, 3},
    {5, 3, 2},
    {5, 4, 1},
  };

    int numOfEdges = sizeof(edges) / sizeof(edges[0]);
    
    AdjList M;
    initList(M);

    for(int i = 0; i < numOfEdges; i++) {
        insertEdge(M, edges[i]);
    }

    displayList(M);
    bfs(M, 0);
  return 0;
}


void initList(AdjList M) {
    for(int i = 0; i < MAX_V; i++) {
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
    for(int i = 0; i < MAX_V; i++) {
        printf("Node %d: ", i);
        for(Vertex curr = M[i]; curr != NULL; curr = curr->next) {
            printf("%d ", curr->label);
        }
        printf("\n");
    }
}