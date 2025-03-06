#include "../../utilities/general.h"
#include "../../utilities/test.h"

void comb_sort(int arr[], int n);

int main(void){
  
  test_sort_w_size(comb_sort);
  return 0;
}

void comb_sort(int arr[], int n){
  int gap = n;
  int swapped = 1;
  
  // Continue until gap is 1 and no swaps occur
  while(gap > 1 || swapped){
    // Update the gap
    gap = (int)gap / 1.3;
    if(gap < 1) gap = 1;
    
    swapped = 0;
    for(int i = 0; i < n - gap; i++){
      if(arr[i] > arr[i + gap]){
        int temp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = temp;
        swapped = 1;
      }
    }
  }
}


