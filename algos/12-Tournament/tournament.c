#include<stdio.h>

void tournament_sort(int arr[], int n);

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  tournament_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}