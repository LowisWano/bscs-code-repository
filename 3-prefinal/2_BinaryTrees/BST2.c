#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  int val;
  struct node *LC;
  struct node *RC;
}*BST, nodeType;

BST createNode(int elem);
void insertNode(BST *T, int elem);
void preorder(BST T);
void inorder(BST T);
void populateTree(BST *T);
void treeTraversal(void (*traverse)(BST T), BST T);
void deleteNode(BST *T, int elem);
void getInputAndDelete(BST *T);

int main(void){
  BST T = NULL;
  populateTree(&T);

  treeTraversal(preorder, T);
  getInputAndDelete(&T);
  treeTraversal(preorder, T);
  return 0;
}

void getInputAndDelete(BST *T){
  int x;
  printf("Give an element to delete: ");
  scanf("%d", &x);
  deleteNode(T, x);
}

void deleteNode(BST *T, int elem){
  BST *trav;
  for(trav=T; *trav != NULL && (*trav)->val != elem; trav = (elem <= (*trav)->val) ? &(*trav)->LC : &(*trav)->RC){}
  if(*trav != NULL){
    BST temp;
    if((*trav)->RC != NULL && (*trav)->LC != NULL){
      // move to right subtree
      BST *nearest = &(*trav)->RC;

      while((*nearest)->LC != NULL){
        nearest = &(*nearest)->LC;
      }

      (*trav)->val = (*nearest)->val;

      temp = *nearest;
      *nearest = (*nearest)->RC;
    }else{
      temp = *trav;
      *trav = ((*trav)->LC != NULL) ? (*trav)->LC : (*trav)->RC; 
    }
    free(temp);
  }else{
    printf("%d is not in the tree!\n", elem);
  }
}

void treeTraversal(void (*traverse)(BST T), BST T){
  if(T == NULL){
    printf("Empty!\n");
  }else{
    traverse(T);
    printf("\n");
  }
}

void insertNode(BST *T, int elem){
  BST node = createNode(elem);
  if(node != NULL){
    BST *trav;
    for(trav=T; *trav != NULL;){
      if(elem <= (*trav)->val){
        trav=&(*trav)->LC;
      }else{
        trav=&(*trav)->RC;
      }
    }
    *trav = node;
  }
}

BST createNode(int elem){
  BST node = malloc(sizeof(nodeType));
  node->val = elem;
  node->LC = NULL;
  node->RC = NULL;
  return node;
}

void populateTree(BST *T){
  int fixedValues[10] = {5, 7, 4, 6, 8, 1, 3};
  for(int i = 0; i < 7; i++) {
    insertNode(T, fixedValues[i]);
  }
}

void preorder(BST T){
  if(T!=NULL){
    printf("%d ", T->val);
    preorder(T->LC);
    preorder(T->RC);
  }
}

void inorder(BST T){
  if(T!=NULL){
    inorder(T->LC);
    printf("%d ", T->val);
    inorder(T->RC);
  }
}