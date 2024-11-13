#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

typedef int Tree[MAX];

void populateTree(Tree T);
bool binarySearch(Tree T, int elem);
void getUserInputAndSearch(Tree T);

int main(void){
  Tree T;
  populateTree(T);
  getUserInputAndSearch(T);
  return 0;
}

void getUserInputAndSearch(Tree T){
  int n;
  printf("Enter number: ");
  scanf("%d", &n);

  printf("%s", binarySearch(T, n) ? "found!\n" : "not found :(\n");
}

bool binarySearch(Tree T, int elem){
  int LB = 0;
  int UB = MAX-1;
  int mid = (LB + UB)/2;
  while(LB < UB && T[mid] != elem){
    if(elem > T[mid]){
      LB = mid + 1;
    }else if (elem < T[mid]){
      UB = mid - 1;
    }
    mid = (LB + UB)/2;
  }
  return (T[mid] == elem) ? true : false;
}

void populateTree(Tree T){
  int fixedValues[10] = {11, 12, 23, 34, 45, 56, 67, 78, 89, 90 };
  for(int i = 0; i < 10; i++) {
    T[i] = fixedValues[i];
  }
}