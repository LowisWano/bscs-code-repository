#include "../../utilities/general.h"
#include "../../utilities/test.h"

void merge_sort(int arr[], int size);
void merge(int arr[], int low, int mid, int high);

int main(void){
  test_sort_w_size(merge_sort);
  return 0;
}

void merge_sort(int arr[], int size){
  int curr_size, left_start;
  for(curr_size = 1; curr_size < size; curr_size = curr_size * 2){
    for(left_start = 0; left_start < size; left_start += 2 * curr_size){
      int mid = (left_start + curr_size-1 < size-1) ? left_start + curr_size-1 : size-1;
      int right_end = (left_start + 2*curr_size-1 < size-1) ? left_start + 2*curr_size-1 : size-1;
      merge(arr, left_start, mid, right_end);
    }
  }
}

void merge(int arr[], int low, int mid, int high){
  int i, j, k;
  int left_size = (mid - low) + 1;
  int right_size = high - mid;

  int left[left_size];
  int right[right_size];

  for(i=0, j = low; i<left_size; i++, j++){
    left[i] = arr[j];
  }

  for(i=0, j=mid+1; i<right_size; i++, j++){
    right[i] = arr[j];
  }

  i=low;
  j=0;
  k=0;
  for(; j<left_size && k<right_size; i++){
    if(left[j]<right[k]){
      arr[i] = left[j++];
    }else{
      arr[i] = right[k++];
    }
  }

  while(j<left_size){
    arr[i++] = left[j++];
  }

  while(k<right_size){
    arr[i++] = right[k++];
  }
}