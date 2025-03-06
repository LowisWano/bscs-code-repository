#include<stdio.h>
#define MAX 8

void bubbleSort(int arr[]){
  int i,j;
  printf("Bubble sort: \n");
  for(i=0;i<MAX;i++){
    for(j=i+1;j<MAX;j++){
      if(arr[i] > arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void insertionSort(int arr[]){
  int i, j;
  printf("Insertion sort:\n");
  for(i=1;i<MAX;i++){
    int key = i;
    for(j=i-1; arr[key] < arr[j] && j > 0; j--, key--){
      int temp = arr[key];
      arr[key] = arr[j];
      arr[j] = temp;
    }
  }
}

void selectionSort(int arr[]){
  int i, j, min;
  printf("Selection sort: \n");
  for(i=0;i<MAX;i++){
    min = i;
    for(j=i+1;j<MAX;j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

void displayData(int arr[]){
  int i;
  for(i=0;i<MAX;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void){
  int arr[MAX] = {1, 6, 5, 4, 2, 3, 9, 7};
  // bubbleSort(arr);
  // insertionSort(arr);
  selectionSort(arr);
  displayData(arr);
  return 0;
}