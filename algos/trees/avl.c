#include<stdio.h>
#include<stdlib.h>
#define max(a, b) ((a > b) ? a : b)

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
  int height;
} *AVL;

int getHeight(AVL node);
int getBalanceFactor(AVL node);
void insert(AVL *root, int data);
void balanceTree(AVL *root);
void leftRotate(AVL *node);
void rightRotate(AVL *node);
int getNewHeight(AVL node);

void preorder(AVL node){
  if(node != NULL){
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

int main(void) {

  AVL root = NULL;

  insert(&root, 12);
  insert(&root, 7);
  insert(&root, 15);
  insert(&root, 5);
  insert(&root, 10);
  preorder(root);
  printf("\n");

  insert(&root, 6);
  preorder(root);
  printf("\n");

  return 0;
}

void insert(AVL *root, int data){
  if (*root == NULL){
    AVL temp = (AVL)malloc(sizeof(struct node));
    if(temp != NULL){
      temp->data = data;
      temp->left = temp->right = NULL;
      *root = temp;
    }
  }else if(data < (*root)->data){
    insert(&(*root)->left, data);
  }else if(data > (*root)->data){
    insert(&(*root)->right, data);
  }

  // update node's height once insertion is done
  (*root)->height = getNewHeight(*root);

  // restore balance to tree
  balanceTree(root);
}

void balanceTree(AVL *root){
  if (*root == NULL)
    return;

  int bf = getBalanceFactor(*root);

  // Left-Left case
  if(bf > 1 && getBalanceFactor((*root)->left) >= 0){
    rightRotate(root);
  }

  // Right-Right
  else if(bf < -1 && getBalanceFactor((*root)->right) <= 0){
    leftRotate(root);
  }

  // Left-Right
  else if(bf > 1 && getBalanceFactor((*root)->left) < 0){
    leftRotate(&(*root)->left);
    rightRotate(root);
  }

  // Right-Left
  else if (bf < -1 && getBalanceFactor((*root)->right) > 0){
    rightRotate(&(*root)->right);
    leftRotate(root);
  }

}

void leftRotate(AVL *node){
  AVL temp = (*node)->right;

  (*node)->right = temp->left;
  temp->left = (*node);

  (*node)->height = getNewHeight(*node);
  temp->height = getNewHeight(temp);

  *node = temp;
}

void rightRotate(AVL *node){
  AVL temp = (*node)->left;

  (*node)->left = temp->right;
  temp->right = *node;

  (*node)->height = getNewHeight(*node);
  temp->height = getNewHeight(temp);

  *node = temp;
}

int getNewHeight(AVL node){
  return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getHeight(AVL node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalanceFactor(AVL node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}