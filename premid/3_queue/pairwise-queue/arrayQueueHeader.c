#include "./arrayQueueHeader.h"

void dequeue(Queue *Q){
  if(Q->rear >= 0){
    int s;
    for(s=0;s<Q->rear;s++){
      Q->elem[s] = Q->elem[s+1];
    }
    Q->rear--;
  }
}

void enqueue(Queue *Q, char elem){
 if(Q->rear < MAX){
  Q->elem[++Q->rear] = elem;
  if(Q->front < 0){
    Q->front = 0;
  }
 }
}

char peek(Queue Q){
  if(Q.front < 0){
    printf("\nqueue is empty!");
    return '0';
  }
  return Q.elem[Q.front];
}

void displayQueue(Queue Q){
  if(Q.rear >= 0){
    int i;
    for(i=0;i<=Q.rear;i++){
      printf("%c ", Q.elem[i]);
    }
  }else{
    printf("queue is empty!");
  }
  
}

void initQueue(Queue *Q){
  Q->front = -1;
  Q->rear = -1;
}