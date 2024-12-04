#include "./functions.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void initQueue(Queue *Q){
  Q->front = 0;
  Q->rear = -1;
}

int isEmpty(Queue Q){
  return (Q.rear + 1) % V == Q.front ? 1 : 0;
}

int isFull(Queue Q){
  return (Q.rear + 2) % V == Q.front ? 1 : 0;
}

void enqueue(Queue *Q, int v){
  if(!isFull(*Q)){
    Q->rear = (Q->rear + 1) % V;
    Q->orderLine[Q->rear] = v;
  }
}

void dequeue(Queue *Q){
  if(!isEmpty(*Q)){
    Q->front = (Q->front + 1) % V;
  }
}

void bfs(AdjacencyMatrix graph, int src){
  Queue Q;
  initQueue(&Q);

  int visited[V] = {0};
  visited[src] = 1;
  
  enqueue(&Q, src);

  // as long as there are still adjacent unvisited vertices, the queue will have elements
  while(!isEmpty(Q)){
    // print front then dequeue
    int x = Q.orderLine[Q.front];
    printf("%d ", x);
    dequeue(&Q);

    // check for adjacent vertices then add them to the queue
    int y;
    for(y=0; y<V; y++){
      if(visited[y] == 0 && graph[x][y] != X){
        enqueue(&Q, y);
        visited[y] = 1;
      }
    }
  }
  printf("\n");
}