#include "../../utilities/general.h"
#include "../../utilities/test.h"

void heap_sort(int arr[], int size);
void heapify(int arr[], int subroot, int size);

int main(void){
  test_sort_w_size(heap_sort);

  return 0;
}

// build heap
// swap root and last elem then decrement size
void heap_sort(int arr[], int size){
  int i;
  for(i=size/2-1; i>= 0; i--){
    heapify(arr, i, size);
  }

  for(i=size-1; i>= 0; i--){
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, 0, i);
  }
}

// maxheapify
void heapify(int arr[], int subroot, int size){
  int max = subroot;
  int LC = 2*subroot + 1;
  int RC = 2*subroot + 2;

  if(LC < size && arr[LC] > arr[max]){
    max = LC;
  }

  if(RC < size && arr[RC] > arr[max]){
    max = RC;
  }

  if(subroot != max){
    int temp = arr[subroot];
    arr[subroot] = arr[max];
    arr[max] = temp;
    heapify(arr, max, size);
  }
  
}