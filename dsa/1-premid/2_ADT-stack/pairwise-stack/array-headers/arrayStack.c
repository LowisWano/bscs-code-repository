// function definitions
#include "./arrayStack.h"

void initializeStack(Stack *S){
  S->top = -1;
}

void PUSH(Stack *S, int elem){
  if(S->top < MAX - 1){
    S->elem[++S->top] = elem;
  }
}

void POP(Stack *S){
  if(S->top >= 0){
    S->top--;    
  }
}

int TOP(Stack S){
  return S.top >= 0 ? S.elem[S.top] : -1;
}

void displayStack(Stack S){
  if(S.top >= 0){
    int i;
    for(i=S.top;i>=0;i--){
      printf("%d ", S.elem[i]);
    }
  }else{
    printf("stack is empty!");
  }
  printf("\n \n");
}

int isEmpty(Stack S){
  return S.top < 0 ? 1 : 0;
}

int isFull(Stack S){
  return S.top == MAX-1? 1:0;
}