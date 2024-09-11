#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdio.h>
#include<stdlib.h>

// structures
typedef struct node{
  int elem;
  struct node *next;
}*nodePtr, nodeType;

typedef struct{
  nodePtr top;
}Stack;

// core functions
void initializeStack(Stack *S);

void PUSH(Stack *S, int elem);
void POP(Stack *S);
int TOP(Stack S);

// utility functions
int isEmpty(Stack S);
int isFull(Stack S);
void displayStack(Stack S);

#endif