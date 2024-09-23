#include<stdio.h>
#include<stdlib.h>
#define VH_SIZE 15

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

typedef struct {
  product elem;
  int next;
} prodNode; // Product node, used in cursor-based implementation of Set

/************************
 * Virtual Heap         *
 ************************/
typedef struct {
  prodNode VH_node[VH_SIZE];
  int avail;
} VHeap;

typedef int List;

typedef struct{
  List front;
  List rear;
}Queue;

void enqueue(VHeap *VH, Queue *Q, product elem);
void dequeue(VHeap *VH, Queue *Q);

void populateQueue(VHeap *VH, Queue *Q);

void initVHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int ndx);
int initQueue(Queue *q);
void displayQueue(VHeap VH, Queue Q);

int main(void){
  VHeap VH;
  initVHeap(&VH);

  Queue q;
  initQueue(&q);

  populateQueue(&VH, &q);
  displayQueue(VH, q);

  dequeue(&VH, &q);
  dequeue(&VH, &q);
  displayQueue(VH, q);

  return 0;
}

void populateQueue(VHeap *VH, Queue *Q){
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
    enqueue(VH, Q, data[i]);
  }
}

void dequeue(VHeap *VH, Queue *Q){
  if(Q->front != -1){
    int temp = Q->front;
    Q->front = VH->VH_node[temp].next;
    deallocSpace(VH, temp);
    
    if(Q->front == -1){
      Q->rear = -1;
    }
  }
}

void displayQueue(VHeap VH, Queue Q){
  printf("\n");
  while(Q.front != -1){
    printf("%s - %d grams\n", VH.VH_node[Q.front].elem.prodDesc.name, VH.VH_node[Q.front].elem.prodDesc.weight);
    dequeue(&VH, &Q);
  }
}

void enqueue(VHeap *VH, Queue *Q, product prod){
  int temp = allocSpace(VH);
  if(temp != -1){
    VH->VH_node[temp].elem = prod;
    VH->VH_node[temp].next = -1;
    if(Q->rear == -1){
      Q->front = temp;
    }else{
      VH->VH_node[Q->rear].next = temp;
    }
    Q->rear = temp;
  }
}

int initQueue(Queue *q){
  q->front = -1;
  q->rear = -1;
}

void deallocSpace(VHeap *VH, int ndx){
  VH->VH_node[ndx].next = VH->avail;
  VH->avail = ndx;
}

int allocSpace(VHeap *VH){
  int ndx = VH->avail;
  if(ndx != -1){
    VH->avail = VH->VH_node[ndx].next;
  }
  return ndx;
}

void initVHeap(VHeap *VH){
  int i;
  for(i=0;i<VH_SIZE;i++){
    VH->VH_node[i].next = i-1;
  }
  VH->avail = VH_SIZE-1;
}