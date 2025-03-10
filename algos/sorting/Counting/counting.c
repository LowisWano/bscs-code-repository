#include "../../utilities/general.h"
#include "../../utilities/test.h"

void counting_sort(int arr[], int size);

int main(void){
  test_sort_w_size(counting_sort);
  return 0;
}

// find max
// create count_arr
// traverse thru input arr and store no. of occurences in count_arr
// calculate prefix sum of each index in count_arr
// iterate over input[] starting from the last elem and store it in its proper position
void counting_sort(int input[], int size){
  int i, max=0;
  for(i=0; i<size; i++){
    if(input[i] > max){
      max = input[i];
    }
  }

  // gcc compiler does not accept int count_arr[var] or static variable sized arrays determined at runtime. should be dynamically allocated instead.
  int *count_arr = (int*)malloc(sizeof(int)*max+1);

  for(i=0; i<size; i++){
    count_arr[input[i]]++;
  }

  for(i=1; i<=max; i++){
    count_arr[i] = count_arr[i-1] + count_arr[i];
  }

  int *output = (int*)malloc(sizeof(int)*size);
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