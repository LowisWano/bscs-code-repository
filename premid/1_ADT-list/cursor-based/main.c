#include "adt-list-cursor.h"

void testInsertFunction(void (*insert)(VirtualHeap *VH, List *L, char elem), VirtualHeap *VH, List *L, char elem, char *name){
  printf("Test for %s: \n", name);
  deleteAll(VH, L);
  insert(VH, L, 'E');
  insert(VH, L, 'C');
  insert(VH, L, 'B');
  insert(VH, L, 'A');
  insert(VH, L, 'D');
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
  testInsertFunction(insertFirst, &VH, &head, 'E', "insertFirst");
  
  /**
   * Test insertSorted() function
   */
  testInsertFunction(insertSorted, &VH, &head, 'E', "insertSorted");
  
  return 0;
}