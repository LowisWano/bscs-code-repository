#include<stdio.h>

void insertion_sort(int arr[], int n);

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  insertion_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
// shift until left side is smaller than curr
void insertion_sort(int arr[], int n){
  int i, j;
  for(i=1;i<n; i++){
    int temp = arr[i];
    for(j=i; j>0 && arr[j-1] > temp; j--){
      arr[j] = arr[j-1];
    }
    arr[j] = temp;
  }
}


