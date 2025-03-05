#include "../../utilities/general.h"
#include "../../utilities/test.h"

void comb_sort(int arr[], int n);

int main(void){
  
  test_sort_w_size(comb_sort);
  return 0;
}

void comb_sort(int arr[], int n){
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


