#include<stdio.h>

int hoare_partition(int arr[], int start, int end);
void quicksort(int arr[], int start, int end);

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  quicksort(arr, 0, n-1);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}

int hoare_partition(int arr[], int start, int end){
  int i = start;
  int j = end;
  int pivot = arr[start];

  while(i<j){
    while(i<end && arr[i] < pivot){
      i++;
    }

    while(j>=0 && arr[j] > pivot){
      j--;
    }

    if(i<j){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  
  return j;
}

void quicksort(int arr[], int start, int end){
  if(start<end){
    int i = hoare_partition(arr, start, end);
    quicksort(arr, start, i);
    quicksort(arr, i+1, end);
  }
}