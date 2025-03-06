#include "../../utilities/general.h" 
#include "../../utilities/test.h" 

void strand_sort(int arr[], int size);

int main(void) {
    test_sort_w_size(strand_sort);
    
    return 0;
}

void strand_sort(int arr[], int size){
  /*
    insertDelete first element of input to strand
    traverse through input and insertDelete every element >= than last elem of strand

    merge strand and result

    copy result to input

  */
  int result[size];
  int result_size = 0;
  int input_size = size;
  
  int i, j;

  while(input_size > 0){
    // 1.
    int strand[size], strand_size = 0;
    strand[strand_size++] = arr[0];
    for(i=1; i<input_size; i++){
      arr[i-1] = arr[i];
    }
    input_size--;

    // 2.
    for(i=0; i<input_size;){
      if(arr[i]>=strand[strand_size-1]){
        strand[strand_size++] = arr[i];
        for(j=i+1; j<input_size; j++){
          arr[j-1] = arr[j];
        }
        input_size--;
      }else{
        i++;
      }
    }

    // 3. merge 
    int temp[size];
    int temp_size = 0;
    for(i=0, j=0; i < strand_size && j < result_size;){
      if(strand[i]<result[j]){
        temp[temp_size++] = strand[i++];
      }else{
        temp[temp_size++] = result[j++];
      }
    }

    while(i<strand_size && j == result_size){
      temp[temp_size++] = strand[i++];
    }

    while(j<result_size && i == strand_size){
      temp[temp_size++] = result[j++];
    }

    // copy back to result
    for(i=0; i<temp_size; i++){
      result[i] = temp[i];
    }
    result_size = temp_size;
  }

  for(i=0; i<size; i++){
    arr[i] = result[i];
  }
}