#include<stdio.h>

void comb_sort(int arr[], int n);

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  comb_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

void comb_sort(int arr[], int n){
  // set gap = n
  int gap = n;
  int is_swapped = 1;

  // while gap > 1 and swapping still occurs
  while(gap>1 && is_swapped == 1){
    is_swapped = 0;
    gap = (int) gap/1.3;
    for(int i=0; i<n-gap; i++){
      if(arr[i] > arr[i+gap]){
        int temp = arr[i];
        arr[i] = arr[i+gap];
        arr[i+gap] = temp;
        is_swapped = 1;
      }
    }
  }
}


