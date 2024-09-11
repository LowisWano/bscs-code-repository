#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

typedef char String[30];

typedef struct{
    String LName;
    String FName;
    char MI;
}NameType;

typedef struct{
    NameType name;
    int ID;
    String course;
    int year;
}Studtype;

typedef struct{
    Studtype stud[MAX];
    int count;
}StudList;

StudList populateList();
void displayList(StudList list);
Studtype createStudent(String LName, String FName, char MI, int id, String course, int year);
void insertAtPos(StudList *L, Studtype newStud, int pos);

Studtype deleteElem(StudList *L, int id);
int deleteAllCourse(StudList *L, String crs);

int deleteAllCourse(StudList *L, String crs){
    int i, count=0;
    Studtype delStud;
    for(i=0;i<L->count;){
        if(strcmp(L->stud[i].course, crs) == 0){
            delStud = deleteElem(L, L->stud[i].ID);
            count++;
        }else{
            i++;
        }
    }
    return count;    
}

int main(void){
    int delCount;
    StudList L;
    L = populateList();
    Studtype delStud;
    displayList(L);
    Studtype newStud = createStudent("Ayanokoji", "Kiyotaka", 'K', 23100999, "BSIT", 1);
    insertAtPos(&L, newStud, 3);
    printf("\n --------------- \n");
    displayList(L);
    printf("\n --------------- \n");
    delStud = deleteElem(&L, 23100987);
    displayList(L);
    printf("\n --------------- \n");
    delCount = deleteAllCourse(&L, "BSIT");
    printf("Number of ppl you just deleted: %d\n", delCount);
    displayList(L);
    return 0;
}

Studtype deleteElem(StudList *L, int id){
    int i,j;
    Studtype delStud;
    for(i=0;i<L->count && L->stud[i].ID != id;i++){}
    delStud = L->stud[i];
    for(;i<L->count;i++){
        L->stud[i] = L->stud[i+1];
    }
    L->count--;
    return delStud;
}


void insertAtPos(StudList *L, Studtype newStud, int pos){
    int i,j;
    if(L->count < MAX){
        for(i=0;i<L->count && i != pos;i++){}
        for(j=L->count;j>=i;j--){
            L->stud[j+1] = L->stud[j];
        }
        L->stud[pos] = newStud;
        L->count++;    
    }else{
        printf("List is full.\n");
    }
    
}


Studtype createStudent(String lname, String fname, char mi, int id, String course, int yr){
    Studtype stud;
    
    strcpy(stud.name.LName, lname);
    strcpy(stud.name.FName, fname);
    stud.name.MI = mi;
    stud.ID = id;
    strcpy(stud.course, course);
    stud.year = yr;
    return stud;
}

StudList populateList(){
    StudList list;
    list.count = 0;
    
    
    list.stud[list.count++] = createStudent("Ouano", "Luis", 'E',23100371, "BSCS", 1);
    list.stud[list.count++] = createStudent("Detablan", "Paul France", 'M',23100891, "BSIT", 1);
    list.stud[list.count++] = createStudent("Arevalo", "Timothy", 'A',23100987, "BSCS", 1);
    
    return list;
}

void displayList(StudList list){
    int i;
    for(i=0;i<list.count;i++){
        printf("ID: %d\n", list.stud[i].ID);
        printf("Name: %s\n",list.stud[i].name.FName);
        printf("Course: %s", list.stud[i].course);
        printf("\n");
    }
}
