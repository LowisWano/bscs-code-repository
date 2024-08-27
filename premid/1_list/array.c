#include<stdio.h>
#include<stdlib.h>
#define  MAX 10

// version 1 array list implementation
typedef struct{
  int elem[MAX];
  int count;
}LIST;

// Linked List ADT Implementation
typedef struct node {
  int elem[MAX];
  struct node *next;
}*LIST;

