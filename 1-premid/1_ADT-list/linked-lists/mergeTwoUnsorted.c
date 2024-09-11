#include<stdio.h>
#include<stdlib.h>

typedef struct nodeType{
  int elem;
  struct nodeType *next;
}List;

void populateList(List **L, int data[]);
List* mergeTwoUnsortedLists(List *A, List *B);
void displayList(List *L);

int main(void){
  int dataA[] = {1,2,3,4,5};
  int dataB[] = {6,7,8,9,10};

  List *A = NULL;
  List *B = NULL;
  List *new  = NULL;

  populateList(&A, dataA);
  populateList(&B, dataB);

  displayList(A);
  displayList(B);

  new = mergeTwoUnsortedLists(A, B);
  printf("new: ");
  displayList(new);
  return 0;
}

void populateList(List **L, int data[]){
  int i;
  for(i=4;i>=0;i--){
    List *temp = malloc(sizeof(List));
    temp->elem = data[i];
    temp->next = *L;
    *L = temp;
  }
}

List* mergeTwoUnsortedLists(List *A, List *B){
  List *new = NULL;
  List *lastPtr = new, *temp;
  /**
   * checks A or B on who is lesser, the lesser one gets inserted first
   * if A is null, insert the rest of B
   * else, insert the rest of A
   */
  while(A!= NULL && B!=NULL){
    temp = malloc(sizeof(List));
    if(A->elem < B->elem){
      temp->elem = A->elem;
      A=A->next;
    }else{
      temp->elem = B->elem;
      B=B->next;
    }
    temp->next = NULL;
    if(new == NULL){
      new = temp;
      lastPtr = temp;
    }else{
      lastPtr->next = temp;
      lastPtr = lastPtr->next;
    }
  }

  for(;A != NULL || B != NULL; B=B->next){
    if(B == NULL){
      B = A;
    }
    temp = malloc(sizeof(List));
    temp->elem = B->elem;
    temp->next = NULL;
    if(new == NULL){
      new = temp;
      lastPtr = temp;
    }else{
      lastPtr->next = temp;
      lastPtr = lastPtr->next;
    }
  }
  return new;
}

void displayList(List *L){
  for(;L!=NULL;L=L->next){
    printf("%d ", L->elem);
  }
  printf("\n");
}