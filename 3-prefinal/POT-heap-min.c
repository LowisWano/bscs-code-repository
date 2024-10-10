#include<stdio.h>
#include<stdlib.h>
#define MAX 15

typedef struct{
  int Elem[MAX];
  int last;
}Heap;

void initHeap(Heap *H);
void insert(Heap *H, int elem);
void preorder(Heap H, int node);

int main(void){
  Heap H;
  initHeap(&H);
  insert(&H, 3);
  insert(&H, 2);
  insert(&H, 9);
  insert(&H, 6);
  insert(&H, 4);
  insert(&H, 5);
  insert(&H, 10);
  insert(&H, 18);
  insert(&H, 1);

  for(int i=0;i<=H.last;i++){
    printf("%d ", H.Elem[i]);
  }
  printf("\nPreorder: ");
  preorder(H, 0);

  printf("\n");
}

void preorder(Heap H, int node){
  if(node < MAX && H.Elem[node]!=-1){
    printf("%d, ", H.Elem[node]);
    preorder(H, (node*2)+1);
    preorder(H, (node*2)+2);
  }
}

void insert(Heap *H, int elem){

  // check if last < max
  if(H->last < MAX){
    // insert
    H->Elem[++H->last] = elem;
    
    // swap child and parent if POT is not satisfied
    int temp;
    int c = H->last;
    int p = (c-1)/2;
    while(H->Elem[c] < H->Elem[p]){
      temp = H->Elem[c];
      H->Elem[c] = H->Elem[p];
      H->Elem[p] = temp;
      c = p;
      p = (c-1)/2;
    }
  }
}

void initHeap(Heap *H){
  int i;
  for(i=0;i<MAX;i++){
    H->Elem[i] = -1;
  }
  H->last = -1;
}