#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}*List;

void populateList(List *L, int data[]);
List sortMerge(List *A, List *B);
void displayList(List L);

int main(void){
  int dataA[] = {1,3,5,7,9};
  int dataB[] = {2,3,4,6,6};

  List A = NULL;
  List B = NULL;
  List new  = NULL;

  populateList(&A, dataA);
  populateList(&B, dataB);

  displayList(A);
  displayList(B);

  new = sortMerge(&A, &B);
  printf("new: ");
  displayList(new);

  return 0;
}

List sortMerge(List *A, List *B){
  List new=NULL;
  List temp, *last=&new;
  while(*A!=NULL && *B!=NULL){
    if((*A)->data < (*B)->data){
      temp = *A;
      *A=(*A)->link;
    }else{
      temp = *B;
      *B = (*B)->link;
    }
    *last = temp;
    last = &(*last)->link;
    *last = NULL;
  }

  if(*A == NULL){
    *last = *B;
  }else if(*B == NULL){
    *last = *A;
  }

  return new;
}

void populateList(List *L, int data[]){
  int i;
  for(i=4;i>=0;i--){
    List temp = malloc(sizeof(List));
    temp->data = data[i];
    temp->link = *L;
    *L = temp;
  }
}

void displayList(List L){
  for(;L!=NULL;L=L->link){
    printf("%d ", L->data);
  }
  printf("\n");
}