#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMPROGRAMS 4
#define YEARLEVELS 4
#define MAXSTUDS 100

/**
 * Concepts tackled in this problem:
 * 1. computer word (using unsigned char personalInfo to gather data about a student)
 * 2. array list of students (arrListStud)
 * 3. linked list of students (studLL)
 * 4. open dictionary of student linked lists (dcismNode): categorized by year (0-year1, 1-year2, 2-year3, 3-year4)
 * 5. closed dictionary of open dictionaries (dcismDict): categorized by program (0-CS, 1-IT, 2-IS, 3-MATH)
 * 6. array representation of SETs of studs (studSet)
 */

typedef struct{
    char fName[64];
    char mi;
    char lName[32];
}studName;

typedef unsigned char personalInfo;
/*Given 8 bits: 0000 0000
 
 Bits
 8    = Status:            0 - Inactive, 1 - Active
 7    = Nationality:       0 - Filipino, 1 - Foreigner
 6    = Enrollment Status: 0 - Regular, 1 - Irregular
 5    = Gender:            0 - Male, 1 - Female
 3-4  = Year Level:        00 - 1st, 01 - 2nd, 10 - 3rd, 11 - 4th
 1-2  = Program:           00 - CS, 01 - IT, 10 - IS, 11 - MATH
 
 For example:
 1001 1001 would represent an Active Regular 3rd Year Filipino Female IT Student
*/
// ========= FOR DATA =============
typedef struct{
    char idNum[9];
    studName name;
    personalInfo info;
}student;

typedef struct{
    student studs[MAXSTUDS];
    int numStuds;
}arrListStud;

// ========= DICTIONARY ===========
typedef struct studNode{
    student stud;
    struct studNode* next;
}studNode, *studLL;

typedef studLL studDict[YEARLEVELS];

typedef struct{
    studDict programStuds;
    int studCtr;               /* refers to the total number of students in the PROGRAM. */
}dcismNode;

typedef dcismNode dcismDict[NUMPROGRAMS];

// ================ SETS array ==============================
typedef struct{
    char studID[9];
    studName sName;
    personalInfo info;
}studRec;

typedef struct{
    studRec studs[MAXSTUDS];
    int count;
}sNode, *studSet;               /* array representation of a Set of studRecs */

char* getProgram(personalInfo);
arrListStud populateStudentList(void);
void displayArrListStud(arrListStud);
int programHash(personalInfo);
int yearLevelHash(personalInfo);
int insertStudLL(studLL*, student);
void displayStudLL(studLL);
void initDCISMDict(dcismDict);
void convertToDCISMDict(dcismDict, arrListStud);
void displayDCISMDict(dcismDict);

studSet* initStudSet(void);
void insertStudSet(studSet, studRec);
studSet* removeInactiveStudents(dcismDict);
void displayStudSets(studSet*);

int main(void)
{
  /* Problem 1
      1) Declare a variable SL of type arrListStud and call populateStudentList() to populate it
      2) Call displayArrListStud()
    */  
  arrListStud SL = populateStudentList();
  displayArrListStud(SL);

  /* Problem 2
      1) Declare a variable D of type dcismDict
      2) Call initDCISMDict()
      3) Call convertToDCISMDict()
      4) Call displayDCISMDict()
    */
  dcismDict D;
  initDCISMDict(D);
  convertToDCISMDict(D, SL);
  displayDCISMDict(D);
  
  /* Problem 3
      1) Declare a variable inactive of type studSet* and call removeInactiveStudents() to populate it
      2) Call displayDCISMDict()
      3) Call displayStudSets()
    */
  studSet *inactive = removeInactiveStudents(D);
  printf("========================AFTER DELETING INACTIVE STUDENTS==================\n");;
  displayDCISMDict(D);
  displayStudSets(inactive);
  return 0;
}

/*
 Write the code for the function getProgram().
 
 The function will return the string equivalent of the program of the provided personalInfo.
 For example: personalInfo = 1001 1001 will return the string BSIT because the last 2 bits are 01. Refer to the definition of personalInfo to know which bit pattern represent each program.
 */
char* getProgram(personalInfo I)
{
  // when declaring a pointer, you should allocate memory for it. If you attempt to strcpy, to a char pointer that is not pointing to anything, it will raise a segfault.
  char *program = malloc(sizeof(char)*7);
  int val = I & 3;
  if(val == 0){
    strcpy(program, "BSCS");
  }else if(val == 1){ 
    strcpy(program, "BSIT");
  }else if(val == 2){ 
    strcpy(program, "BSIS");
  }else if(val == 3){ 
    strcpy(program, "BSMATH");
  }
  return program;
}

/*
 Code for this function has been partially provided.
 Write the code for the function populatesetList().
 The function will read a file containing student records and return the student records to the calling function in the form of an arrListStud.
 */
arrListStud populateStudentList(void)
{
  FILE* fp;
  student* studs;
  int dataCount;
  arrListStud SL = {{}, 0};
  
  if((fp = fopen("students.bin", "rb"))== NULL){
    puts("Unsuccessful in opening students.txt");
  }else{
    fseek(fp, 0, 2);
    dataCount = (int) ftell(fp) / sizeof(student);
    studs = (student*) malloc (sizeof(student) * dataCount);
    if(studs != NULL){
        fseek(fp, 0, 0);
        fread(studs, sizeof(student), dataCount, fp);
    }
    /* In this section, insert all the studs into an setList to be returned. */
    int i;
    int x;
    for (x = 0; x < MAXSTUDS && x < dataCount; ++x) {
      SL.studs[x] = studs[x];
      SL.numStuds++;
    }
    fclose (fp);
  }
  return SL;
}
/*
 Write the code for the function displayArrListStud().
 This function will display the ID number, First Name, and Last name of the student records inside the arrListStud.
 */
void displayArrListStud(arrListStud A)
{
    printf("Student Data from the file\n");
    printf("%-10s", "Id Number");
    printf("%-10s", "fName");
    printf("%-10s\n", "lName");
    
    int i;
    for(i=0;i<A.numStuds; i++){
        printf("%-10s%-10s%-10s\n", A.studs[i].idNum, A.studs[i].name.fName, A.studs[i].name.lName);
    }
}


/*
 Write the code for the function programHash().
 Given a personalInfo variable, the function will return the integer equivalent of the bits that represent a student's program.
 */
int programHash(personalInfo I)
{
  // you have to modulo with max apparently, try to ask what is the reason since there's no way double digit binary exceeds 3
  return I & 3;
}

/*
 Write the code for the function yearLevelHash().
 Given a personalInfo variable, the function will return the integer equivalent of the bits that represent a student's year level.
 */
int yearLevelHash(personalInfo I)
{
  return (I & 12) >> 2; 
}

/*
 Write the code for the function insertStudentLL().
 Given a pointer to a studLL and a student to insert, the function will insert into the sorted studSet based on the student's ID number. All elements in the studLL should be unique. The function will return 1 if the insert was successful and 0 if not.
 */
int insertStudLL(studLL* SL, student S)
{ 
  studLL *trav, temp;
  for(trav = SL; *trav!=NULL && S.idNum >= (*trav)->stud.idNum; trav=&(*trav)->next){
    if(S.idNum == (*trav)->stud.idNum){
      return 0;
    }
  }
  temp = malloc(sizeof(studNode));
  temp->stud = S;
  temp->next = *trav;
  *trav = temp;
  return 1;
}

/*
 Code for this function has been partially provided.
 Write the code for the function displayStudLL().
 The function will display the contents of a given studLL.
 */
void displayStudLL(studLL SL){
    if(SL!=NULL){
        printf("\nYear %d\n\n", yearLevelHash(SL->stud.info)+1);
        printf("%-10s", "Id Number");
        printf("%-10s", "fName");
        printf("%-10s", "lName");
        printf("%-10s", "Program");
        printf("%-10s", "Year");
        printf("%-10s", "Gender");
        printf("%-15s", "Enrollment");
        printf("%-15s", "Nationality");
        printf("%-10s\n", "Status");
        for(; SL!=NULL; SL=SL->next){
          printf("%-10s", SL->stud.idNum);
          printf("%-10s", SL->stud.name.fName);
          printf("%-10s", SL->stud.name.lName);
          printf("%-10s", getProgram(SL->stud.info));
          printf("%-10d",  yearLevelHash(SL->stud.info)+1);
          printf("%-10s",  (SL->stud.info & 16)?"Female":"Male");
          printf("%-15s",  (SL->stud.info & 32)?"Irregular":"Regular");
          printf("%-15s",  (SL->stud.info & 64)?"Foreigner":"Filipino");
          printf("%-15s\n",  (SL->stud.info & 128)?"Active":"Inactive");
        }
    }
}

/*
 Write the code for the function initDCISMDict().
 The function will receive a dcismDict, and initialize it to be empty.
 */
void initDCISMDict(dcismDict D){
  int i,j;
  studLL trav;
  for(i=0; i<NUMPROGRAMS; i++){
    for(j=0;j<YEARLEVELS; j++){
      D[i].programStuds[j] = NULL;
    }
    
    D[i].studCtr = 0;
  }
}

/*
 Write the code for the function convertToDCISMDict().
 The function will receive a dcismDict and an arrListStud. The function will go through list of students and insert them to their proper place in the dcismDict.
 */
void convertToDCISMDict(dcismDict D, arrListStud SL)
{
  /*
      PLAN:
      1. use programHash to get the hash index on where to access from dcismDict
      2. use yearHash to get the hash index on where to access from dcismNode
      3. insert sorted by ID

      for every student
   */
  int i, program, year;
  for(i=0; i<SL.numStuds; i++){
    program = programHash(SL.studs[i].info);
    year = yearLevelHash(SL.studs[i].info);
    if(insertStudLL(&(D[program].programStuds[year]), SL.studs[i]) == 1){
      D[program].studCtr++;
    }
  }
}

/*
 Code for this function has been partially provided.
 Write the code for the function displayDCISMDict().
 The function will receive a dcismDict. The function will display all the students in the dcismDict by program and year level.
 */
void displayDCISMDict(dcismDict D){
    int i, j;
    for(i=0; i<NUMPROGRAMS; i++){
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
        // Check if there is at least one student in the first year to avoid dereferencing NULL
        if (D[i].programStuds[0] != NULL) {
            printf("%s %d Students\n", getProgram(D[i].programStuds[0]->stud.info), D[i].studCtr);
        } else {
            printf("No students for this program.\n");
        }
        for(j=0; j<YEARLEVELS; j++){
      
                displayStudLL(D[i].programStuds[j]);

        }
    }
}


/*
 Write the code for the function initStudSet().
 The function will initialize an empty array of studSets that can accommodate the total number of programs.

 typedef struct{
    char studID[9];
    studName sName;
}studRec;

typedef struct{
    studRec studs[MAXSTUDS];
    int count;
}sNode, *studSet;      

 */
studSet* initStudSet(void) {
    //Write your code here
    studSet *setPtr = (studSet *) malloc (sizeof (studSet) * NUMPROGRAMS);  //arrayy of studSet or pointers to a structure
    if (setPtr != NULL) {
        int x;
        for (x = 0; x < NUMPROGRAMS; ++x) {
            setPtr[x] = (studSet) malloc (sizeof (sNode));
            if (setPtr[x] != NULL) {
                setPtr[x]->count = 0;
            }
        }
    }
    return setPtr;
}


//-----------------------------------------------------------------------------------------
// insertStudSet(). The function will insert the studRec into the studSet. Student will be inserted at the end of the set.
//-----------------------------------------------------------------------------------------
void insertStudSet(studSet S, studRec sRecord) {
    //Write your code here
    if (S->count < MAXSTUDS) {
        S->studs[S->count++] = sRecord;
    }
}


//-----------------------------------------------------------------------------------------
// removeInactiveStudents(). The function will delete all student records that have the status "inactive".
// Deleted records will be stored in an array of studSets, such that each deleted student will be stored
// in its proper index in the array of studSets based on their program. Return the array of studSets to the calling function.
//-----------------------------------------------------------------------------------------
studSet * removeInactiveStudents(dcismDict D) {
    //Write your code here
    studSet *lSet = initStudSet(); 
    if (lSet != NULL) {
        int x, n;
        for (x = 0; x < NUMPROGRAMS; ++x) {         
            for (n = 0; n < YEARLEVELS; ++n) {      
                studLL *trav, temp;
                
                for (trav = &(D[x].programStuds[n]); *trav != NULL;) {
                    personalInfo mask = 1 << (sizeof (personalInfo) * 8)-1;
                    if ((*trav)->stud.info & mask) {
                        trav = &(*trav)->next;
                    } else {
                        temp = *trav;
                        *trav = temp->next;
                        
                        studRec SR;
                        strcpy (SR.studID, temp->stud.idNum);
                        SR.sName = temp->stud.name;
                        SR.info = temp->stud.info;
                        
                        insertStudSet (lSet[x], SR);
                        (D[x].studCtr)--;
                        free(temp);
                    }
                }
            }
        }
    }
    return lSet;
}

 
 
/**********************************************************************************
 *  Displays the ID, Firstname and Lastname of inactive students for each program. *
 **********************************************************************************/
void displayStudSets(studSet S[]) {
    //Write your code 
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("\nInactive Students\n");
    printf("%-13s", "IDNumber");
    printf("%-13s", "FName");
    printf("%-13s", "LName");
    printf("%-13s\n", "Status");
    int x, n;
    for (x = 0; x < NUMPROGRAMS; ++x) {
        printf("\n[%d]", x);
        for (n = 0; n < S[x]->count; ++n) {
            printf("\n%-13s", S[x]->studs[n].studID);
            printf("%-13s", S[x]->studs[n].sName.fName);
            printf("%-13s", S[x]->studs[n].sName.lName);
            printf("%-13s", (S[x]->studs[n].info & 1 << (sizeof (personalInfo) * 8) - 1)? "Active": "Inactive");
        }
        printf("\nCount: %d\n", S[x]->count);
    }   
}