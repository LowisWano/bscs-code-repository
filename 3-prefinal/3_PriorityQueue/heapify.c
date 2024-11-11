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
int deleteMin(Heap *H);
void populateData(Heap *H);
void heapSort(Heap *H, int arr[]);

int main(void) {
  
  Heap H;
  
  populateData(&H);
  int sortedArray[10];
  
  heapSort(&H, sortedArray);

  for(int i = 0; i < 10; i++) {
    printf("%d ", sortedArray[i]);
  }
  printf("\n");
  
  return 0;
}

void heapSort(Heap *H, int arr[]){
  int i=0;
  heapifyMin(H);
  while(H->last >= 0){
    arr[i++] = deleteMin(H);
  }
}

void populateData(Heap *H){
  int fixedValues[10] = {23, 45, 12, 56, 78, 89, 34, 67, 90, 11};
  for(int i = 0; i < 10; i++) {
    printf("%d ", fixedValues[i]);
    H->Elem[i] = fixedValues[i];
  }
  printf("\n");
  H->last = 9;
}

int deleteMin(Heap *H){
  int root = H->Elem[0];
  H->Elem[0] = H->Elem[H->last];
  H->Elem[H->last] = root;
  H->last--;
  heapifyMin(H);
  return root;
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
  if(H.last >= 0){
    int i;
    for(i=0;i<=H.last;i++){
      printf("%d ", H.Elem[i]);
    }
  }else{
    printf("heap empty!");
  }
  printf("\n");
}