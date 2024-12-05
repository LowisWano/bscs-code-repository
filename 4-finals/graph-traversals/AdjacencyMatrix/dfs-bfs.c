#include<stdio.h>
#define V 6
#define X 9999

typedef struct{
  int vertex;
  int weight;
}Edge;

typedef struct{
  int conn[V];
  int rear, front;
}Queue;

void dfs(int graph[V][V], int curr, int visited[]);
void bfs(int graph[V][V], int curr, int visited[]);

int isFull(Queue Q){
  return (Q.rear + 2) % V == Q.front;
}

int isEmpty(Queue Q){
  return (Q.rear + 1) % V == Q.front;
}

void enqueue(Queue *Q, int e){
  if(!isFull(*Q)){
    Q->rear = (Q->rear % V) + 1;
    Q->conn[Q->rear] = e;
  }
}

void dequeue(Queue *Q){
  if(!isEmpty(*Q)){
    Q->front = (Q->front + 1) % V;
  }
}

int checkIfAllVisited(int visited[]){
  int i;
  for(i=0;i<V && visited[i] == 1;i++){}
  return (i==V)? 1: 0;
}

int main(void){
  int graph[V][V] = {
    {X, 2, X, 8, X, X},
    {2, X, X, 5, 6, X},
    {X, X, X, X, 9, 3},
    {8, 5, X, X, 3, 2},
    {X, 6, 9, 3, X, 1},
    {X, X, 3, 2, 1, X},
  };

  int visited[V] = {0};

  // dfs(graph, 0, visited);
  bfs(graph, 0, visited);
  printf("\n");

  return 0;
}

void bfs(int graph[V][V], int curr, int visited[]) {
    Queue Q;
    Q.front = 0;
    Q.rear = -1;
    
    
    printf("%d ", curr);
    visited[curr] = 1;
    enqueue(&Q, curr);
    
    // while the queue is not empty
    while (!isEmpty(Q)) {
        // 
        int x = Q.conn[Q.front];  
        dequeue(&Q);
        
        // Check all adjacent vertices
        for (int y = 0; y < V; y++) {
            if (!visited[y] && graph[x][y] != X) {
                printf("%d ", y);
                visited[y] = 1;
                enqueue(&Q, y);
            }
        }
    }
}

void dfs(int graph[V][V], int curr, int visited[]){
  visited[curr] = 1;
  int y=0;
  printf("%d ", curr);
  for(y=0; y<V;y++){
    if(visited[y] != 1 && graph[curr][y] != X){
      dfs(graph, y, visited);
    }
  }
}