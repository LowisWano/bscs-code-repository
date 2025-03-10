#include "../../utilities/general.h"
#include "../../utilities/test.h"

void rsd_radix_sort(int arr[], int size);
int get_max(int arr[], int size);
int get_digit_count(int max);
void msd_radix_sort_recursive(int arr[], int output[], int size, int exp);

int main(void){
  test_sort_w_size(rsd_radix_sort);
  return 0;
}

int get_max(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int get_digit_count(int max) {
  int count = 0;
  while (max > 0) {
    count++;
    max /= 10;
  }
  return count;
}

void rsd_radix_sort(int arr[], int size) {
  if (size <= 1) return;
  
  int max = get_max(arr, size);
  int digit_count = get_digit_count(max);
  
  int exp = 1;
  for (int i = 1; i < digit_count; i++) {
    exp *= 10;
  }
  
  int* output = (int*)malloc(size * sizeof(int));
  if (output == NULL) return;
  
  msd_radix_sort_recursive(arr, output, size, exp);
  
  free(output);
}

void msd_radix_sort_recursive(int arr[], int output[], int size, int exp) {
  if (size <= 1 || exp < 1) return;

  int count[10] = {0};
  int position[10] = {0};
  
  for (int i = 0; i < size; i++) {
    count[(arr[i] / exp) % 10]++;
  }
  
  position[0] = 0;
  for (int i = 1; i < 10; i++) {
    position[i] = position[i-1] + count[i-1];
  }
  
  for (int i = 0; i < size; i++) {
    int digit = (arr[i] / exp) % 10;
    output[position[digit]] = arr[i];
    position[digit]++;
  }
  
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
  
  int start = 0;
  for (int i = 0; i < 10; i++) {
    int bucket_size = count[i];
    if (bucket_size > 1 && exp > 1) {
      msd_radix_sort_recursive(arr + start, output + start, bucket_size, exp / 10);
    }
    start += bucket_size;
  }
}