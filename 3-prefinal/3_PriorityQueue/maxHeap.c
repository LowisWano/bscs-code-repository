#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

typedef struct {
  int Elems[MAX];
  int last;  
}Heap;

void initHeap(Heap *H);
void insertPOT(Heap *H, int elem);

void maxHeapify(Heap *H);
void deleteMin(Heap *H);
void heapSort(Heap *H);
void populateData(Heap *H);
void displayHeap(Heap H);

void heapifySubtree(Heap *H, int node, int last);

int main(void){

  Heap H;
  populateData(&H);
  displayHeap(H);
  
  heapSort(&H);
  displayHeap(H);
  return 0;
}

/**
 * swap subroot with the biggest child. If swap occurs, perform heapsort on the position of the child that was swapped until
 * heapsorting reaches the bottom.
 */
void heapifySubtree(Heap *H, int subroot, int last){
  int max = subroot;
  int LC = subroot*2 + 1;
  int RC = subroot*2 + 2;
  
  if(LC <= last && H->Elems[LC] > H->Elems[max]){
    max = LC;
  }

  if(RC <= last && H->Elems[RC] > H->Elems[max]){
    max = RC;
  }

  if(subroot != max){
    int temp = H->Elems[subroot];
    H->Elems[subroot] = H->Elems[max];
    H->Elems[max] = temp;

    // heapify the node which replaced the subroot
    heapifySubtree(H, max, last);
  }
}

/**
 * start heapifying from the parent of the last node until it reaches the root
 */
void maxHeapify(Heap *H){
  int i;
  for(i=(H->last-1)/2;i>= 0; i--){
    heapifySubtree(H, i, H->last);
  }
}

/**
 * maxHeap the array first, then swap root and last node. Decrement last because it is already in its proper place. Repeat until everything
 * is in its proper place
 */
void heapSort(Heap *H){
  int origLast = H->last;;
  for(int i=H->last; i>=0; i--){
    maxHeapify(H);
    int temp = H->Elems[0];
    H->Elems[0] = H->Elems[H->last];
    H->Elems[H->last--] = temp;
  }
  H->last = origLast;
}

void populateData(Heap *H){
  int fixedValues[10] = {23, 45, 12, 56, 78, 89, 34, 67, 90, 11};
  for(int i = 0; i < 10; i++) {
    H->Elems[i] = fixedValues[i];
  }
  H->last = 9;
}

void displayHeap(Heap H){
  if(H.last >= 0){
    int i;
    for(i=0;i<=H.last;i++){
      printf("%d ", H.Elems[i]);
    }
  }else{
    printf("heap empty!");
  }
  printf("\n");
}

void initHeap(Heap *H){
  H->last = -1;
}
