#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

typedef struct{
  int elems[MAX];
  int last;
}Heap;

void initHeap(Heap *H);
void populateWithInsertAll(Heap *H);
void insertAllHeap(Heap *H, int elem);
void minHeapify(Heap *H);
void minHeapifySubtree(Heap *H, int subroot);
void heapSort(Heap *H);

void populateData(Heap *H);
void displayHeap(Heap H);

int main(void){
  Heap H;
  initHeap(&H);
  populateData(&H);
  minHeapify(&H);
  printf("Heapify: \n");
  displayHeap(H);

  Heap H2;
  initHeap(&H2);
  populateWithInsertAll(&H2);
  printf("Insert all: \n");
  displayHeap(H2);

  heapSort(&H);
  heapSort(&H2);

  printf("\n");
  displayHeap(H);
  displayHeap(H2);
  return 0;
}

void heapSort(Heap *H){
  int oldLast = H->last;
  while(H->last >= 0){
    int temp = H->elems[0];
    H->elems[0] = H->elems[H->last];
    H->elems[H->last--] = temp;
    minHeapify(H);
  }
  H->last = oldLast;
}

void insertAllHeap(Heap *H, int elem){
  if(H->last < MAX-1){
    H->elems[++(H->last)] = elem;
    int ch = H->last; 
    int p = (ch-1)/2;
    while(H->elems[ch] < H->elems[p]){
      int temp = H->elems[ch];
      H->elems[ch] = H->elems[p];
      H->elems[p] = temp;
      ch = p;
      p = (ch-1)/2;
    }
  }else{
    printf("Limit reached!\n");
  }
}

void populateWithInsertAll(Heap *H){
  int fixedValues[10] = {57, 45, 12, 56, 78, 89, 34, 67, 90, 11};
  for(int i = 0; i < 10; i++) {
    insertAllHeap(H, fixedValues[i]);
  }
  H->last = 9;
}

void minHeapify(Heap *H){
  int p;
  for(p = (H->last-1)/2; p>=0; p--){
    minHeapifySubtree(H, p);
  }
}

void minHeapifySubtree(Heap *H, int subroot){
  int LC = (2*subroot) + 1;
  int RC = (2*subroot) + 2; 
  int smallest = subroot;
  
  if(LC <= H->last && H->elems[LC] < H->elems[smallest]){
    smallest = LC;
  }

  if(RC <= H->last && H->elems[RC] < H->elems[smallest]){
    smallest = RC;
  }

  if(subroot != smallest){
    int temp = H->elems[subroot];
    H->elems[subroot] = H->elems[smallest];
    H->elems[smallest] = temp;
    minHeapifySubtree(H, smallest);
  }
  
}

void displayHeap(Heap H){
  if(H.last >= 0){
    for(int i=0;i<=H.last;i++){
      printf("%d ", H.elems[i]);
    }
  }else{
    printf("heap empty!");
  }
  printf("\n");
}

void populateData(Heap *H){
  int fixedValues[10] = {57, 45, 12, 56, 78, 89, 34, 67, 90, 11};
  for(int i = 0; i < 10; i++) {
    H->elems[i] = fixedValues[i];
  }
  H->last = 9;
}

void initHeap(Heap *H){
  H->last = -1;
}