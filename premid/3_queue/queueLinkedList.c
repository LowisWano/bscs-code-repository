#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  char elem;
  struct node *next;
}*nodePtr, nodeType;

// front appears as first element pointed to by the head pointer, rear would be the last
typedef struct{
  nodePtr front;
  nodePtr rear;
}Queue;

// initializes queue by assigning null to the pointers
void initQueue(Queue *Q);

// inserts to the rear, if queue is empty set both rear and front to the same node, dont forget to check for malloc if successful
void enqueue(Queue *Q, char elem);

// deletes front, does not do anything if queue is empty
void dequeue(Queue *Q);

void displayQueue(Queue Q);

int main(void){
  Queue Q;
  initQueue(&Q);
  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'C');
  displayQueue(Q);
  
  dequeue(&Q);
  printf("\nafter dequeing: ");
  displayQueue(Q);
  
  printf("\nlets enqueue another element!: ");
  enqueue(&Q, 'D');
  displayQueue(Q);
  return 0;
}

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