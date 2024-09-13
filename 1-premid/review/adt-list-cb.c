#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define VH_SIZE 10

typedef struct{
  int elem;
  int next;
}nodeType;

typedef struct{
  nodeType nodes[VH_SIZE];
  int avail;
}VHeap;

typedef int List; // works like a pointer. -1 if null, value of index if has value

/**
 * Virtual Heap Management Operations
 */
void initVHeap(VHeap *VH);
int allocSpace(VHeap *VH); // works like malloc
void deallocSpace(VHeap *VH, int index); // works like free

// ADT List Operations
void initList(List *L);
void insertFirst(VHeap *VH, List *L, int elem);
void insertSorted(VHeap *VH, List *L, int elem);
void insertLast(VHeap *VH, List *L, int elem);

void deleteFirstOcc(VHeap *VH, List *L, int elem);
void deleteAllOcc(VHeap *VH, List *L, int elem);

void testInsertFunction(void (*insert)(VHeap *VH, List *L, int elem), VHeap *VH, List *L, char *name);
void testDeleteFunction(void (*delete)(VHeap *VH, List *L, int elem), VHeap *VH, List *L, int elem, char *name);
void displayList(VHeap VH, List L);
void deleteAll(VHeap *VH, List *L);

int main(void){
  VHeap VH;
  initVHeap(&VH);
  List L;
  initList(&L);

  testInsertFunction(insertFirst, &VH, &L, "insertFirst");
  testInsertFunction(insertSorted, &VH, &L, "insertSorted");
  testInsertFunction(insertLast, &VH, &L, "insertLast");

  testDeleteFunction(deleteFirstOcc, &VH, &L, 4, "delete first occ");
  testDeleteFunction(deleteAllOcc, &VH, &L, 5, "delete all occ");
  return 0;
}

void initList(List *L){
  *L = -1;
}

void deleteFirstOcc(VHeap *VH, List *L, int elem){
  if(*L != -1){
    List *trav, temp;
    for(trav=L; *trav != -1 && elem != VH->nodes[*trav].elem; trav=&(VH->nodes[*trav].next)){}
    if(*trav != -1){
      temp = *trav;
      *trav = VH->nodes[temp].next;
      deallocSpace(VH, temp);
    }
  }
}

void deleteAllOcc(VHeap *VH, List *L, int elem){
  if(*L != -1){
    List *trav, temp;
    for(trav=L; *trav != -1;){
      if(VH->nodes[*trav].elem == elem){
        temp = *trav;
        *trav = VH->nodes[*trav].next;
        deallocSpace(VH, temp);
      }else{
        trav=&(VH->nodes[*trav].next);
      }
    }
  }
}

void deleteAll(VHeap *VH, List *L){
  if(*L != -1){
    List temp;
    while(*L != -1){
      temp = *L;
      *L = VH->nodes[*L].next;
      deallocSpace(VH, temp);
    }
  }
}

void displayList(VHeap VH, List L){
  List trav;
  for(trav=L;trav != -1; trav=VH.nodes[trav].next){
    printf("%d ", VH.nodes[trav].elem);
  }
  printf("\n");
}

void insertFirst(VHeap *VH, List *L, int elem){
  List temp = allocSpace(VH);
  if(temp != -1){
    VH->nodes[temp].elem = elem;
    VH->nodes[temp].next = *L;
    *L = temp;
  }
}

void insertSorted(VHeap *VH, List *L, int elem){
  List temp = allocSpace(VH);
  if(temp != -1){
    List *trav;
    for(trav=L; *trav != -1 && elem > VH->nodes[*trav].elem; trav = &(VH->nodes[*trav].next)){}
    VH->nodes[temp].elem = elem;
    VH->nodes[temp].next = *trav;
    *trav = temp;
  }
}

void insertLast(VHeap *VH, List *L, int elem){
  List temp = allocSpace(VH);
  if(temp != -1){
    List *trav;
    for(trav=L; *trav != -1; trav=&(VH->nodes[*trav].next)){}
    VH->nodes[temp].elem = elem;
    VH->nodes[temp].next = -1;
    *trav = temp;
  }
}

void initVHeap(VHeap *VH){
  int i;
  for(i=0;i<VH_SIZE;i++){
    VH->nodes[i].next = i-1;
  }
  VH->avail = VH_SIZE - 1;
}

int allocSpace(VHeap *VH){
  int index = VH->avail;
  if(index != -1){
    VH->avail = VH->nodes[index].next;
  }
  return index; 
}

void deallocSpace(VHeap *VH, int index){
  VH->nodes[index].next = VH->avail;
  VH->avail = index;
}

void testInsertFunction(void (*insert)(VHeap *VH, List *L, int elem), VHeap *VH, List *L, char *name){
  int count = 10;
  int *data = malloc(count * sizeof(int));
  int init_data[] = {3, 1, 5, 2, 5, 5, 6, 8, 7, 9};
  memcpy(data, init_data, count * sizeof(int));

  printf("Test for %s: \n", name);
  deleteAll(VH, L);
  for(int i=0; i<count; i++){
    insert(VH, L, data[i]);
  }
  displayList(*VH, *L);
  printf("\n");
}

void testDeleteFunction(void (*delete)(VHeap *VH, List *L, int elem), VHeap *VH, List *L, int elem, char *name){
  int count = 10;
  int *data = malloc(count * sizeof(int));
  int init_data[] = {3, 1, 5, 2, 5, 5, 4, 8, 7, 9};
  memcpy(data, init_data, count * sizeof(int));

  printf("======================\nTest for %s: \n", name);
  deleteAll(VH, L);

  for(int i=0; i < count; i++){
    insertSorted(VH, L, data[i]);
  }

  printf("element to delete: %d\n \nbefore: ", elem);
  displayList(*VH, *L);

  delete(VH, L, elem);
  printf("\nafter: ");
  displayList(*VH, *L);
  printf("\n");
}
