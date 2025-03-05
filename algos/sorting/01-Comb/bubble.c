#include<stdio.h>

void bubble_sort(int arr[], int n);

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  bubble_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

void bubble_sort(int arr[], int n){
  int i, j;
  for(i=0;i<n-1;i++){
    for(j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}