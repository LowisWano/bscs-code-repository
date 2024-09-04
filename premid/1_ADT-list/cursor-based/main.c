#include "adt-list-cursor.h"

int main(void){

  VirtualHeap VH;
  List head;

  initializeVH(&VH);

  insertFirst(&VH, &head, 1);
  insertFirst(&VH, &head, 2);
  insertFirst(&VH, &head, 3);

  displayList(VH, head);

  deleteFirstOcc(&VH, &head, 3);
  displayList(VH, head);

  return 0;
}