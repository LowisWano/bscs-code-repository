/* Instructions:
	The University of San Carlos has begun rolling out its newest locker technology: GraviLockers.
	These lockers are capable of fitting any amount of items, for as long as the total weight of all items
	does not exceed the weight limit of 5 KG. However, during shipping, the lockers' disk drives were damaged,
	and the firmware that made them work was lost. Luckily, the documentation for the structures remained intact.
	
	As students of DCIS, USC needs your help. Write the codes for the functions to make the lockers work again.
	Use the structures defined below.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLOCKERS 10
#define WEIGHTLIMIT 5

typedef struct{
	char studID[9];		
	char studName[65];  
	char course[5];		
}Student;

typedef struct{
	char itemName[33];	
	float weight;		/* Weight of the item to be stored */	
}ItemDets;

typedef struct ItemNode{
	ItemDets item;
	struct ItemNode* nextItem;
}ItemNode, *ItemList;

typedef struct{
	Student owner;			/* Details of the student who owns the locker */
	ItemList IL;			/* Linked list representation of all the items inside a certain locker */
	int lockerStat; 	 	/* 0 if locker is Vacant, 1 if occupied */
	float totWeight;		/* Total weight of all items in the locker */
}Locker;

typedef struct{
	Locker *lockers;
	int count;
	int max;
}Locklist;

void displayItemList(ItemList L);
ItemList getHeavyItems(Locker* L, float limit);
void depositItem(Locker* L, char studID[], ItemDets newItem);


Student* returnStudExceed(Locklist L, float limit, int *count){
	Student *badboys = malloc(sizeof(Student)*max);
	int i;
	for(i=0;i<L->count;i++){
		if(L.lockers[i].totWeight > limit && *count < L.max){
			badboys[*count++] = L.lockers[i].owner;
		}
	}
	return badboys;
}


int main(void)
{
	ItemDets item1 = {"Prog 1 Book", 0.35};
	ItemDets item2 = {"Shoes", 0.87};
	ItemDets item3 = {"Laptop", 2.35};
	ItemDets item4 = {"Keyboard", 1.17};
	ItemDets item5 = {"Discrete", 5.32};
	ItemDets item6 = {"Discrete", 2.22};
	

	
	Locker myLocker = {{"14101941", "Cris Militante", "BSCS"}, NULL, 1, 0};
	ItemList heavyItems = NULL;
	
	depositItem(&myLocker, "141011", item6);
	depositItem(&myLocker, "14101941", item5);
	depositItem(&myLocker, "14101941", item4);
	depositItem(&myLocker, "14101941", item2);
	depositItem(&myLocker, "14101941", item3);
	depositItem(&myLocker, "14101941", item1);
	displayItemList(myLocker.IL);
	
	heavyItems = getHeavyItems(&myLocker, 1.00);
	displayItemList(myLocker.IL);
	displayItemList(heavyItems);
	
	
	
	Locker locker1 = {{"23100371", "Luis Ouano", "BSCS"}, NULL, 1, 0};
	Locker locker2 = {{"23100372", "Paul Detablan", "BSCS"}, NULL, 1, 0};
	Locker locker3 = {{"23100000", "Elijah", "BSCS"}, NULL, 1, 0};
	Locker locker4 = {{"23100375", "Nash Ouano", "BSCS"}, NULL, 1, 0};
	
	Locklist L;
	L.count = 4;
	L.max = 10;
	
	L.lockers[0] = locker1;
	L.lockers[1] = locker2;
	L.lockers[2] = locker3;
	L.lockers[3] = locker4;
	
	
		depositItem(&L->lockers[0], "141011", item1);
		depositItem(&L->lockers[0], "14101941", item2);
		depositItem(&L->lockers[0], "14101941", item4);
		
	
		depositItem(&L->lockers[1], "141011", item3);
		depositItem(&L->lockers[1], "141011", item5);
		depositItem(&L->lockers[1], "14101941", item6);
		
		
		
		depositItem(&L->lockers[2], "141011", item1);
		depositItem(&L->lockers[2], "14101941", item2);
		depositItem(&L->lockers[2], "14101941", item4);
	
	
		depositItem(&L->lockers[3], "141011", item3);
		depositItem(&L->lockers[3], "141011", item5);
		depositItem(&L->lockers[3], "14101941", item6);


	
	int count=0;
	Student *badstudents;
	badstudents = returnStudExceed(L, 1.5, &count);
	
	int j;
	for(j=0;j<count;j++){
		printf("%s\n", badstudents[j].studName);
	}
	return 0;
}


/* Function depositItem(): This function will receive as parameter a Locker, a student ID, and an item to be
stored. The function will insert the item into the Locker's ItemList, which is sorted by weight. Heavier
items are stored at the end of the locker's ItemList. Before insertion, please make sure that the student ID
passed is the same as the student ID of the locker's owner. Also, make sure that the weight of all items,
including the new item to store, does not exceed the weight limit. */

void depositItem(Locker* L, char studID[], ItemDets newItem)
{
	/*
		check if ID passed is the same as owner ID
		check if weight limit has not exceeded
		
		insertSorted by weight (insert at pos)
		traverse until you find NULL or an item heavier than it
		
		
		kasagaran gyud ang flow sa mga problems ni sir gran is:
		1. check validation (e.g studID, weight can still be available, etc.)
		2. ADT list operation
		3. additional details to increment (e.g total weight, total salary, typa shi)
	*/
	ItemList *trav;
	ItemList temp=NULL;
	if(!strcmp(studID, L->owner.studID) && newItem.weight < WEIGHTLIMIT){
			for(trav=&L->IL; *trav != NULL && newItem.weight > (*trav)->item.weight;trav=&(*trav)->nextItem){}
			temp = malloc(sizeof(ItemNode));
			temp->item = newItem;
			
			// insert only takes two lines of code
			temp->nextItem = *trav;
			*trav = temp;
			L->totWeight+= newItem.weight;
	}
}

/* Function getHeavyItems(): This function will receive as parameter a Locker and a weight threshold/limit.
The function will go through all the items in the passed Locker's ItemList. If any item EXCEEDS the passed
threshold/limit, store that item into a new ItemList using insertFirst, and delete it from the locker's 
ItemList. Return the ItemList of deleted items to the calling function. */

ItemList getHeavyItems(Locker* L, float limit)
{
	/*
		traverse through LL
		check if item exceeds limit
		delete all occurence
		insertfirst to new list
	*/
	ItemList *trav;
	ItemList temp;
	ItemList heavy = NULL;
	// deleteAllOccurences
	for(trav=&L->IL;*trav!=NULL;){
		if((*trav)->item.weight > limit){
			// insert operation
			temp = *trav;
			
			// transfer item
			*trav = (*trav)->nextItem;
			
			temp->nextItem = heavy;
			heavy = temp;
		}else{
			trav=&(*trav)->nextItem;
		}
	}
	return heavy;
}

void displayItemList(ItemList L)
{
	ItemList trav;
	float totWeight =0;
	for(trav = L; trav != NULL; trav = trav->nextItem){
		totWeight+= trav->item.weight;
		printf("Item: %-15s | Weight: %-15.2f\n", trav->item.itemName, trav->item.weight);

	}
	printf("\nTotal Weight: %.2fkg\n\n", totWeight);
}
