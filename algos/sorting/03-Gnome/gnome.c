#include "../../utilities/general.h"
#include "../../utilities/test.h"

void gnome_sort(int arr[], int n);

int main(void){
  test_sort_w_size(gnome_sort);

  return 0;
}

void gnome_sort(int arr[], int n) {
  int i = 0;
  
  while (i < n) {
    if (i == 0 || arr[i] >= arr[i-1]) {
      // Either at start or current element is in correct order
      i++;
    } else {
      // Swap elements and move back one position
      int temp = arr[i];
      arr[i] = arr[i-1];
      arr[i-1] = temp;
      i--;
    }
  }
}