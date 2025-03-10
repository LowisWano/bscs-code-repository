#include "../../utilities/general.h"
#include "../../utilities/test.h"

void merge_sort(int arr[], int size);
void merge(int arr[], int low, int mid, int high);

int main(void){
  test_sort_w_size(merge_sort);
  return 0;
}

void merge_sort(int arr[], int size) {
  int curr_size;
  int left_start;

  for(curr_size = 1; curr_size < size; curr_size *= 2){
    for(left_start = 0; left_start < size - 1; left_start += 2 * curr_size){
      int mid = (left_start + curr_size - 1 < size - 1) ? left_start + curr_size - 1 : size - 1;
      int right_end = (left_start + 2 * curr_size - 1 < size - 1) ? left_start + 2 * curr_size - 1 : size - 1;
      merge(arr, left_start, mid, right_end);
    }
  }
}

// same merge function is still being used
void merge(int arr[], int low, int mid, int high){
  int i, j, k;
  // identify sizes for left sub-array and right sub-array
  int left_size = mid - low + 1;
  int right_size = high - mid;

  int left_arr[left_size];
  int right_arr[right_size];

  // copy to temp arrays
  for(i=0; i<left_size; i++){
    left_arr[i] = arr[low+i];
  }

  for(j=0; j<right_size; j++){
    right_arr[j] = arr[mid + 1 + j];
  }

  // merge sort
  i = 0; // iterator for left
  j = 0; // iterator for right
  k = low; // iterator for orig array (starts at low)

  while(i<left_size && j<right_size){
    if(left_arr[i]<=right_arr[j]){
      arr[k] = left_arr[i++];
    }else{
      arr[k] = right_arr[j++];
    }
    k++;
  }

  while(i<left_size){
    arr[k++] = left_arr[i++];
  }

  while(j<right_size){
    arr[k++] = right_arr[j++]; // i might start using x, y, z as my iterators rn bru T_T
  }
}