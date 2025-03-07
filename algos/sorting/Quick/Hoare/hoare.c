#include "../../../utilities/general.h"
#include "../../../utilities/test.h"

int hoare_partition(int arr[], int start, int end);
void quicksort(int arr[], int start, int end);

int main(void){
  test_sort_w_low_high(quicksort);

  return 0;
}

// void quicksort(int arr[], int start, int end){
//   if(start < end){
//     int p = hoare_partition(arr, start, end);
//     quicksort(arr, start, p);
//     quicksort(arr, p+1, end);
//   }
// }

// we can also combine everything in one function
void quicksort(int arr[], int start, int end){
  if(start < end){
    int pivot = arr[start];
    int i = start - 1, j = end + 1;
    
    while(i<j){
      // more intuitive to use do while loops for hoare's to guarantee movement to avoid i and j getting stuck in edge cases where they both encounter a value same as pivot
      do{
        i++;
      }while(i<=end && arr[i]<pivot);

      do{
        j--;
      }while(j>=start && arr[j]>pivot);
      
      if(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }

    }
    quicksort(arr, start, j);
    quicksort(arr, j+1, end);
  }
}

// int hoare_partition(int arr[], int start, int end){
//   int pivot = arr[start];
//   int i = start - 1, j = end + 1;
  
//   while(i<j){
//     // more intuitive to use do while loops for hoare's to guarantee movement to avoid i and j getting stuck in edge cases where they both encounter a value same as pivot
//     do{
//       i++;
//     }while(i<=end && arr[i]<pivot);

//     do{
//       j--;
//     }while(j>=start && arr[j]>pivot);
    
//     if(i<j){
//       int temp = arr[i];
//       arr[i] = arr[j];
//       arr[j] = temp;
//     }

//   }

//   return j;
// }