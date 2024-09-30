#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
#define EMPTY -1
#define DELETED -2

typedef int ClosedDict[MAX];

int getHash(int elem);
void initDict(ClosedDict d);
void insert(ClosedDict d, int elem);
void visualize(ClosedDict d);
void delete(ClosedDict d, int elem);

int main(void){
  ClosedDict d;
  initDict(d);
  printf("inserting elements....\n");
  insert(d, 1);
  insert(d, 1); // test uniqueness
  insert(d, 2);
  insert(d, 3);
  insert(d, 4);
  insert(d, 5);
  insert(d, 20); // test collision
  insert(d, 6); // test displacement

  visualize(d);

  printf("deleting 9...\n");
  delete(d, 9);
  delete(d, 15);
  visualize(d);
  return 0;
}

void delete(ClosedDict d, int elem){
  int hash = getHash(elem);
  int i;
  for(i=0; i<MAX && d[hash] != elem; i++, hash = (hash + 1) % MAX){}
  if(i<MAX){
    d[hash] = DELETED;
  }else{
    printf("Could not find the element %d!\n", elem);
  }
}

void visualize(ClosedDict d){
  int i;
  for(i=0;i<MAX; i++){
    printf("%d - ", i);
    if(d[i] != EMPTY && d[i] != DELETED){
      printf("%d",d[i]);
    }else if(d[i] == EMPTY){
      printf("EMPTY");
    }else if(d[i] == DELETED){
      printf("DELETED");
    }
    printf("\n");
  }
  printf("\n");
}

void insert(ClosedDict d, int elem){
  //get hash
  int hash = getHash(elem);
  printf("elem - %d, hash value - %d\n", elem, hash);
  int i;
  // traverse while i < MAX (acts as counter to check if the list has been fully circulated),
  // hash position is not emtpy,
  // hash position does not contain same elem
  for(i=0; i<MAX  && d[hash] != EMPTY && d[hash] != elem; hash = (hash + 1) % MAX, i++){}
  if(i<MAX){
    d[hash] = elem;  
  }else{
    printf("Dictionary is full!");
  }
}

void initDict(ClosedDict d){
  int i;
  for(i=0;i<MAX;i++){
    d[i] = EMPTY;
  }
}

// a hash function could literally be anything
int getHash(int elem){
  return (elem + 36) % MAX;
}