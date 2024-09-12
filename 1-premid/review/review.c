#include<stdio.h>
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
 */
void initArrList1(ArrayList1 *L);
ArrayList2 createArrList2();
void initArrList3(ArrayList3 *L);
ArrayList4 createArrList4();

void insertFirst(ArrayList2 L, int elem);
void insertSorted(ArrayList2 L, int elem);
void insertLast(ArrayList2 L, int elem);

void deleteFirstOccur(ArrayList2 L, int elem);
void deleteAllOccur(ArrayList2 L, int elem);
void deleteAll(ArrayList2 L);

/**
 * Utility functions
 */
void testAdtArrayFunction(void (*adtOperation)(ArrayList2 L, int elem),ArrayList2 L, char *name);
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

    // testAdtArrayFunction(insertFirst, &list1, "insertFirst");
    insertFirst(&list1, 6);
    displayArrList(list1);
    return 0;
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
      L->elems[L->count] = L->elems[L->count-1];
    }
    L->elems[0] = elem;
    L->count++;
  }
}

void displayArrList(ArrayList1 L){
  int i;
  for(i=0;i<L.count;i++){
    printf("%d ", L.elems[i]);
  }
  printf("\n");
}

/**
 * Array Initialization/returnNew functions
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

// void testAdtArrayFunction(void (*adtOperation)(ArrayList2 L, int elem),ArrayList2 L, char *name){
//   int data[] = {3, 1, 5, 2, 4, 6, 9, 8};
//   printf("Test for %s: \n", name);
//   deleteAll(L);
//   for(int i=0; data[i] != '\0'; i++){
//     adtOperation(L, data[i]);
//   }
//   displayArrList(*L);
//   printf("\n");
// }
