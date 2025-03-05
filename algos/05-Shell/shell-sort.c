#include<stdio.h>


void shell_sort(int arr[], int n){
  int gap = n/2;
  int i, j;
  while(gap>0){
    for(i=gap; i<n; i++){
      int temp = arr[i];
      for(j=i; j>=gap && arr[j-gap]>temp; j -= gap){
        arr[j] = arr[j-gap];
      }
      arr[j] = temp;
    }
    gap /= 2;
  }
}

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  shell_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}