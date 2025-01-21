#include"header.h"

int main(void){

  Personlist P;
  PersonOpenDict OD;
  
  initializePersonList(&P);
  populatePersonList(&P);
  
  int i;
  printf("People data: \n");
  for(i=0;i<P.count; i++){
    printf("id: %d - %s - %s\n", P.list[i].id,P.list[i].name, P.list[i].add.city);
  }
  printf("\n");

  String city;
  strcpy(city, "NewYork");
  
  StackLList S = getVoters(P, city);
  displayStackLList(S);
  
  initializeOpenDict(&OD);
  populateOpenDict(&OD);
  String *names = getNames(OD, city);
  displayNames(names);
  
   QueuePersonList Q;
   initializeQueueList(&Q);
  getAllUniqueVoters(S, &Q);
  displayQueue(Q);
}