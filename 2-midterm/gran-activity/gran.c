#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 20
/**
 * Open hashing: 
 * Closed hashing: 
 * 
 */

typedef struct {
  int studID;
  char studName[30];
  char program[10];
  int year;
}Student;

typedef struct node {
  Student stud;
  struct node *link;
}NodeType, *NodePtr;

typedef struct {
  NodePtr elems[MAX];
  int count;
}HashTable;

/**
 * Get the hash based on the summation of the first 3 letters of the name plus the letters in the program and must be able to return a value from 0 -19
 */
int getHash(Student s);
void initDictionary(HashTable *ht);
Student createStudent(char *name, char *course, int id, int year);

/**
 * Use insert sorted if multiple data are already in the list
 */
int insert(HashTable *ht, Student s);
int delete(HashTable *ht, Student s);
void visualizeTable(HashTable ht);

int main(void){
  HashTable ht;
  initDictionary(&ht);

  Student s = createStudent("Paul", "BSCS", 23100371, 2);
  insert(&ht, s);
  visualizeTable(ht);
  delete(&ht, s);
  visualizeTable(ht);
  return 0;
}

int delete(HashTable *ht, Student s){
  int hash = getHash(s);
  NodePtr *head = &(ht->elems[hash]); 
  NodePtr *trav, temp;

  for(trav=head;*trav!=NULL && s.studID != (*trav)->stud.studID;trav=&(*trav)->link){}
  if(*trav != NULL){
    temp = *trav;
    *trav = (*trav)->link;
    free(temp);
  }
  return (*trav != NULL) ? 1:0;
}

/**
 * cannot insert if same element or threshold is reached, ideally size is increased if max is reach
 */
int insert(HashTable *ht, Student s){
  int hash = getHash(s);
  NodePtr *head = &(ht->elems[hash]); 
  NodePtr *trav, temp;
  
  /**
   * will have to break mdm pena's rule for this one cuz condition will be too unreadable
   * !important: always keep in mind that conditions evaluate left to right, if the left condition is not satisfied, the condition on the right will not run at all
   */
  for(trav=head;*trav != NULL && s.studID >= (*trav)->stud.studID; trav = &(*trav)->link ){
    if((*trav)->stud.studID == s.studID){
      printf("student already exists!\n");
      return 0;
    }
  }
  temp = malloc(sizeof(NodeType));
  temp->stud = s;
  temp->link = *trav;
  *trav = temp;
  ht->count++;
  return 1;
}

void visualizeTable(HashTable ht){
  int i;
  NodePtr trav;
  printf("\n");
  for(i=0;i<MAX;i++){
    printf("%d - ", i);
    for(trav = ht.elems[i]; trav!=NULL; trav=trav->link){
      printf("[%d] %s - ", trav->stud.studID, trav->stud.studName);
    }
    if(trav == NULL){
      printf("NULL");
    }
    printf("\n");
  }
}

Student createStudent(char *name, char *course, int id, int year){
  Student s;
  strcpy(s.studName, name);
  strcpy(s.program, course);
  s.studID = id;
  s.year = year;
  return s;
}

int getHash(Student s){
  int sum;
  sum = s.studName[0] + s.studName[1] + s.studName[2]; 
  for(int i = 0; s.program[i] != '\0'; i++){
    sum += s.program[i];
  }
  return sum % MAX;
}

void initDictionary(HashTable *ht){
  int i = 0;
  for(i=0;i<MAX;i++){
    ht->elems[i] = NULL;
  }
  ht->count = 0;
}