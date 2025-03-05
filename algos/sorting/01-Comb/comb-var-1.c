#include "../../utilities/general.h"
#include "../../utilities/test.h"

void comb_sort(int arr[]);
void comb_sort_adapter(int arr[], int size);

int main(void){
  test_sort_w_size(comb_sort_adapter);

  return 0;
}

void comb_sort_adapter(int arr[], int size) {
  // Create a new array with size as the first element
  int* new_arr = (int*)malloc((size + 1) * sizeof(int));
  
  // Set first element as size
  new_arr[0] = size;
  
  // Copy the elements
  for (int i = 0; i < size; i++) {
    new_arr[i+1] = arr[i];
  }
  
  // Call the original comb sort
  comb_sort(new_arr);
  
  // Copy back the sorted elements
  for (int i = 0; i < size; i++) {
    arr[i] = new_arr[i+1];
  }
  
  // Free allocated memory
  free(new_arr);
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