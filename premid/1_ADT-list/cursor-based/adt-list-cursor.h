#ifndef CURSOR_H
#define CURSOR_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef struct{
  char elem;
  int next;
}nodeType;

typedef struct{
  nodeType nodes[MAX];
  int avail;
}VirtualHeap;

typedef int List;

/**
 *  Virtual Heap Management Operations:
 *  1. initializeVH: prepares the virtual heap for use
 *  2. allocSpace: works just like malloc()
 *  3. deallocSpace: works just like free()
 */
void initializeVHeapV2(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);

/**
 * ADT LIST Operations
 */
void insertFirst(VirtualHeap *VH, List L, char elem);
void insertSorted(VirtualHeap *VH, List L, char elem);
void insertLast(VirtualHeap *VH, List L, char elem);

void deleteFirstOcc(VirtualHeap *VH, List L, char elem);
void deleteAllOcc(VirtualHeap *VH, List L, char elem);

/**
 * Utility Functions
 */
void displayList(VirtualHeap VH, List L);
int listIsEqualSorted(VirtualHeap VH);
int listIsEqualUnsorted(VirtualHeap VH);

#endif