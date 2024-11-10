#include<stdio.h>
#include<stdlib.h>
#define MAX 15

typedef struct{
  int Elem[MAX];
  int last;
}Heap;

void initHeap(Heap *H);
void displayHeap(Heap H);
void heapifyMin(Heap *H);

int main(void) {
  
  Heap H;
  int fixedValues[10] = {23, 45, 12, 56, 78, 89, 34, 67, 90, 11};
  for(int i = 0; i < 10; i++) {
    printf("%d ", fixedValues[i]);
    H.Elem[i] = fixedValues[i];
  }
  H.last = 9;
  printf("\n");
  
  heapifyMin(&H);
  displayHeap(H);

  return 0;
}

void heapifyMin(Heap *H){
  int P;
  for(P = (H->last - 1)/2; P >= 0; P--){
    int LC = P*2 + 1;
    int RC = P*2 + 2;
    int smallest = P;
    if(LC <= H->last && H->Elem[LC] < H->Elem[smallest]){
      smallest = LC;
    }
    if(RC <= H->last && H->Elem[RC] < H->Elem[smallest]){
      smallest = RC;
    }
    if(smallest != P){
      int temp = H->Elem[P];
      H->Elem[P] = H->Elem[smallest];
      H->Elem[smallest] = temp;
    }
  }
}

void displayHeap(Heap H){
  int i;
  for(i=0;i<=H.last;i++){
    printf("%d ", H.Elem[i]);
  }
  printf("\n");
}