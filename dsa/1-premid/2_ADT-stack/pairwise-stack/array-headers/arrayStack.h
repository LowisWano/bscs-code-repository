#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

// structures
typedef struct{
  int elem[MAX];
  int top;
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