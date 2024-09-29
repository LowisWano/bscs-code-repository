#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

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

int getHash(Student s);
void initDictionary(HashTable *ht);
Student createStudent(char *name, char *course, int id, int year);

int insert(HashTable *ht, Student s);
int delete(HashTable *ht, Student s);
void visualizeTable(HashTable ht);


int main(void) {
  HashTable ht;
  initDictionary(&ht);

  Student s1 = createStudent("Luis", "BSCS", 23100371, 2);
  Student s2 = createStudent("Kentward", "BSIT", 23100372, 2);
  Student s3 = createStudent("Luib", "BSCS", 23100379, 2);
  Student s4 = createStudent("Luia", "BSCS", 23100377, 2);
  Student s5 = createStudent("Paul", "BSCS", 23100374, 2);

  insert(&ht, s1);
  insert(&ht, s2);
  insert(&ht, s3);
  insert(&ht, s4);
  insert(&ht, s5);
  visualizeTable(ht);

  delete(&ht, s2);
  delete(&ht, s4);
  visualizeTable(ht);
  
  return 0;
}

int delete(HashTable *ht, Student s){
  int num = getHash(s);
  NodePtr temp, *trav = &(ht->elems[num]);
  
  for(;*trav!=NULL && s.studID != (*trav)->stud.studID; trav=&(*trav)->link){}
  if(*trav != NULL){
    temp = *trav;
    *trav = (*trav)->link;
    free(temp);
  }
  return (*trav != NULL) ? 1: 0;
}

// insert sorted by id, does not insert if element already exists
int insert(HashTable *ht, Student s){
  int num = getHash(s);
  NodePtr *trav = &(ht->elems[num]);

  NodePtr temp = malloc(sizeof(NodeType));
  temp->stud = s;
  
  for(;*trav!=NULL && s.studID >= (*trav)->stud.studID; trav=&(*trav)->link){
    if(s.studID == (*trav)->stud.studID){
      return 0;
    }
  }
  temp->link = *trav;
  *trav = temp;

  ht->count++;
  return 1;
}

// sum of the three letters in the name plus all the letters in the program
int getHash(Student s){
  int sum = s.studName[0] + s.studName[2] + s.studName[2];
  int i;
  for(i=0;i<s.program[i] != '\0'; i++){
    sum += s.program[i];
  }
  return sum % MAX-1;
}

void initDictionary(HashTable *ht){
  int i;
  for(i=0;i<MAX;i++){
    ht->elems[i] = NULL;
  }
  ht->count = 0;
}

Student createStudent(char *name, char *program, int id, int year){
  Student new;
  strcpy(new.studName, name);
  strcpy(new.program, program);
  new.studID = id;
  new.year = year;
  return new;
}

void visualizeTable(HashTable ht){
  int i;
  NodePtr trav;
  for(i=0;i<MAX;i++){
    printf("%d - ", i);
    for(trav=ht.elems[i]; trav!=NULL ;trav=trav->link){
      printf("%s -> ", trav->stud.studName);
    }
    printf("NULL");
    printf("\n");
  }
  printf("\n");
}