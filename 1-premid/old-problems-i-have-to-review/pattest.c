#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8
 
typedef struct{
	char fName[50];
	char lName[50];
}name;
 
typedef struct{
	char subjectName[50];
	int grade;
}subjectGrade;
 
typedef struct{
	int idNum;
	name studentName;
	char course[10];
	subjectGrade studentGrade[3];
}studentInfo;
 
typedef struct{
	studentInfo studentList[MAX];
	int count;
}classRecord;
 
typedef struct{
	classRecord classList;// Populate the initial array into this structure member
	classRecord passersList;// Populate this array based on the data in classList that have an average grade greater than or equal to 80
}teacherRecord;
 
 
studentInfo addNewStudent(char [],char[],char[],int,char[],int,char[],int,char[],int);
void addFront(classRecord *classList, studentInfo stud);
void populateRecord(classRecord *);
// void getPassers(classRecord classList);

//Create a function to transfer students from classList who have a grade of 80 or higher to the new passersList structure
//Implement a function Insert Into, Insert Sorted, Delete Front, Delete Last,Delete Item
//Implement a function Update, and ask user to update the grades only.
//Implement a function to find the details of a student with a specific ID Number
 
int main(){
    int size, i;
    teacherRecord rec;
  
    // printf("Input number of students: ");
    // scanf("%d", &size);

    
    rec.classList.count = 0;
    rec.passersList.count = 0;

    
    rec.classList.studentList[0] = addNewStudent("Luis","Ouano", "BSCS", 23100371, "prog2", 99, "networking", 99, "discrete", 99);
    rec.classList.studentList[1] = addNewStudent("Kiyotaka","Ayanokoji", "BSCS", 23100987, "prog2", 99, "networking", 99, "discrete", 99);
    rec.classList.studentList[2] = addNewStudent("Suzune","Horikita", "BSCS", 23100891, "prog2", 99, "networking", 99, "discrete", 99);
    rec.classList.studentList[3] = addNewStudent("Kei","Karuizawa", "BSCS", 23100543, "prog2", 99, "networking", 99, "discrete", 99);
    rec.classList.studentList[4] = addNewStudent("Yosuke","Hirata", "BSCS", 23100735, "prog2", 99, "networking", 99, "discrete", 99);
    rec.classList.count = 5;

    
    
    // display names
    for(i=0;i<rec.classList.count;i++){
        printf("%s ", rec.classList.studentList[i].studentName.fName);
    }
    
}


 
void addFront(classRecord *record, studentInfo stud){
    /*Code to addFront*/
    int i;
    if(record->count <= 7){  
        for(i=record->count-1;i>=0;i--){
            record->studentList[i+1] = record->studentList[i];
        }
        record->studentList[0] = stud;
        record->count++;
    }else{
        printf("Maximum students is 7");
    }
    
}
 
studentInfo addNewStudent(char fName[],char lName[],char courseName[],int idNum,char sub1[],int sub1Grade,char sub2[],int sub2Grade,char sub3[],int sub3Grade){
 
	studentInfo newStudent;
 
	newStudent.idNum=idNum;
	strcpy(newStudent.studentName.fName,fName);
	strcpy(newStudent.studentName.lName,lName);
	strcpy(newStudent.course,courseName);
 
	strcpy(newStudent.studentGrade[0].subjectName,sub1);
	newStudent.studentGrade[0].grade=sub1Grade;
 
	strcpy(newStudent.studentGrade[1].subjectName,sub2);
	newStudent.studentGrade[1].grade=sub2Grade;
 
	strcpy(newStudent.studentGrade[2].subjectName,sub3);
	newStudent.studentGrade[2].grade=sub3Grade;
 
	return newStudent;
}
 
 
