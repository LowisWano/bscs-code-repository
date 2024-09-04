#ifndef ARRHEADER_H
#define ARRHEADER_H

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct {
  char elem[MAX];
  int front;
  int rear;
}Queue;

// functions
void initQueue(Queue *Q);
void enqueue(Queue *Q, char elem);
void dequeue(Queue *Q);
char peek(Queue Q);
void displayQueue(Queue Q);

#endif 