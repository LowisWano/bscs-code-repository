#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define V 6
#define X 9999


typedef int AdjacencyMatrix[V][V];

typedef struct {
  int orderLine[V];
  int front;
  int rear;
}Queue;

int isEmpty(Queue Q);
void enqueue(Queue *Q, int v);
void dequeue(Queue *Q);
void initQueue(Queue *Q);
void bfs(AdjacencyMatrix graph, int src);

#endif