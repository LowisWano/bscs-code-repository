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

  enqueue(&Q, src);
  visited[src] = 1;

  while(!isEmpty(Q)){
    // get value of current vertex in the queue
    int curr = Q.orderLine[Q.front];
    printf("%d ", curr);
    dequeue(&Q);

    // check for adjacent vertices and add them to the queue and mark visited
    int y;
    for(y=0;y<V;y++){
      if(visited[y] == 0 && graph[curr][y] != X){
        enqueue(&Q, y);
        visited[y] = 1;
      }
    }
  }
  printf("\n");
}