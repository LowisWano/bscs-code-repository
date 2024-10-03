#include"header.h"

int main(void){

  Personlist P;
  PersonOpenDict OD;
  
  initializePersonList(&P);
  populatePersonList(&P);
  
  int i;
  printf("People data: \n");
  for(i=0;i<P.count; i++){
    printf("%s\n", P.list[i].name);
  }
  printf("\n");

   StackLList S = getVoters(P, "NewYork");
   displayStackLList(S);
  
  initializeOpenDict(&OD);
  populateOpenDict(&OD);
   String *names = getNames(OD, "NewYork");
   displayNames(names);
  
  // QueuePersonList Q;
  // initializeQueueList(&Q);
  // getAllUniqueVoters(S, &Q);
}