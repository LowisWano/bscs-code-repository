#include "../../utilities/general.h"
#include "../../utilities/test.h"

void counting_sort(int arr[], int size);

int main(void){
  test_sort_w_size(counting_sort);
  return 0;
}

// find max
// create count_arr
// traverse thru input and count each element's occurences
// calculate prefix sum for each element
// traverse starting from end of the input array and place to proper position in output
void counting_sort(int input[], int size){
  int i, max = 0;
  for(i=0; i<size; i++){
    if(input[i]>max){
      max = input[i];
    }
  }

  int *count_arr = calloc(max+1, sizeof(int));

  for(i=0; i<size; i++){
    count_arr[input[i]]++;
  }

  for(i=1; i<max+1; i++){
    count_arr[i] = count_arr[i-1] + count_arr[i];
  }

  int *output = calloc(size, sizeof(int));
  for(i=size-1; i>=0; i--){
    output[count_arr[input[i]]-1] = input[i];
    count_arr[input[i]]--;
  }

  for(i=0; i<size; i++){
    input[i] = output[i];
  }

  free(count_arr);
  free(output);
}