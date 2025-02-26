#include<stdio.h>


void shell_sort(int arr[], int n){
  int gap;
  for(gap = n/2; gap > 0; gap=gap/2){
    for(int i = gap; i < n; i++){
      int key = arr[i];
      int j;

      for(j=i; j>=gap && arr[j-gap] > key; j=j-gap){
        arr[j] = arr[j-gap];
      }

      arr[j] = key;
    }
  }
}

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  shell_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  // printf("\n");
  return 0;
}