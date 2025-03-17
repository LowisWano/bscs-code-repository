#include "../../../utilities/general.h"
#include "../../../utilities/test.h"

int lumoto_partition(int arr[], int start, int end);
void quicksort(int arr[], int start, int end);

int main(void){
  test_sort_w_low_high(quicksort);

  return 0;
}

void quicksort(int arr[], int start, int end){
  if(start < end){
    int p = lumoto_partition(arr, start, end);
    quicksort(arr, start, p-1);
    quicksort(arr, p+1, end);
  }
  
}

int lumoto_partition(int arr[], int start, int end){
  int temp, pivot = arr[end];
  int i = start-1;
  int j = start;

  for(; j<end; j++){
    if(arr[j] <= pivot){
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  i++;
  temp = arr[i];
  arr[i] = arr[end];
  arr[end] = temp;

  return i;
}