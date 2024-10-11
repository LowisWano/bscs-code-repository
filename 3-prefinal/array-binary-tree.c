// array of structures with left child and right child containing indexes
#include<stdio.h>
#include<stdlib.h>
#define MAX 15
#define EMPTY -1

typedef struct{
  int elem;
  int LC;
  int RC;
}ElemType;

typedef struct{
  ElemType elems[MAX];
  int root;
}Tree;

void initTree(Tree *T);

int main(void){

  return 0;
}

void initTree(Tree *T){
  T->root = -1;
  int i;
  for(i=0;i<MAX;i++){
    T->elems[i].LC = EMPTY;
    T->elems[i].RC = EMPTY;
  }
}