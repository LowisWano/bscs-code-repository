#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define ROOT -1

typedef struct node{
  int elem;
  struct node *next;
}*Node, NodeType;

typedef struct{
  Node nodes[MAX];          // index itself is the element, the nodes it is connected to are the children
  int root;
}Tree;

void initTree(Tree *T);
void insert(int elem, int parent, Tree *T);
void preorder(Tree T, Node node);
void inorder(Tree T, Node node);

int main(void){
  Tree T;
  initTree(&T);
  insert(5, ROOT, &T);

  insert(0, 5, &T);
  insert(6, 5, &T);
  insert(2, 5, &T);
  
  insert(3, 6, &T);
  insert(1, 6, &T);
  
  insert(4, 1, &T);
  insert(7, 1, &T);

  insert(8, 2, &T);

  printf("%d ", T.root);
  preorder(T, T.nodes[T.root]);
  printf("\n");

  printf("%d ", T.root);
  inorder(T, T.nodes[T.root]);
  printf("\n");
  return 0;
}

/* 
  I think this is where recursion becomes necessary. There are n amount of times you have to traverse for every node that
  has children, and therefore do not know how many times you should traverse. Hardcoding multiple for loops won't work on this one. 
  You will have to use recursion.
*/
void preorder(Tree T, Node node){
  if(node!=NULL){
    Node trav;
    for(trav=node; trav!=NULL; trav=trav->next){
      printf("%d ", trav->elem);
      preorder(T, T.nodes[trav->elem]);
    }
  }
}

void inorder(Tree T, Node node){
  if(node!=NULL){
    inorder(T, T.nodes[node->elem]);
    for()
  }
}

void insert(int elem, int parent, Tree *T){
  if(elem >= 0 && elem < MAX){
    if(parent == ROOT){     // if element to be inserted is the root
      T->root = elem;
    }else{                  // if element has a parent 
      Node *trav;
      for(trav=&(T->nodes[parent]); *trav!=NULL; trav=&(*trav)->next){}
      *trav = malloc(sizeof(NodeType));
      (*trav)->elem = elem;
      (*trav)->next = NULL;
    }
  }
}

void initTree(Tree *T){
  T->root = ROOT;
  int i;
  for(i=0;i<MAX;i++){
    T->nodes[i] = NULL;
  }
}