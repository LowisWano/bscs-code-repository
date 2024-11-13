#include<stdio.h>
#include<stdlib.h>
#define MAX 15

void populateData(int heap[], int *count);
void minHeapifySubtree(int heap[], int subroot, int last);
void displayHeap(int heap[], int count);
void minHeapify(int heap[], int last);
void heapSort(int heap[], int size);

int main(void){

  int heap[MAX];
  int count = 0;
  populateData(heap, &count);
  displayHeap(heap, count);

  heapSort(heap, count);
  displayHeap(heap, count);
  return 0;
}

void heapSort(int heap[], int size){
  for(int i=size-1; i>=0; i--){
    minHeapify(heap, i);
    int temp = heap[0];
    heap[0] = heap[i];
    heap[i] = temp;
  }
}

void minHeapify(int heap[], int last){
  int i;
  for(i=(last-1)/2; i>=0; i--){
    minHeapifySubtree(heap, i, last);
  }
}

void minHeapifySubtree(int heap[], int subroot, int last){
  int min = subroot;
  int LC = (subroot*2)+1; 
  int RC = (subroot*2)+2; 

  if(LC <= last && heap[LC] < heap[min]){
    min = LC;
  }

  if(RC <= last && heap[RC] < heap[min]){
    min = RC;
  }

  if(subroot != min){
    int temp = heap[subroot];
    heap[subroot] = heap[min];
    heap[min] = temp;
    minHeapifySubtree(heap, min, last);
  }
}

void displayHeap(int heap[], int count){
  int i;
  for(i=0;i<count;i++){
    printf("%d ", heap[i]);
  }
  printf("\n");
}

void populateData(int heap[], int *count){
  int fixedValues[10] = {23, 45, 12, 56, 78, 89, 34, 67, 90, 11};
  for(; *count < 10; (*count)++) {
    heap[*count] = fixedValues[*count];
  }
}