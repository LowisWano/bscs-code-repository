#include<stdio.h>
#include<stdlib.h>

int* strand_sort(int arr[], int n);

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  int *sorted = strand_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", sorted[i]);
  }
  printf("\n");

  return 0;
}

int* strand_sort(int input[], int n){
  int *result = (int*)malloc(sizeof(int)*n);
  int result_size = 0;
  int orig_size = n;

  while(n>0){
    int i, j;

    // Step 1: insertAndDelete() first element of input[] to strand[]
    int strand[n], strand_size = 0;
    strand[strand_size++] = input[0];
    for(j=1; j<n; j++){
      input[j-1] = input[j];
    }
    n--;

    // Step 2: Traverse through input[] and insertAndDelete() all its elems that are > last elem of strand[]
    for(i=0;i<n;){
      if(input[i]>strand[strand_size-1]){
        strand[strand_size++] = input[i];
        for(j=i+1; j<n; j++){
          input[j-1] = input[j];
        }
        n--;
      }else{
        // Remember: Only move pointer when you are not deleting. If not, you will skip over an element.
        i++;
      }
    }

    // Step 3: Perform unionSet() to strand[] and result[]
    int temp[orig_size], temp_size=0;
    for(i=0, j=0; i<strand_size && j<result_size;){
      if(strand[i] < result[j]){
        temp[temp_size++] = strand[i++]; 
      }else{
        temp[temp_size++] = result[j++];
      }
    }

    while(i<strand_size && j==result_size){
      temp[temp_size++] = strand[i++];
    }

    while(j<result_size && i==strand_size){
      temp[temp_size++] = result[j++];
    }

    for(i=0; i<temp_size; i++){
      result[i] = temp[i];
    }
    result_size = temp_size;
    
  }
  
  return result;
}