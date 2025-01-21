#include<stdio.h>
#include<stdlib.h>
#define MAX 10

// version 1 ADT List array implementation
typedef struct{
    int elem[MAX];
    int count
}List;

// insert operations
void insertFirst(List *L, int elem);
void insertSorted(List *L, int elem);
void insertLast(List *L, int elem);

// delete operations
void deleteFirstOccurence(List *L, int elem);
void deleteAllOccurences(List *L, int elem);

// mix
void deleteAndMakeNewList(List *L, List *newList, int elem);