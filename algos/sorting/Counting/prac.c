#include "../../utilities/general.h"
#include "../../utilities/test.h"

void counting_sort(int arr[], int size);

int main(void){
  test_sort_w_size(counting_sort);
  return 0;
}

// find max
// create count[]
// traverse thru input and count each occurence
// perform prefix sum on count[]
// start from last index of input and i--, place proper position to output[]
// copy back to orig array
void counting_sort(int arr[], int size){
  int i, max = arr[0];
  for(i=1; i<size; i++){
    if(arr[i]>=max){
      max = arr[i];
    }
  }

  int *count = calloc(max+1, sizeof(int));

  for(i=0; i<size; i++){
    count[arr[i]]++;
  }

  for(i=1; i<max+1; i++){
    count[i] = count[i-1] + count[i];
  }

  int *output = calloc(size, sizeof(int));

  for(i=size-1; i>=0; i--){
    output[count[arr[i]]-1] = arr[i];
    count[arr[i]]--;
  }

  for(i=0; i<size; i++){
    arr[i] = output[i];
  }

  free(count);
  free(output);
}