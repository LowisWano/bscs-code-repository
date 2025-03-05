#include<stdio.h>

void comb_sort(int arr[]);

int main(void){
  int arr[] = {0, 12, 34, 54, 2, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);
  arr[0] = n;

  comb_sort(arr);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}

void comb_sort(int arr[]){
  int i, gap = arr[0];
  int is_swapped = 1;
  for(;gap>1 && is_swapped == 1;){
    is_swapped = 0;
    gap = (int)gap/1.3;
    for(i=1;i<arr[0]-gap ;i++){
      if(arr[i] > arr[i+gap]){
        int temp = arr[i];
        arr[i] = arr[i+gap];
        arr[i+gap] = temp;
        is_swapped=1;
      }
    }
  }
}