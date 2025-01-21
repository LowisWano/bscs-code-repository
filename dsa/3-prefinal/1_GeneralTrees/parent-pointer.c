#include <stdio.h>
#include <stdlib.h>


// In this implementation, the tree is represented as an array of integers, where node is the index and its value is its parent.

#define MAX 10
#define ROOT -1 // signifies that this node is the root
#define NONEXISTENT -2 // signifies that this node does not exist within the tree

typedef int Tree[MAX];

Tree *initTree();                             // sets all node as nonexistent
void insert(int node, int parent, Tree *T);   // insert node and set its parent as its value
void inorder(int root, Tree T);               // child(1) -> parent -> child(2) -> ... -> child(n)
int findRoot(Tree T);                         
void displayParents(int node, Tree T);

int main(void){

  Tree *T = initTree();
  insert(5, ROOT, T);
  insert(2, 5, T);
  insert(3, 2, T);
  displayParents(3, *T);
  return 0;
}

void displayParents(int node, Tree T){
  if(node >= 0 && node < MAX){
    int i;
    for(i=node;T[i]!=ROOT; i = T[i]){
      printf("%d ", i);
    }
    printf("-> %d", i);
    printf("\n");
  }
}

// @params: elem to insert, its parent (the index of another node or -1 to signify it is the root), and the tree
void insert(int node, int parent, Tree *T){
  if(node>=0 && node<MAX && parent < MAX){
    if((*T)[node] == NONEXISTENT){
      (*T)[node] = parent;
    }else{
      printf("Node already exists!");
    }
  }else{
    printf("Element or parent out of bounds!");
  }
}

int findRoot(Tree T){
  int i;
  for(i=0;i<MAX && T[i] != ROOT;i++){}
  return i<MAX ? i: NONEXISTENT;
}

// set all node as nonexistent
Tree *initTree(){
  Tree *T = (Tree*)malloc(sizeof(Tree));
  if(T!= NULL){
    int i;
    for(i=0;i<MAX;i++){
      (*T)[i] = NONEXISTENT;
    }
    return T;
  }
}