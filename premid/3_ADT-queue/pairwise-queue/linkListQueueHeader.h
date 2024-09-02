#ifndef LLHEADER_H
#define LLHEADER_H

#include<stdio.h>
#include<stdlib.h>

// structures
typedef struct node{
  char elem;
  struct node *next;
}*nodePtr, nodeType;

typedef struct{
  nodePtr front;
  nodePtr rear;
}Queue;

// functions

/* initializes queue by assigning null to the pointers */
void initQueue(Queue *Q);

/* inserts to the rear, 
if queue is empty set both rear and front to the same node, 
dont forget to check for malloc if successful */
void enqueue(Queue *Q, char elem);

/* deletes front, does not do anything if queue is empty */
void dequeue(Queue *Q);

/* check value on front */
char peek(Queue Q);

/* print all values of queue */
void displayQueue(Queue Q);

#endif 
