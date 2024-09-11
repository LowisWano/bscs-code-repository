
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node{
    int elem;
    struct node *next;
}*linkedList, nodeItem;

typedef struct{
    int elem[MAX];
    int count;
}arrayList;

// given a linked list, delete the inputted element and insertSort the deleted element to a new array 
arrayList deleteAndInsertSorted(linkedList *L, arrayList *A, int elem);