#include "adt-list-cursor.h"

/**
 * @name initializeVHeapV2
 * @feature: Links up all the nodes in the VHeap and sets avail to the first available node
 * @details: version 2 initVHeap has index 0 starts with -1 and increments throuhout the array. Basically, index 0 would be the last node
 * while the last index would be the first node.
 */
void initializeVHeapV2(VirtualHeap *VH){
  int i;
  for(i=0;i<MAX;i++){
    VH->nodes[i].next = i-1;
  }
  VH->avail = MAX-1;
}

/**
 * @name allocSpace
 * @feature: Works like malloc(). I
 * @details: If there is still space, it will return the index of an available space in the VHeap for it to be used, and
 * change the value of VH->avail to the next available one. Returns -1 if no more space.
 */
int allocSpace(VirtualHeap *VH){
  int index = VH->avail;
  if(index != -1){
    VH->avail = VH->nodes[index].next;
  }
  return index;
}

/**
 * @name deallocSpace
 * @feature: Works like free(). I
 * @details: Receives an index for a node and sets it as the new value for VH->avail and connects that node to the former VH->avail
 */
void deallocSpace(VirtualHeap *VH, int index){
  VH->nodes[index].next = VH->avail;
  VH->avail = index;
}

/**
 * ADT LIST Operations:
 * Works just like linked list, but instead of pointers, its indexes.
 */

void insertFirst(VirtualHeap *VH, List *L, char elem){
  List temp = allocSpace(VH);
  if(temp != -1){
    VH->nodes[temp].elem = elem;
    VH->nodes[temp].next = *L;
    *L = temp;
  }
}

void insertSorted(VirtualHeap *VH, List *L, char elem){
  List *trav, temp = allocSpace(VH);
  if(temp != -1){
    for(trav=L;*trav!=-1 && VH->nodes[*trav].elem < elem;trav=&(VH->nodes[*trav].next)){}
    
    VH->nodes[temp].elem = elem;
    VH->nodes[temp].next = *trav;
    *trav = temp;
    
  }
}

void insertLast(VirtualHeap *VH, List *L, char elem){
  List *trav, temp = allocSpace(VH);
  if(temp != -1){
    for(trav=L;*trav!=-1;trav=&(VH->nodes[*trav].next)){}
    VH->nodes[temp].elem = elem;
    VH->nodes[temp].next = *trav;
    *trav = temp;
  }
}

void deleteFirstOcc(VirtualHeap *VH, List *L, char elem){
  List *trav, temp;
  for(trav=L;*trav!=-1 && VH->nodes[*trav].elem != elem;trav=&(VH->nodes[*trav].next)){}
  if(*trav != -1){
    temp = *trav;
    *trav = VH->nodes[*trav].next;
    deallocSpace(VH, temp);
  }
}

void deleteAllOcc(VirtualHeap *VH, List *L, char elem){
  List *trav, temp;
  for(trav=L;*trav!=-1;){
    if(VH->nodes[*trav].elem == elem){
      temp = *trav;
      *trav = VH->nodes[*trav].next;
      deallocSpace(VH, temp);
    }else{
      trav=&(VH->nodes[*trav].next);
    }
  }
}

/**
 * Utility Functions
 */
int listIsEqualSorted(VirtualHeap VH){
  // ...
}

void deleteAll(VirtualHeap *VH, List *L){
  if(*L != -1){
    List *trav, temp;
    for(trav=L;*trav!=-1;){
      temp = *trav;
      *trav = VH->nodes[*trav].next;
      deallocSpace(VH, temp);
    }
  }
}

void displayList(VirtualHeap VH, List L){
  List trav;
  if(L != -1){
    for(trav=L;trav!=-1;trav=VH.nodes[trav].next){
      printf("%c ", VH.nodes[trav].elem);
    }
  }else{
    printf("list is empty!");
  }
  
  printf("\n");
}

