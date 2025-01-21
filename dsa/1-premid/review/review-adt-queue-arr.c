#include<stdio.h>
#define MAX 10

typedef struct {
  char name[24]; // Chocolate name
  int weight;    // Chocolate weight in grams
} chocoDesc;

typedef struct {
  char prodID[8];     //  product ID uniquely identifies the products; EMPTY or
  chocoDesc prodDesc; //  product description
  float prodPrice;    //  product price
  int prodQty;        //  product count or quantity
} product;            //  product record

typedef struct{
  product checkOutCounter[MAX];
  int front;
  int rear;
}Queue;

// FULL - 1 space between (strictly in range of 2 spaces)
// EMPTY - beside each other

void enqueue(Queue *Q, product p);
void dequeue(Queue *Q);
void initQueue(Queue *Q);

int isFull(Queue Q);
int isEmpty(Queue Q);
void populateQueue(Queue *Q);
void displayQueue(Queue Q);

int main(void){
  Queue Q;
  initQueue(&Q);

  populateQueue(&Q);
  displayQueue(Q);

  dequeue(&Q);
  dequeue(&Q);
  displayQueue(Q);
  
  return 0;
}

void displayQueue(Queue Q){
  while(!isEmpty(Q)){
    printf("%s - %d grams\n", Q.checkOutCounter[Q.front].prodDesc.name, Q.checkOutCounter[Q.front].prodDesc.weight);
    dequeue(&Q);
  }
  printf("\n");
}

int isFull(Queue Q){
  return (Q.rear + 2) % MAX == Q.front;
}

int isEmpty(Queue Q){
return (Q.rear + 1) % MAX == Q.front;
}

void dequeue(Queue *Q){
  if(!isEmpty(*Q)){
    Q->front = (Q->front + 1) % MAX;
  }
}

void enqueue(Queue *Q, product p){
  if(!isFull(*Q)){
    Q->rear = (Q->rear + 1) % MAX;
    Q->checkOutCounter[Q->rear] = p;
  }
}

void initQueue(Queue *Q){
  Q->front = 0;
  Q->rear = MAX -1;
}

void populateQueue(Queue *Q){
  const int COUNT = 15;
  product data[] = {
    {"1701", {"Toblerone", 135}, 150.75, 20},
    {"1356", {"Ferrero", 200}, 250.75, 85},
    {"1109", {"Patchi", 50}, 99.75, 35},
    {"1550", {"Cadbury", 120}, 200.00, 30},
    {"1807", {"Mars", 100}, 150.75, 20},
    {"1201", {"Kitkat", 50}, 97.75, 40},
    {"1450", {"Ferrero", 100}, 150.50, 50},
    {"1701", {"Toblerone", 50}, 90.75, 80},
    {"1601", {"Meiji", 75}, 75.50, 60},
    {"1310", {"Nestle", 100}, 124.50, 70},
    {"1807", {"Valor", 120}, 149.50, 90},
    {"1455", {"Tango", 75}, 49.50, 100},
    {"1703", {"Toblerone", 100}, 125.75, 60},
    {"1284", {"Lindt", 100}, 250.75, 15},
    {"1688", {"Guylian", 50}, 99.75, 35},
  };
  int i;
  for(i=0;i<COUNT;i++){
    enqueue(Q, data[i]);
  }
}
