#include "../../utilities/general.h"
#include "../../utilities/test.h"

void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main(void){
  test_sort_w_low_high(merge_sort);
  return 0;
}

/**
 * 1. if low < high
 * 2. find mid: low + (high-low)/2
 * 3. sort low to mid
 * 4. sort mid + 1 to high
 * 5. merge the two sorted halves
 */
void merge_sort(int arr[], int low, int high){
  if(low<high){
    int mid = low + (high-low)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

/**
 * 1. Split the array in half by separating them into temp arrays
 * 2. mergeSort them back to the orig array
 */
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