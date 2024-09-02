#include "./array-headers/arrayStack.h"

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
  // stack with full elements
  displayStack(S);
  printf("is full? %d\n", isFull(S));
  printf("is empty? %d\n", isEmpty(S));

  POP(&S);
  POP(&S);
  // stack with 2 elements popped
  displayStack(S);
  printf("is full? %d\n", isFull(S));

  // top value is 3
  printf("top value: %d\n", TOP(S));

  return 0;
}