// #include "./array-headers/arrayStack.h"
#include "./linklist-headers/linkStack.h"

int main(void){
  Stack S;

  initializeStack(&S);
  printf("is empty? %d\n", isEmpty(S));

  PUSH(&S, 1);
  PUSH(&S, 2);
  PUSH(&S, 3);
  PUSH(&S, 4);
  PUSH(&S, 5);
  PUSH(&S, 6); // 6 does not get pushed because stack is full
  
  printf("Stack with full elements (does not apply to linked list)\n");
  displayStack(S);
  printf("is full? %d\n", isFull(S));
  printf("is empty? %d\n", isEmpty(S));

  POP(&S);
  POP(&S);

  // stack with 2 elements popped
  printf("deleting 2 elements... \n");
  displayStack(S);
  printf("is full? %d\n", isFull(S));

  // top value is 3
  printf("top value: %d\n", TOP(S));

  return 0;
}