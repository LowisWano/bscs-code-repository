#include "../../utilities/general.h"
#include "../../utilities/test.h"

void bubble_sort(int arr[], int n);

int main(void){
  test_sort_w_size(bubble_sort);
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