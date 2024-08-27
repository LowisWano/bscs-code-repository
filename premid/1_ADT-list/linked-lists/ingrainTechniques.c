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
	Student owner;			
	ItemList IL;			
	int lockerStat; 	 	
	float totWeight;		
}Locker;

void displayItemList(ItemList L);
void depositItemInsertFirstConnect(Locker* L, char studID[], ItemDets newItem);
void depositItemInsertLastTrav(Locker* L, char studID[], ItemDets newItem);
void depositItemInsertLastRemember(Locker* L, char studID[], ItemDets newItem, ItemList *lastNode);
void depositItemInsertSorted(Locker* L, char studID[], ItemDets newItem);
ItemList getHeavyItemsInsertFirst(Locker* L, float limit);
ItemList getHeavyItemsInsertLast(Locker* L, float limit);
ItemList getHeavyItemsInsertSorted(Locker* L, float limit);
void deleteItem(Locker* L, char studID[], char name[]);


int main(void)
{
	ItemDets item1 = {"Prog 1 Book", 0.35};
	ItemDets item2 = {"Shoes", 0.87};
	ItemDets item3 = {"Laptop", 2.35};
	ItemDets item4 = {"Keyboard", 1.17};
	ItemDets item5 = {"Discrete", 5.32};
	ItemDets item6 = {"Discrete", 2.22};

	
	Locker myLocker = {{"14101941", "Cris Militante", "BSCS"}, NULL, 1, 0};
	ItemList heavyItems;
    
	ItemList rem = myLocker.IL;
	depositItemInsertFirstConnect(&myLocker, "141011", item6);
	depositItemInsertFirstConnect(&myLocker, "14101941", item5);
	depositItemInsertFirstConnect(&myLocker, "14101941", item4);
	depositItemInsertFirstConnect(&myLocker, "14101941", item2);
	depositItemInsertFirstConnect(&myLocker, "14101941", item3);
	depositItemInsertFirstConnect(&myLocker, "14101941", item1);
    deleteItem(&myLocker, "14101941", "Laptop");
	displayItemList(myLocker.IL);
	
	// heavyItems = getHeavyItemsInsertLast(&myLocker, 1.00);
	// displayItemList(myLocker.IL);
	// displayItemList(heavyItems);
	return 0;
}

// //delete single item
void deleteItem(Locker* L, char studID[], char name[]){
    ItemList *trav;
    ItemList temp;
    for(trav=&L->IL;*trav!=NULL && strcmp(name,(*trav)->item.itemName)!=0 ;trav=&(*trav)->nextItem){}
    temp = *trav;
    *trav = (*trav)->nextItem;
    free(temp);
}

// deleteAllOccurences and InsertLast, return new array
ItemList getHeavyItemsInsertLast(Locker* L, float limit){
    // deleteAllOccurences of item weight exceeding limit
    // insertLast to heavy list
    ItemList heavy = NULL, temp;
    ItemList *trav, *curr;
    for(trav=&L->IL;*trav!=NULL;){
        if((*trav)->item.weight > limit){
            temp = *trav;
            *trav = (*trav)->nextItem;

            for(curr=&heavy;*curr!=NULL;curr=&(*curr)->nextItem){}
            *curr = temp;
            temp->nextItem = NULL;
        }else{
            trav=&(*trav)->nextItem;
        }
    }
    
    return heavy;
}

// // deleteAllOccurences and InsertSorted, return new array
ItemList getHeavyItemsInsertSorted(Locker* L, float limit){
    ItemList *trav, *travH;
    ItemList heavy=NULL, temp;
    
    for(trav=&L->IL;*trav!=NULL;){
        if((*trav)->item.weight > limit){
            // remove from LL
            temp = *trav;
            *trav = (*trav)->nextItem;
            // traverse while temp is bigger, then insert when found heavy bigger implementation
            for(travH=&heavy;*travH!=NULL && temp->item.weight > (*travH)->item.weight; travH=&(*travH)->nextItem){}
            temp->nextItem = *travH;
            *travH = temp;
        }else{
            trav=&(*trav)->nextItem;
        }
    }
    return heavy;
}

// // deleteAllOccurences and InsertFirst, return new array
ItemList getHeavyItemsInsertFirst(Locker* L, float limit){
    
    ItemList heavy = NULL;
    ItemList temp;
    ItemList *trav;
    for(trav=&L->IL;*trav!=NULL;){
        if((*trav)->item.weight > limit){
            temp = *trav;
            *trav= (*trav)->nextItem;

            temp->nextItem = heavy;
            heavy = temp;
        }else{
            trav=&(*trav)->nextItem;
        }   
    }
    return heavy;
}

// do this again later to ingrain it in your mind
void depositItemInsertLastRemember(Locker* L, char studID[], ItemDets newItem, ItemList *lastNode){
    // create new item
    ItemList temp = malloc(sizeof(ItemNode));
    temp->item = newItem;
    temp->nextItem = NULL;

    if(*lastNode != NULL){
        (*lastNode)->nextItem = temp;
    }else{
        L->IL = temp;
    }
    *lastNode = temp;
}

//insertSorted
void depositItemInsertSorted(Locker* L, char studID[], ItemDets newItem){
    ItemList *trav;
    ItemList temp;
    for(trav=&L->IL;*trav !=NULL && newItem.weight > (*trav)->item.weight;trav=&(*trav)->nextItem){}
    temp = malloc(sizeof(ItemNode));
    
    temp->item = newItem;
    temp->nextItem = *trav;
    
    *trav = temp;
}
    
// insertFirst
void depositItemInsertFirstConnect(Locker* L, char studID[], ItemDets newItem){
    ItemList temp = malloc(sizeof(ItemNode));
    temp->item = newItem;
    temp->nextItem = L->IL;
    L->IL = temp;
}

void depositItemInsertLastTrav(Locker* L, char studID[], ItemDets newItem){
    ItemList *trav;
    for(trav=&L->IL; *trav!=NULL;trav=&(*trav)->nextItem){}
    *trav = malloc(sizeof(ItemNode));
    (*trav)->item = newItem;
    (*trav)->nextItem = NULL;
}




void displayItemList(ItemList L){
	ItemList trav;
	float totWeight = 0;
    
	for(trav = L; trav != NULL; trav = trav->nextItem){
        totWeight+=trav->item.weight;
		printf("Item: %-15s | Weight: %-15.2f\n", trav->item.itemName, trav->item.weight);

	}
	printf("\nTotal Weight: %.2fkg\n\n", totWeight);
}

