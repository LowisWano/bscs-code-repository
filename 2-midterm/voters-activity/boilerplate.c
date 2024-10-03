#include"header.h"

/**
 * PROBLEM 1: Get all the voters living in the specified city and store it to a StackLList to be returned
 */
StackLList getVoters(Personlist vlist, String city){
  // code here...
}

/**
 * PROBLEM 2: Get the names of all voters with IDs 1 to 10 that are residing in a specified city and store it in an array of strings to be returned
 * Add a sentinel using an empty string
 */
String* getNames(PersonOpenDict d, String city){
   // code here...
}   

/**
 * PROBLEM 3: Get all unique voters in StackLList and store it to a QueuePersonList
 */
void getAllUniqueVoters(StackLList S, QueuePersonList *Q){
    // code here....
}


// HELPER FUNCTIONS
void displayQueue(QueuePersonList Q){
    /*
        print head
        dequeue then enqueue to tempQ
        reattach tempQ to origQ
    */
    QueuePersonList tempQ;
    tempQ.head=NULL;
    tempQ.tail=NULL;
    NodePtr holder;
    printf("\nQUEUE ELEMENTS:\n");
    while(Q.head!=NULL){
        holder = Q.head;
        printf("%d: %s\n", holder->p.id,holder->p.name);
        
        Q.head = Q.head->link;
        holder->link = NULL;
        
        if(tempQ.head == NULL){
            tempQ.head = holder;
            tempQ.tail = holder;
        }else{
            tempQ.tail->link = holder;
            tempQ.tail = holder;
        }
    }
    Q.tail = NULL;
    
    Q.head = tempQ.head;
    Q.tail = tempQ.tail;
    tempQ.head = NULL;
    tempQ.tail = NULL;
}


void initializePersonList(Personlist *P){
    P->max = MAXPEOPLE;
    P->count = 0;
    P->list = malloc(sizeof(Person)*MAXPEOPLE);
}

void populatePersonList(Personlist *P) {
    Person persons[] = {
        {1, "John", {"NewYork", 10001}},
        {2, "Alice", {"LosAngeles", 90001}},
        {3, "Bob", {"Chicago", 60601}},
        {4, "Diana", {"Houston", 77001}},
        {5, "Eve", {"Phoenix", 85001}},
        {6, "Frank", {"LosAngeles", 90001}},      // Same city as Alice
        {7, "Grace", {"NewYork", 10001}},         // Same city as John
        {1, "John", {"NewYork", 10001}},          // Duplicate of John
        {9, "Bob", {"Chicago", 60601}},           // Duplicate of Bob
        {10, "Leo", {"Chicago", 60601}},          // Same city as Bob
        {11, "Karen", {"Phoenix", 85001}},        // Same city as Eve
        {12, "Ivy", {"SanDiego", 92101}},
        {13, "Mia", {"FortWorth", 76101}},
        {14, "Diana", {"Houston", 77001}},        // Duplicate of Diana
        {15, "Oscar", {"Charlotte", 28201}},
    };

    int numPersons = sizeof(persons) / sizeof(persons[0]);

    if (numPersons > P->max) {
        printf("Too many persons to add! Max is %d\n", P->max);
        numPersons = P->max;
    }

    // Populate the list with predefined persons
    for (int i = 0; i < numPersons; i++) {
        P->list[P->count++] = persons[i];
    }
}

void initializeOpenDict(PersonOpenDict *OD){
    int i;
    for(i=0;i<MAXDICT;i++){
      OD->list[i] = NULL;
    }
    OD->count = 0;
}

int hash(int id){
  return id % MAXDICT;
}

void populateOpenDict(PersonOpenDict *OD){
    Person persons[] = {
        {1, "John", {"NewYork", 10001}},
        {2, "Alice", {"LosAngeles", 90001}},
        {3, "Bob", {"Chicago", 60601}},
        {4, "Diana", {"Houston", 77001}},
        {5, "Eve", {"Phoenix", 85001}},
        {6, "Frank", {"LosAngeles", 90001}},      // Same city as Alice
        {7, "Grace", {"NewYork", 10001}},         // Same city as John
        {8, "John", {"NewYork", 10001}},          // Duplicate of John
        {9, "Bob", {"Chicago", 60601}},           // Duplicate of Bob
        {10, "Leo", {"Chicago", 60601}},          // Same city as Bob
        {11, "Karen", {"Phoenix", 85001}},        // Same city as Eve
        {12, "Ivy", {"SanDiego", 92101}},
        {13, "Mia", {"FortWorth", 76101}},
        {14, "Diana", {"Houston", 77001}},        // Duplicate of Diana
        {15, "Oscar", {"Charlotte", 28201}},
    };

    int numPersons = sizeof(persons) / sizeof(persons[0]);

    if (numPersons > MAXPEOPLE) {
        printf("Too many persons to add!\n");
    }

    // Populate the list with predefined persons
    for (int i = 0; i < numPersons; i++) {
      int index = hash(persons[i].id);  
      
      NodePtr temp = malloc(sizeof(NodeType));
      if (temp == NULL) {
          printf("Memory allocation failed\n");
          exit(1);
      }
      temp->p = persons[i];
      temp->link = OD->list[index]; 
      OD->list[index] = temp;
      OD->count++;
    }

    for (int i = 0; i < MAXDICT; i++) {
      printf("Bucket %d: ", i);
      NodePtr temp = OD->list[i];
      while (temp != NULL) {
          printf("-> %d-%s ", temp->p.id,temp->p.name);
          temp = temp->link;
      }
      printf("\n");
    }
}

void initializeQueueList(QueuePersonList *Q){
    Q->head = NULL;
    Q->tail = NULL;
}

void intializeStackLList(StackLList *OD){
    // code here
}

void populateStackLList(StackLList *OD){
    // code here
}

void displayStackLList(StackLList S){
    // code here
    StackLList tempStack = NULL, temp;
    printf("Stack elements:\n");
    
    while(S!=NULL){
        printf("%s - id: %d\n", S->p.name, S->p.id);
        temp = tempStack;
        tempStack = S;
        S = S->link;
        tempStack->link = temp;
    }
    
    while(tempStack != NULL){
        temp = S;
        S = tempStack;
        tempStack = tempStack->link;
        S->link = temp;
    }
    printf("\n");
}

void displayNames(String *names){
    // code here    
    int i;
    printf("\nnames: ");
    for(i=0; strcmp(names[i], "\0") != 0;i++){
        printf("%s ", names[i]);
    }
    printf("\n");
}
