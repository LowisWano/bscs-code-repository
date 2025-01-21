#include"header.h"

/**
 * PROBLEM 1: Get all the voters living in the specified city and store it to a StackLList to be returned
 */
StackLList getVoters(Personlist vlist, String city){
  // code here
  StackLList S = NULL, temp;
  int i;
  for(i=0;i<vlist.count;i++){
      if(strcmp(vlist.list[i].add.city, city)==0){
          temp = malloc(sizeof(NodeType));
          temp->p = vlist.list[i];
          temp->link = S;
          S = temp;
      }
  }
  return S;
}

/**
 * PROBLEM 2: Get the names of all voters with IDs 1 to 10 that are residing in a specified city and store it in an array of strings to be returned
 * Add a sentinel using an empty string
 */
String* getNames(PersonOpenDict d, String city){
   // code here
   /*
        Given an open dictionary,
        use hash(id) to get its location 
        since it is an open dictionary, traverse thru the list and check if conditions are met.
        if met, insert to array of strings
   */
   String *names = malloc(sizeof(String)*10);
   int n = 0, i;
   for(i=0;i<=10;i++){
       int h = hash(i);\
       NodePtr trav;
       for(trav=d.list[h];trav!=NULL; trav=trav->link){
           if(trav->p.id == i && strcmp(trav->p.add.city, city) == 0){
            //   printf("id: %d - hash:%d\n",i, h);
               strcpy(names[n++], trav->p.name);
           }
       }
   }
   return names;
}   

/**
 * PROBLEM 3: Get all unique voters in StackLList and store it to a QueuePersonList
 */
void getAllUniqueVoters(StackLList S, QueuePersonList *Q){
    /*
        move stack to tempStack
        insertLastUnique top to open dictionary
        if successfull, it is unique, therefore enqueue
        return tempstack to orig stack
    */
    StackLList tempStack = NULL, holder;
    NodePtr *trav, tempQ;
    PersonOpenDict OD;
    initializeOpenDict(&OD);
    
    while(S!=NULL){
        // insert to dictionary
        int h = hash(S->p.id);
        for(trav=&(OD.list[h]); *trav!=NULL && (*trav)->p.id != S->p.id; trav=&(*trav)->link){}    
        if(*trav==NULL){
            // insertLast
            *trav = malloc(sizeof(NodeType));
            (*trav)->p = S->p;
            (*trav)->link = NULL;
            
            // enqueue
            tempQ = malloc(sizeof(NodeType));
            tempQ->p = S->p;
            tempQ->link = NULL;
            
            if(Q->head == NULL){
                Q->head = tempQ;           
            }else{
                Q->tail->link = tempQ;
            }
            Q->tail = tempQ;
        }
        
        // move stack
        holder = tempStack;
        tempStack = S;
        S = S->link;
        tempStack->link = holder;
    }
    
    while(tempStack!=NULL){
        holder = S;
        S = tempStack;
        tempStack = tempStack->link;
        S->link = holder;
    }
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
        }else{
            tempQ.tail->link = holder;
        }
        tempQ.tail = holder;
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
        {8, "Joshue", {"NewYork", 10001}},          // Duplicate of John
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
