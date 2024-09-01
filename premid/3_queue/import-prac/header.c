#include "./header.h"

void dequeue(Queue *Q){
    nodePtr temp;
  if(Q->front != NULL){
      temp = Q->front;
      Q->front = Q->front->next;
      free(temp);
  }
}

void enqueue(Queue *Q, char elem){
  nodePtr temp = malloc(sizeof(nodeType));
  if(temp != NULL){
    temp->elem = elem;
    temp->next = NULL;
    
    if(Q->rear != NULL){
      Q->rear->next = temp;
    }else{
      Q->front = temp;
    }
    Q->rear = temp;
  }
}

char peek(Queue Q){
  return Q.front->elem;
}

void displayQueue(Queue Q){
  nodePtr trav;
  printf("\n");
  for(trav=Q.front; trav != NULL; trav=trav->next){
    printf("%c ", trav->elem);
  }
}

void initQueue(Queue *Q){
  Q->front = NULL;
  Q->rear = NULL;
};
