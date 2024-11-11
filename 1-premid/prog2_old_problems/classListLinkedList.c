#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];
    int id;
    char course[8];
    int yearlvl;
    int examScore;
}Stud;

typedef struct node{
    Stud studrec;
    struct node* link;
}*LIST, List;

Stud createStud(char *name, int id, char *course, int yearlvl, int examScore);
void display(LIST head);
void insertLast(LIST* head, Stud new);
void insertFirst(LIST* head, Stud new);
void insertPos(LIST* head, Stud new, int pos);
void sortListAscending(LIST head);
void sortListDescending(LIST head);
void deleteStudrec(LIST* head, int id);
void deleteAtPos(LIST* head, int pos);
void deleteCourse(LIST* head, char *course);
void deleteAll(LIST* head);

int main(void){
    LIST head;
    head = NULL;
    insertLast(&head, createStud("Paul", 111111, "BSCS", 1, 60));
    insertLast(&head, createStud("Arevalo", 222222, "BSCS", 1, 60));
    insertLast(&head, createStud("Cimafranca", 333333, "BSIS", 1, 69));
    insertLast(&head, createStud("Alec", 444444, "BSCS", 1, 99));
    insertFirst(&head, createStud("Glenn", 666666, "BSIT", 3, 12));
    insertPos(&head, createStud("Gran", 555555, "BSIT", 4, 10), 2);

    printf("Before sorting: \n");
    display(head);
    printf("\nAfter sorting A-Z: \n");
    sortListAscending(head);
    display(head);

    printf("\nAfter sorting Z-A: \n");
    sortListDescending(head);
    display(head);

    printf("After deleting Paul\n");
    deleteStudrec(&head, 111111);
    display(head);

    printf("After deleting 3rd position: \n");
    deleteAtPos(&head, 2);
    display(head);

    printf("After deleting all IT courses: \n");
    deleteCourse(&head, "BSIT");
    display(head);

    deleteAll(&head);
    display(head);
}

void deleteAll(LIST* head){
    while(*head!=NULL){
        LIST temp = *head;
        *head=(*head)->link;
        free(temp);
    }
}

void deleteCourse(LIST* head, char *course){
    LIST *trav;
    for(trav=head;*trav!=NULL;){
        if(strcmp((*trav)->studrec.course, course) == 0){
            LIST temp = *trav;
            *trav=(*trav)->link;
            free(temp);
        }else{
            trav=&(*trav)->link;
        }
    }
}

void deleteAtPos(LIST* head, int pos){
    int count=0;
    LIST* trav;
    for(trav=head; *trav!=NULL && count != pos;trav=&(*trav)->link, count++){}

    if(*trav!=NULL){
        LIST temp = *trav;
        *trav=(*trav)->link;
        free(temp);
    }else{
        printf("This position does not exist. ");
    }
}

void deleteStudrec(LIST* head, int id){
    LIST* trav;
    for(trav=head;*trav!=NULL && (*trav)->studrec.id != id;trav=&(*trav)->link){}
    if(*trav != NULL){
        LIST temp = *trav;
        *trav=(*trav)->link;
        free(temp);
    }else{
        printf("A student with an id of %d does not exist.", id);
    }
}

void sortListDescending(LIST head){
    LIST i,j, max;
    Stud temp;
    for(i=head;i!=NULL;i=i->link){
        // set i as the max first
        max = i;

        // this block of code's purpose is to find the biggest after i
        for(j=i->link;j!=NULL;j=j->link){
            if(strcmp(j->studrec.name, max->studrec.name) > 0){
                max = j;
            }
        }

        // swap after finding the biggest
        temp = max->studrec;
        max->studrec = i->studrec;
        i->studrec = temp;
    }
}

void sortListAscending(LIST head){
    // we finna do selection sort
    LIST i, j, min;
    Stud temp;
    int curr = 0; 
    for(i=head;i!=NULL;i=i->link, curr++){
        min = i;
        for(j=i->link;j!=NULL;j=j->link){
            if(strcmp(j->studrec.name, min->studrec.name) < 0){
                min = j;
            }
        }
        temp = min->studrec;
        min->studrec = i->studrec;
        i->studrec = temp;
    }
}

void insertPos(LIST* head, Stud new, int pos){
    LIST *curr; 
    int currPos = 0;
    for(curr=head;*curr!=NULL && currPos != pos;curr=&(*curr)->link, currPos++){}
    LIST temp = malloc(sizeof(struct node));
    temp->studrec = new;
    temp->link = *curr;
    *curr = temp;
}

void insertFirst(LIST* head, Stud new){
    LIST temp = malloc(sizeof(struct node));
    temp->studrec = new;
    temp->link = *head;
    *head = temp;
}

void insertLast(LIST* head, Stud new){
    LIST *curr;
    for(curr=head;*curr!=NULL;curr=&(*curr)->link){}
    *curr = malloc(sizeof(struct node));
    (*curr)->studrec = new;
    (*curr)->link = NULL;
}

void display(LIST head){
    printf("===STUDENT LIST===\n");
    if(head!=NULL){
        for(; head != NULL; head=head->link){
            printf("Name: %s\n", head->studrec.name);
            // printf("ID: %d\n", head->studrec.id);
            printf("Course: %s\n", head->studrec.course);
            // printf("Year: %d\n", head->studrec.yearlvl);
            // printf("Score: %d\n", head->studrec.examScore);
            printf("\n");
        }    
    }else{
        printf("There are no students in the class.");
    }
    
}

Stud createStud(char *name, int id, char *course, int yearlvl, int examScore){
    Stud new;
    strcpy(new.name, name);
    new.id = id;
    strcpy(new.course, course);
    new.yearlvl = yearlvl;
    new.examScore = examScore;
    return new;
}
