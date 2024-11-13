#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 10

typedef struct node {
  int data;
  struct node *LC;
  struct node *RC;
}*Tree, NodeType;

void initTree(Tree *T);
void populateTree(Tree *T, int[]);
void insert(Tree *T, int elem);
void delete(Tree *T, int elem);
bool search(Tree T, int elem);
void preorder(Tree T);
void inorder(Tree T);
void postorder(Tree T);

int main(void){

  Tree T;
  int data[MAX] = {5, 1, 3, 7, 4, 2, 8, 5, 9, 6};
  populateTree(&T, data);
  preorder(T);
  printf("\n");
  inorder(T);
  printf("\n");
  postorder(T);
  printf("\n");
  // delete(&T, 5);
  // printf("\n");
  // preorder(T);
  // printf("\n");
  return 0;
}

void inorder(Tree T){
  if(T!=NULL){ 
    inorder(T->LC);
    printf("%d ", T->data);
    inorder(T->RC);
  }
}

void postorder(Tree T){
  if(T!=NULL){ 
    postorder(T->LC);
    postorder(T->RC);
    printf("%d ", T->data);
  }
}


void preorder(Tree T){
  if(T!=NULL){
    printf("%d ", T->data);
    preorder(T->LC);
    preorder(T->RC);
  }
}

void delete(Tree *T, int elem){
  Tree *trav;
  // traverse until element is found
  for(trav=T; *trav != NULL && (*trav)->data != elem; trav = (elem > (*trav)->data) ? &(*trav)->RC : &(*trav)->LC){}

  if(*trav != NULL){
    Tree temp;

    // if node has 2 children
    if((*trav)->LC != NULL && (*trav)->RC != NULL){
      // go to smallest right child
      Tree *nearest = &(*trav)->RC;

      // in case if there is still a smaller child
      while((*nearest)->LC != NULL){
        nearest = &(*nearest)->LC;
      }

      // delete node with one child (also covers if no child at all)
      (*trav)->data = (*nearest)->data;
      temp = *nearest;
      *nearest = (*nearest)->RC;
    }else{
      // delete node with one child (also covers if no child at all)
      temp = *trav;
      *trav = ((*trav)->LC != NULL) ? (*trav)->LC : (*trav)->RC;
    }
    free(temp);
  }
}

void insert(Tree *T, int elem){
  Tree new = malloc(sizeof(NodeType));
  if(new != NULL){
    new->LC = NULL;
    new->RC = NULL;
    new->data = elem;

    Tree *trav = T;
    while(*trav != NULL && (*trav)->data != elem){
      if((*trav)->data < elem){
        trav = &(*trav)->RC;
      }else{
        trav = &(*trav)->LC;
      }
    }
    if(*trav == NULL){
      *trav = new;
    }
    
  }
}

void populateTree(Tree *T, int arr[]){
  int i;
  for(i=0;i<MAX;i++){
    insert(T, arr[i]);
  }
}

void initTree(Tree *T){
  *T = NULL;
}