#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

/**
 * Refresher for everything we have tackled so far.
 * ADT LIST - array, linked list, cursor based
 * ADT Stack - array, linked list, cursor based
 * ADT Queue - circular array, linked list, cursor based
 */

typedef struct{
    int elems[MAX];
    int count;
}ArrayList1, *ArrayList2;

typedef struct{
    int *elem;
    int count;
}ArrayList3, *ArrayList4;

/**
 * ADT LIST array operations
 * Remember:
 *   - L->elems[j] = L->elems[j-1];  // shift to the right, usually used for making space to insert
 *   - L->elems[i-1] = L->elems[i]   // shift to the left, usually used for deleting
 * 
 */
void initArrList1(ArrayList1 *L);
ArrayList2 createArrList2();
void initArrList3(ArrayList3 *L);
ArrayList4 createArrList4();

void insertFirst(ArrayList2 L, int elem);
void insertSorted(ArrayList2 L, int elem);
void insertLast(ArrayList2 L, int elem);

void deleteFirstOccurArr(ArrayList2 L, int elem);
void deleteAllOccurArr(ArrayList2 L, int elem);
void deleteAllArr(ArrayList2 L);

/**
 * Utility functions
 */
void testArrayInsertFunction(void (*adtOperation)(ArrayList2 L, int elem),ArrayList2 L, char *name);
void testArrayDeleteFunction(void (*adtOperation)(ArrayList2 L, int elem),ArrayList2 L, int elem, char *name);
void displayArrList(ArrayList1 L);

int main(void){
    ArrayList1 list1;
    ArrayList2 list2;
    ArrayList3 list3;
    ArrayList4 list4;

    initArrList1(&list1);
    list2 = createArrList2();
    initArrList3(&list3);
    list4 = createArrList4();

    testArrayInsertFunction(insertFirst, &list1, "insertFirst");
    testArrayInsertFunction(insertSorted, &list1, "insertSorted");
    testArrayInsertFunction(insertLast, &list1, "insertLast");

    testArrayDeleteFunction(deleteFirstOccurArr, &list1, 6, "deleteFirstOccur for array");
    testArrayDeleteFunction(deleteAllOccurArr, &list1, 6, "deleteAllOccur for array");

    return 0;
}

void deleteAllOccurArr(ArrayList2 L, int elem){
  if(L->count > 0){
    int i, j;
    for(i=0;i<L->count;){
      if(L->elems[i] == elem){
        // delete by shifting to the left and decrement count
        for(j=i+1;j<L->count;j++){
          L->elems[j-1] = L->elems[j];
        }
        L->count--;
      }else{
        i++;
      }
    }
  }
}

/*
  traverse until you reach count or find the match
  if match not found, handle that error
  else, increment i by 1 and shift elements to the left
  decrement count
*/
void deleteFirstOccurArr(ArrayList2 L, int elem){
  if(L->count > 0){
    int i;
    for(i=0;i<L->count && elem != L->elems[i]; i++){}
    if(i == L->count){
      printf("element not found");
    }else{
      // delete by shifting to the left and decrement count
      for(++i;i<L->count;i++){          
        L->elems[i-1] = L->elems[i];
      }
      L->count--;
    }
  }
}

void insertLast(ArrayList2 L, int elem){
  if(L->count < MAX){
    L->elems[L->count++] = elem;
  }
}

/*
  if count is 0, insert at first index,
  else if count is less than max.
    traverse while count has not been reached and element is greater than current index
    shift elements to the right 
    insert element
    increment count
*/
void insertSorted(ArrayList2 L, int elem){
  if(L->count == 0){
    L->elems[L->count++] = elem;
  }else if(L->count < MAX){
    int i,j;
    for(i=0;i<L->count && elem > L->elems[i];i++){}
    for(j=L->count;j>i;j--){
      L->elems[j] = L->elems[j-1];
    }
    L->elems[i] = elem;
    L->count++;
  }
}

void insertFirst(ArrayList2 L, int elem){
  /*
    if list is empty, insert directly
    else, shift elements to the right to make space for the first element
  */
  if(L->count == 0){
    L->elems[L->count++] = elem;
  }else if(L->count < MAX){
    int i;
    for(i=L->count; i > 0; i--){
      L->elems[i] = L->elems[i-1];
    }
    L->elems[0] = elem;
    L->count++;
  }
}

/**
 * Utility functions
 */
void initArrList1(ArrayList1 *L){
    L->count = 0;
}

ArrayList2 createArrList2(){
  ArrayList2 temp = malloc(sizeof(ArrayList1));
  temp->count = 0;
  return temp;
}

void initArrList3(ArrayList3 *L){
  L->elem = malloc(sizeof(int)*MAX);
  L->count = 0;
}

ArrayList4 createArrList4(){
  ArrayList4 temp = malloc(sizeof(ArrayList3));
  temp->elem = calloc(MAX, sizeof(int));
  temp->count = 0;
}

void displayArrList(ArrayList1 L){
  int i;
  for(i=0;i<L.count;i++){
    printf("%d ", L.elems[i]);
  }
  printf("\n");
}

void deleteAllArr(ArrayList2 L){
  L->count = 0;
}

void testArrayInsertFunction(void (*adtOperation)(ArrayList2 L, int elem),ArrayList2 L, char *name){
  // MAX is 10
  int count = 10;
  int *data = malloc(count * sizeof(int));
  int init_data[] = {3, 1, 5, 2, 4, 6, 10, 8, 7, 9};
  memcpy(data, init_data, count * sizeof(int));
  
  printf("======================\nTest for %s: \n", name);
  deleteAllArr(L);
  
  for(int i=0; i < count; i++){
    adtOperation(L, data[i]);
  }

  displayArrList(*L);
  printf("\n");
}

void testArrayDeleteFunction(void (*adtOperation)(ArrayList2 L, int elem),ArrayList2 L, int elem,char *name){
  int count = 10;
  int *data = malloc(count * sizeof(int));
  int init_data[] = {3, 1, 5, 2, 6, 6, 6, 8, 7, 9};
  memcpy(data, init_data, count * sizeof(int));

  printf("======================\nTest for %s: \n", name);
  deleteAllArr(L);

  for(int i=0; i < count; i++){
    insertSorted(L, data[i]);
  }

  printf("element to delete %d\n \nbefore: ", elem);
  displayArrList(*L);

  adtOperation(L, elem);
  printf("\nafter: ");
  displayArrList(*L);
  printf("\n");
}
