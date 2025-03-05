#include "../../utilities/general.h"
#include "../../utilities/test.h"

void insertion_sort(int arr[], int n);

int main(void){
  test_sort_w_size(insertion_sort);
  return 0;
}
// shift until left side is smaller than curr
void insertion_sort(int arr[], int n){
  int i, j;
  for(i=1;i<n; i++){
    int temp = arr[i];
    for(j=i; j>0 && arr[j-1] > temp; j--){
      arr[j] = arr[j-1];
    }
    arr[j] = temp;
  }
}


