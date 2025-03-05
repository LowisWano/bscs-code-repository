#include "../../utilities/general.h"
#include "../../utilities/test.h"

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
  test_sort_w_size(shell_sort);
  return 0;
}