#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  int elem;
  struct node *next;
}*List, nodeItem;

// utility functions
void initList(List *L);
void testInsertFunction(void (*insert)(List *L, int elem), List *L, char *name);
void testDeleteFunction(void (*delete)(List *L, int elem), List *L, int elem, char *name);
void displayList(List L);
void deleteAll(List *L);

// adt operations
void insertFirst(List *L, int elem);
void insertSorted(List *L, int elem);
void insertLast(List *L, int elem);

void deleteFirstOccur(List *L, int elem);
void deleteAllOccur(List *L, int elem);

int main(void){
  List L;
  initList(&L);

  testInsertFunction(insertFirst, &L, "insertFirst");
  testInsertFunction(insertSorted, &L, "insertSorted");
  testInsertFunction(insertLast, &L, "insertLast");

  testDeleteFunction(deleteFirstOccur, &L, 4, "deleteFirstOccur");
  testDeleteFunction(deleteAllOccur, &L, 5, "deleteAllOccur");
  return 0;
}

void deleteAllOccur(List *L, int elem){
  List *trav, temp;
  for(trav=L; *trav!=NULL;){
    if((*trav)->elem == elem){
      temp = *trav;
      *trav = (*trav)->next;
      free(temp);
    }else{
      trav=&(*trav)->next;
    }
  }
}

void deleteFirstOccur(List *L, int elem){
  if(*L != NULL){
    List *trav, temp;
    for(trav=L; *trav!=NULL && elem != (*trav)->elem;trav=&(*trav)->next){}
    if(*trav!= NULL){
      temp = *trav;
      *trav = (*trav)->next;
      free(temp);
    }
  }
}

void insertLast(List *L, int elem){
  List *trav, temp;
  for(trav=L;*trav!=NULL;trav=&(*trav)->next){}

  temp = malloc(sizeof(nodeItem));
  if(temp != NULL){
    temp->elem = elem;
    temp->next = NULL;
    
    *trav = temp;
  }
}

void insertSorted(List *L, int elem){
  List *trav, temp;
  for(trav=L;*trav!=NULL && elem >(*trav)->elem;trav=&(*trav)->next){}

  temp = malloc(sizeof(nodeItem));
  if(temp!=NULL){
    temp->elem = elem;
    temp->next = *trav;

    *trav = temp;
  }
}

void insertFirst(List *L, int elem){
  List temp = malloc(sizeof(nodeItem));
  temp->elem = elem;
  temp->next = *L;

  *L = temp;
}

void testDeleteFunction(void (*delete)(List *L, int elem), List *L, int elem, char *name){
  int count = 10;
  int *data = malloc(count * sizeof(int));
  int init_data[] = {3, 1, 5, 2, 5, 5, 4, 8, 7, 9};
  memcpy(data, init_data, count * sizeof(int));

  printf("======================\nTest for %s: \n", name);
  deleteAll(L);

  for(int i=0; i < count; i++){
    insertSorted(L, data[i]);
  }

  printf("element to delete: %d\n \nbefore: ", elem);
  displayList(*L);

  delete(L, elem);
  printf("\nafter: ");
  displayList(*L);
  printf("\n");
}

void testInsertFunction(void (*insert)(List *L, int elem), List *L, char *name){
  int count = 10;
  int *data = malloc(count * sizeof(int));
  int init_data[] = {3, 1, 5, 2, 5, 5, 6, 8, 7, 9};
  memcpy(data, init_data, count * sizeof(int));

  printf("======================\nTest for %s: \n", name);
  deleteAll(L);
  for(int i=0; i<count; i++){
    insert(L, data[i]);
  }
  displayList(*L);
  printf("\n");
}

void displayList(List L){
  List trav;
  for(trav=L;trav!=NULL;trav=trav->next){
    printf("%d ", trav->elem);
  }
  printf("\n");
}

void initList(List *L){
  *L = NULL;
}

void deleteAll(List *L){
  if(*L != NULL){
    List *trav, temp;
    for(trav=L;*trav!=NULL;){
      temp = *trav;
      *trav = (*trav)->next;
      free(temp);
    }
  }
}