#include<stdio.h>
#include<stdlib.h>
#define MAX 10

// both linked list and array implementation should contain the same boiler plate and processes. Only the code of the structures and  functions are altered.
typedef struct {
  char elem[MAX];
  int front;
  int rear;
}Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, char elem);
void dequeue(Queue *Q);
char peek(Queue Q);
void displayQueue(Queue Q);

int main(void){
  Queue Q;
  initQueue(&Q);
  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'C');
  displayQueue(Q);
  
  dequeue(&Q);
  dequeue(&Q);
  printf("\nafter dequeing: ");
  displayQueue(Q);
  
  printf("\nlets enqueue another element!: ");
  enqueue(&Q, 'D');
  displayQueue(Q);
    
    
  printf("\npeek on the value of front: %c", peek(Q));
  return 0;
}

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
    printf("\nrear: %d", Q.rear);
  }else{
    printf("queue is empty!");
  }
  
}

void initQueue(Queue *Q){
  Q->front = -1;
  Q->rear = -1;
}