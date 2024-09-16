#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10 // actual maximum number of elements is 9

typedef struct{
  char elems[MAX]; // sacrifice 1 cell to identify if queue is full
  int front;
  int rear;
}Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, char elem);
void dequeue(Queue *Q);
void read(Queue Q);
int isFull(Queue Q);
int isEmpty(Queue Q);

int main(void){
 Queue Q;
 initQueue(&Q);
  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'C');
  enqueue(&Q, 'D');
  read(Q);
}

void read(Queue Q){
  if(isEmpty(Q)){
    printf("queue is empty");
  }
  
  while(!isEmpty(Q)){
    int val;
    val = Q.elems[Q.front];
    printf("%c ", val);
    dequeue(&Q);
  }
  printf("\n");
}

/**
 * an empty queue needs rear to be behind front
 */
void initQueue(Queue *Q){
  Q->front = 0;
  Q->rear = MAX-1;
}

/**
 * If rear is 2 blocks behind front, stack is full
 */
int isFull(Queue Q){
  return (Q.rear + 2) % MAX == Q.front;
}

/**
 * If rear is directly behind front, stack is empty
 */
int isEmpty(Queue Q){
  return (Q.rear + 1) % MAX == Q.front;
}

/**
 * x % MAX resets x to 0 if max index has reached
 * 
 */
void enqueue(Queue *Q, char elem){
  if(!isFull(*Q)){
    Q->rear = (Q->rear + 1) % MAX;
    Q->elems[Q->rear] = elem;
  }
}

void dequeue(Queue *Q){
  if(!isEmpty(*Q)){
    Q->front = (Q->front + 1) % MAX;
  }
}