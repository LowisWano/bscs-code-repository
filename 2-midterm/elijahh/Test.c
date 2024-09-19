#include <stdio.h>
#include <stdlib.h>
#Define MAX 10

typedef struct{
	char fname[20];
	char mname[20];
	char lname[20];
}Name;

typedef struct{
	int year;
	char section[20];	
}YaS;

typedef enum{M,F} Gender;

typedef struct{
	int ID[8];
	Name Fullname;
	YaS YearSection;
	Gender Sex;
	int Age;
}StudentRecord;

typedef struct{
	StudentRecord Data;
	int link;
}Student;

typedef struct{
	Student Studlist[MAX];
	int avail;
}VirtualHeap;

// Virtual Heap Operations
void initVH(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int Pos);
void clean(VirtualHeap *VH);

//ADT Operations
void insertFirst(VirtualHeap *VH, List *L, char elem);
void insertLast(VirtualHeap *VH, List *L, char elem);
void insertSorted(VirtualHeap *VH, List *L, char elem);
void deleteFirstOcc(VirtualHeap *VH, List *L, char elem);
void deleteAllOcc(VirtualHeap *VH, List *L, char elem);

int main(){
	
}

void initVH(VirtualHeap *VH){
	int x;
	for(x = MAX; X>-1; x--){
		VH.Studlist[].link = x-1;
	}
}
