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
bool deleteBST(BST *bst, int data);
BST createNode(int data);

void delete(BST *root, int e);
int min(BST root);

// DFS
void postOrder(BST bst);
void preOrder(BST bst);
void inOrder(BST bst);

int main(void){
  BST bst = NULL;

  // order in inserting does matter
  insertBST(&bst, 48);
  insertBST(&bst, 27);
  insertBST(&bst, 64);
  insertBST(&bst, 22);
  insertBST(&bst, 45);
  insertBST(&bst, 52);
  insertBST(&bst, 97);
  insertBST(&bst, 21);
  insertBST(&bst, 46);
  
  preOrder(bst);
  printf("\n");

  // does not work on root
  deleteBST(&bst, 48);
  preOrder(bst);

  printf("\n");
  return 0;
}

/*
// solution before optimizing
bool deleteBST(BST *bst, int e){
  if(*bst != NULL){
    BST temp;
    if(e < (*bst)->data){
      deleteBST(&(*bst)->LC, e);
    }else if(e > (*bst)->data){
      deleteBST(&(*bst)->RC, e);
    }else if((*bst)->data == e && (*bst)->LC == NULL && (*bst)->RC == NULL){
      temp = *bst;
      *bst = NULL;
      free(temp);
      return true;
    }else if((*bst)->data == e && (*bst)->RC != NULL){
      temp = *bst;
      (*bst)->RC->LC = (*bst)->LC;
      *bst = (*bst)->RC;
      free(temp);
      return true;
    }else if((*bst)->data == e && (*bst)->RC == NULL){
      temp = (*bst)->RC;
      *bst = (*bst)->LC;
      free(temp);
      return true;
    }
  }
  return false;
}
*/

// what happens again when you delete the root node?
// smallest leaf in the right tree becomes the new root node
// My thought process in here just happens to coincidentally work in some cases. But the principle is, the node that takes over is the right child closest to its value e.g. the minimum right child
bool deleteBST(BST *bst, int e){
  if(*bst != NULL){
    if(e < (*bst)->data){
      deleteBST(&(*bst)->LC, e);
    }else if(e > (*bst)->data){
      deleteBST(&(*bst)->RC, e);
    }else if((*bst)->data == e){
      // if only has LC, LC takes over position
      // if only has RC, RC takes over

      // if both child, min of RC takes over, original pos of min gets freed
      // if no child, delete. 
    }
  }
  return false;
}

int min(BST bst){
  if(bst->LC || bst->RC ){
    if(bst->LC != NULL){
      min(bst->LC);
    }else if(bst->RC != NULL){
      min(bst->RC);
    }
  }
  return bst->data;
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

// // fitz' solution
// void delete(BST *root, int e) {
//   if (*root == NULL) return;
//   if (e < (*root)->data) {
//       delete(&(*root)->LC, e);
//   } else if (e > (*root)->data) {
//       delete(&(*root)->RC, e);
//   } else {
//       if ((*root)->LC == NULL) {
//           BST temp = (*root)->RC;
//           free(*root);
//           *root = temp;
//       } else if ((*root)->RC == NULL) {
//           BST temp = (*root)->LC;
//           free(*root);
//           *root = temp;
//       } else {
//           // i think this is the part in his solution when the root is deleted
//           (*root)->data= min((*root)->RC);
//           delete(&(*root)->RC, (*root)->data);
//       }
//   }
// }

// int min(BST root) {
//   return (root != NULL) ? (root->LC == NULL) ? root->data : min(root->LC) : -1;
// }
