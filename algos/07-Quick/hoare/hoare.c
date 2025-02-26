#include <stdio.h>

int hoare_partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start;
    int j = end;
    
    while (i < j) {
        // Move i forward while element is less than pivot
        for (; arr[i] < pivot && i < end; i++);
  
        // Move j backward while element is greater than pivot
        for (; arr[j] > pivot && j > start; j--);
  
        
        // If pointers haven't crossed, swap elements
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    return j;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int p = hoare_partition(arr, start, end);
        quickSort(arr, start, p);
        quickSort(arr, p + 1, end);
    }
}


int main(void) {
    int arr[] = {3, 1, 4, 2 , 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    quickSort(arr, 0, n-1);
    
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}