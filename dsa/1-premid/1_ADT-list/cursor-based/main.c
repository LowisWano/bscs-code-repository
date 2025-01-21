#include "adt-list-cursor.h"

void testInsertFunction(void (*insert)(VirtualHeap *VH, List *L, char elem), VirtualHeap *VH, List *L, char *name){
  char data[] = {'E', 'C', 'B', 'A', 'D', '\0'};
  printf("Test for %s: \n", name);
  deleteAll(VH, L);
  for(int i=0; data[i] != '\0'; i++){
    insert(VH, L, data[i]);
  }
  displayList(*VH, *L);
  printf("\n");
}

int main(void){

  VirtualHeap VH;
  List head = -1;

  initializeVHeapV2(&VH);

  /**
   * Test insertFirst() function
   */
  testInsertFunction(insertFirst, &VH, &head, "insertFirst");
  
  /**
   * Test insertSorted() function
   */
  testInsertFunction(insertSorted, &VH, &head, "insertSorted");

  /**
   * Test insertLast() function
   */
  testInsertFunction(insertLast, &VH, &head, "insertLast");
  
  return 0;
}