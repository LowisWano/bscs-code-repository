#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXPEOPLE 20
#define MAXDICT 5

typedef char String[16];

typedef struct{
    String city;
    int zip;
}Address;

typedef struct{
    int id;
    String name;
    Address add;
}Person;

typedef struct{
    Person *list; // dynamically allocated array
    int count;
    int max;
}Personlist, StackAList, PersonCloseDict;

typedef struct{
    Person list[MAXPEOPLE];
    int front;
    int rear;
}QueueAList;

typedef struct node{
    Person p;
    struct node *link;
}NodeType, *NodePtr, *StackLList;

typedef struct{
    NodePtr list[MAXDICT];
    int count;
}PersonOpenDict;

typedef struct{
    NodePtr head;
    NodePtr tail;
}QueuePersonList;

StackLList getVoters(Personlist vlist, String city);
String* getNames(PersonOpenDict d, String city);
void getAllUniqueVoters(StackLList S, QueuePersonList *Q);

void initializePersonList(Personlist *P);
void populatePersonList(Personlist *P);

void  initializeOpenDict(PersonOpenDict *OD);
void populateOpenDict(PersonOpenDict *OD);

void intializeStackLList(StackLList *OD);
void populateStackLList(StackLList *OD);

void initializeQueueList(QueuePersonList *Q);

void displayStackLList(StackLList S);
void displayNames(String *names);
void displayQueue(QueuePersonList Q);
int hash(int id);

#endif