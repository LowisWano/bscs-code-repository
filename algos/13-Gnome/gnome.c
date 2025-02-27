#include<stdio.h>

void gnome_sort(int arr[], int n);

int main(void){
  int arr[] = {12, 34, 54, 2, 3, 5, 7, 23, 1, 26};
  int n = sizeof(arr)/sizeof(arr[0]);

  gnome_sort(arr, n);

  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}

void gnome_sort(int arr[], int n){
  int i;
  for(i=1; i<n;){
    if(i==0){
      i++;
    }
    if(arr[i] < arr[i-1]){
      int temp = arr[i];
      arr[i] = arr[i-1];
      arr[i-1] = temp;
      i--;
    }else{
      i++;
    }
  }

  // int i = 1,temp;

  // while(i < n){
  //   if(arr[i] < arr[i-1]){
  //     temp = arr[i];
  //     arr[i] =arr[i-1];
  //     arr[i - 1] = temp;
  //     if(i > 1){
  //       i--;
  //     }
  //   }else{
  //     i++;
  //   }
  // }
}