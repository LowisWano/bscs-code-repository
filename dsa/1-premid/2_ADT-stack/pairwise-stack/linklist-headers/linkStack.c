#include "./linkStack.h"
/**
 * Linked list implementation of stack works just like a normal linked list, except the only operations you can do are insertFirst 
 * and deleteFirst
 * 
 */

void initializeStack(Stack *S){
  S->top = NULL;
}

int isEmpty(Stack S){
  return S.top == NULL;
}

int isFull(Stack S){
  return 0;
}

int TOP(Stack S){
  return !isEmpty(S) ? S.top->elem : -1;
}

void PUSH(Stack *S, int elem){
  nodePtr temp = malloc(sizeof(nodeType));
  if(temp != NULL){
    temp->elem = elem;
    temp->next = S->top;
    S->top = temp;
  }
}

void POP(Stack *S){
  if(!isEmpty(*S)){
    nodePtr temp = S->top;
    S->top = S->top->next;
    free(temp);
  }
}

void displayStack(Stack S){
  nodePtr trav;
  for(trav=S.top;trav!=NULL;trav=trav->next){
    printf("%d ", trav->elem);
  }
  printf("\n \n");
}





