#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *LC;
    struct node *RC;
} NodeType, *NodePtr, *BST;

typedef struct nodeQ{
    BST data;
    struct nodeQ *next;
}*NodeQPtr;

void initBST(BST *bst);
BST newBST();// same ^^
bool insertBST(BST *bst, int data);
bool deleteBST(BST bst, int data);
BST createNode(int data);

// DFS
void postOrder(BST bst);
void preOrder(BST bst);
void inOrder(BST bst);

int main(void){
  BST bst = NULL;

  insertBST(&bst, 48);
  insertBST(&bst, 27);
  insertBST(&bst, 64);
  insertBST(&bst, 22);
  insertBST(&bst, 45);
  insertBST(&bst, 52);
  insertBST(&bst, 97);
  insertBST(&bst, 21);
  
  preOrder(bst);

  printf("\n");
  return 0;
}

bool insertBST(BST *bst, int e){
  if(*bst == NULL){
    *bst = createNode(e);
    return true;
  }else if(e < (*bst)->data){
    insertBST(&(*bst)->LC, e);
  }else if(e > (*bst)->data){
    insertBST(&(*bst)->RC, e);
  }
  return false;
}

BST newBST(){
  BST new = malloc(sizeof(NodeType));
  new->LC = NULL;
  new->RC = NULL;
  new->data = -1;
  return new;
}

void preOrder(BST bst){
  if(bst!=NULL){
    printf("%d ", bst->data);
    preOrder(bst->LC);
    preOrder(bst->RC);
  }
}

BST createNode(int data) {
  BST newNode = (BST)malloc(sizeof(NodeType));
  newNode->data = data;
  newNode->LC = NULL;
  newNode->RC = NULL;

  return newNode;
}
