#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define VH_SIZE 20

/**
 * PUSH, POP
 */

typedef struct{
  int elem;
  int next;
}nodeType;

typedef struct{
  nodeType nodes[VH_SIZE];
  int avail;
}VHeap;

typedef int List;

void initVHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int index);

void initList(List *L);
void push(VHeap *VH, List *L, int elem);
int pop(VHeap *VH, List *L);
void displayNoTrav(VHeap *VH, List *L);

void testInsertFunction(void (*insert)(VHeap *VH, List *L, int elem), VHeap *VH, List *L, char *name);
void deleteAll(VHeap *VH, List *L);
void displayList(VHeap VH, List L);

int main(void){
  VHeap VH;
  List L;

  initVHeap(&VH);
  testInsertFunction(push, &VH, &L, "push");
  pop(&VH, &L);
  pop(&VH, &L);
  pop(&VH, &L);
  displayNoTrav(&VH, &L);

  return 0;
}

void displayNoTrav(VHeap *VH, List *L){
  /*
    pop
    print val
    push val to temp stack

    after the loop ends, pop all values and push them back to L
  */
 if(*L != -1){
  List tempStack;
  int val;
  while(*L != -1){
    val = pop(VH, L);
    printf("%d ", val);
    push(VH, &tempStack, val);
  }
  while(tempStack != -1){
    val = pop(VH, &tempStack);
    push(VH, L, val);
  }
  printf("\n");
 }
}

void push(VHeap *VH, List *L, int elem){
  List temp = allocSpace(VH);
  if(temp != -1){
    VH->nodes[temp].elem = elem;
    VH->nodes[temp].next = *L;
    *L = temp;
  }
}

int pop(VHeap *VH, List *L){
  int top = -1;
  if(*L != -1){
    top = VH->nodes[*L].elem;
    List temp = *L;
    *L = VH->nodes[temp].next;
    deallocSpace(VH, temp);
  }
  return top;
}

void initList(List *L){
  *L = -1;
}

void deallocSpace(VHeap *VH, int index){
  VH->nodes[index].next = VH->avail;
  VH->avail = index;
}

int allocSpace(VHeap *VH){
  int index = VH->avail;
  if(index != -1){
    VH->avail = VH->nodes[index].next;
  }
  return index;
}

void initVHeap(VHeap *VH){
  int i;
  for(i=0;i<VH_SIZE;i++){
    VH->nodes[i].next = i-1;
  }
  VH->avail = VH_SIZE - 1;
}

void deleteAll(VHeap *VH, List *L){
  if(*L != -1){
    List temp;
    while(*L != -1){
      temp = *L;
      *L = VH->nodes[temp].next;
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