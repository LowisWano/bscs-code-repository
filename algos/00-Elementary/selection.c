#include<stdio.h>

void selection_sort(int arr[], int n);

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  selection_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

// 
void selection_sort(int arr[], int n){
  int i, j;
  for(i=0; i<n; i++){
    int min = i;
    for(j=i+1; j<n; j++){
      if(arr[j]<arr[min]){
        min = j;
      }
    }
    if(i!=min){
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}


