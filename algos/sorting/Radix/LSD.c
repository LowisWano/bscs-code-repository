#include "../../utilities/general.h"
#include "../../utilities/test.h"

void lsd_radix_sort(int arr[], int size);
int get_max(int arr[], int size);
void counting_sort(int arr[], int size, int exp);

int main(void){
  test_sort_w_size(lsd_radix_sort);
  return 0;
}

void lsd_radix_sort(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    counting_sort(arr, size, exp);
  }
}

void counting_sort(int arr[], int size, int exp) {
  int output[size];
  // only until size 10 instead of max (traditional counting sort) since digits are only from 0-9
  int count[10] = {0};
  
  // (arr[i] / exp) shifts a digit to current power (ones, tens, hundreds)
  // % 10 extracts the rightmost digit
  for (int i = 0; i < size; i++) {
    count[(arr[i] / exp) % 10]++;
  }
  
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  
  for (int i = size - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }
  
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
}