#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int thousands;
    int fivehundreds;
    int onehundreds;
}Bill;

typedef struct{
    int id;
    char brand[20];
    char location[20];
    Bill bills;
    int balance;
}Bank;

typedef struct{
    int id;
    char fname[20];
    int balance;
}User;

typedef struct{
    int count;
    int max;
    Bank name;
    User *user;
}BankList;

typedef struct node{
    BankList bank;
    struct node *next;
}Node;

//ACT
bool withdraw(Node *x, int userId, int withdraw);
bool transferUser(Node *x, int userId, int bankID);
bool sendMoney(Node *x, int userIdFrom, int userIdTo, int transferMoney);
//ACT

void displayUser(Node *x);
bool registerUser(Node *x, int id, User user);
User inputuser(int id, char name[], int balance);
void displaybank(Node *x);
void populateNode(Node **x, BankList bank);
BankList populateBank(Bank name);
Bank bankname(int id, char brand[], char location[], int bal);
    
int main(){
    Node *x = NULL;
    /*
    	we are given:
		a linkedlist of arrays, a linked list of banks with an array of users
    
    */
	// populate bank LL
    populateNode(&x,populateBank(bankname(101,"MetroBank","Mandaue",50000)));
    populateNode(&x,populateBank(bankname(105,"ChinaBank","Banilad",40000)));
    populateNode(&x,populateBank(bankname(106,"LandBank","Cebu",60000)));
    populateNode(&x,populateBank(bankname(205,"BdoBANK","Consolacion",30000)));

	// register user to respective banks
    registerUser(x,101, inputuser(123,"Kenny", 5000));
    registerUser(x,101, inputuser(124,"Kentward", 4000));
    registerUser(x,101, inputuser(125,"Marlou", 12000));
    registerUser(x,105, inputuser(126,"Marlon", 3000));
    registerUser(x,105, inputuser(127,"Ermac", 9700));
    registerUser(x,106, inputuser(128,"Joe", 15000));
    registerUser(x,106, inputuser(129,"Harry", 7500));
    registerUser(x,106, inputuser(130,"Luke", 1000));
    registerUser(x,106, inputuser(131,"John", 25000));
    registerUser(x,205, inputuser(132,"Ziryll", 33000));
    registerUser(x,205, inputuser(133,"Majarocon", 700));
    registerUser(x,205, inputuser(134,"Paolo", 20000));
    registerUser(x,205, inputuser(136,"Nazzar", 35000));
    registerUser(x,205, inputuser(137,"Lopez", 55000));

    int choice;
    do{
        displaybank(x);
        displayUser(x);
        printf("=========================\n\n");
        printf("1. Send Money\n2. Transfer User to Another Bank\n3. Withdraw Money\n4. Register User");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        //pag imo2 nlang og input ari
        int userIdFrom, userIdTo, transferMoney;
        int userID, bankID;
        int success;
        int userId, money;
        switch(choice){
            case 1:
            	printf("Enter sender ID: ");
            	scanf("%d",&userIdFrom);
            	
            	printf("Enter recipient ID: ");
            	scanf("%d",&userIdTo);
            	
            	printf("Enter money to transfer: ");
            	scanf("%d",&transferMoney);
                int moneySucc = sendMoney(x, userIdFrom, userIdTo, transferMoney);
                
                moneySucc?printf("\n \nSUCCESS! \n \n"):printf("\n \nFAIL! \n \n");
                break;
            case 2:
            	
            	printf("Enter your user ID: ");
            	scanf("%d", &userID);
            	
            	printf("Enter your bank ID: ");
            	scanf("%d", &bankID);
                success = transferUser(x, userID, bankID);
                success?printf("\n \nSUCCESS! \n \n"):printf("\n \nFAIL! \n \n");
                break;
            case 3:
            	
            	printf("Enter user ID: ");
            	scanf("%d", &userId);
            	
            	printf("Enter money to withdraw: ");
            	scanf("%d", &money);
                int withSucc = withdraw(x, userId, money);
                
                withSucc?printf("\n \nSUCCESS! \n \n"):printf("\n \nFAIL! \n \n");
                break;
            case 4:
                //bool registerUser(Node *x, int id, User user);//
                break;
            case 0:
                choice = 0;
                break;
        }
    }while(choice!=0);
}
/*
    typedef struct{
    int thousands;
    int fivehundreds;
    int onehundreds;
}Bill;

typedef struct{
    int id;
    char brand[20];
    char location[20];
    Bill bills;
    int balance;
}Bank;

typedef struct{
    int id;
    char fname[20];
    int balance;
}User;

typedef struct{
    int count;
    int max;
    Bank name;
    User *user;
}BankList;

typedef struct node{
    BankList bank;
    struct node *next;
}Node;
*/

// // Create a bool function that lets user withdraw from the bank if divisible by 100, deduct balance and bills on both(Bank and user), 
// //(return true if withdrawal dont exceed the balance of bank, false if otherwise)
bool withdraw(Node *x, int userId, int withdraw){
   /*
   		Essential steps:
   		1. Find userId
   		2. Add user balance
   		3. Deduct bank balance and bills
   		
   		check if withdraw is divisible by 100
   		
   */
   if(withdraw%100==0){
   		Node *trav;
   		int i, flag=1;
   		for(trav=x;trav!=NULL && flag;trav=trav->next){
   			for(i=0;i<trav->bank.count && flag;i++){
     			if(trav->bank.user[i].id == userId){
     				trav->bank.user[i].balance += withdraw;
     				trav->bank.name.balance -= withdraw;
     				
     				while(withdraw > 0){
     					if(withdraw % 1000 == 0){
     						withdraw -= 1000;
     						trav->bank.name.bills.thousands--;
     				
						}else if(withdraw % 500 == 0){
							withdraw -= 500;
     						trav->bank.name.bills.fivehundreds--;
						}else{
							withdraw -= 100;
     						trav->bank.name.bills.onehundreds--;
						}
     					
					}
     				flag=0;
		 		}
	 		}
		}
		
		return (flag==0)? true:false;
   }
   	return false;
   
}


Bank bankname(int id, char brand[], char location[], int bal){
    Bank x;
    x.id = id;
    strcpy(x.brand, brand);
    strcpy(x.location, location);
    x.balance = bal;
    x.bills = (Bill){20, 30, 100};
    return x;
}

BankList populateBank(Bank name){
    BankList x;
    x.name = name;
    x.count = 0;
    x.max = 5;
    x.user = malloc(sizeof(User) * x.max);
    return x;
}

void populateNode(Node **x, BankList bank){
    Node *temp = malloc(sizeof(Node));
    temp->bank = bank;
    temp->next = *x;
    *x = temp;
}

void displaybank(Node *x){
	printf("==========================\n");
    printf("Banks Available:\n");
    printf("ID\tName\tLocation\tBalance\t\tBills\n\n");
    while(x != NULL){
        printf("%-3d - %-10s - %-12s - %-10d - Thousands: %-5d - FiveHundreds: %-5d - Hundreds: %-5d\n",x->bank.name.id,x->bank.name.brand,x->bank.name.location,
                               x->bank.name.balance,x->bank.name.bills.thousands, x->bank.name.bills.fivehundreds,x->bank.name.bills.onehundreds);
        x = x->next;
    }
    printf("\n");
}


User inputuser(int id, char name[], int balance){
    User x;
    x.id = id;
    strcpy(x.fname, name);
    x.balance = balance;

    return x;
}

bool registerUser(Node *x, int id, User user){
    
    while(x != NULL){
        if(x->bank.name.id == id){
            if(x->bank.count == x->bank.max){
                x->bank.user = realloc(x->bank.user, ++x->bank.max * sizeof(User)); //Increase dynamic size if user is full
            }
            x->bank.user[x->bank.count++] = user;
            return true;   
        }
        x = x->next;
    }
    return false;
}

void displayUser(Node *x){
	int i;
    while(x != NULL){
    	
        printf("%s Users(%d/%d):\n",x->bank.name.brand, x->bank.count, x->bank.max);
        for( i = 0; i < x->bank.count; i++){
            printf("%d - %s - %d\n",x->bank.user[i].id,x->bank.user[i].fname, x->bank.user[i].balance);
        }
        printf("\n");
        x = x->next;
    }
}

// Create a bool function that transfers a user from a bank to another bank 
// if count and max is the same....decrease max, count and realloc
// (return true if transfer successful, false if bank dont exist or user alrdy exist in the bank)
bool transferUser(Node *x, int userId, int bankID){
    /*
        traverse bank LL, bankID find and userID 
        check the users of each bank if they have the same id
        remove that user from that bank, subtract count;
        add that user to that bank, increase count

        return false if userId is not found or bankID is not found
    */
    Node *findB, *findU;
    User temp;
    int i, j, flag = 1;
    
    // find bank
    for(findB=x;findB->bank.name.id != bankID;findB=findB->next){}
    if(findB==NULL){
    	printf("\n \nfindb\n \n");
        return false;
    }
    // find user and delete it from the bank
    for(findU=x;findU!=NULL && flag==1;findU=findU->next){
        for(i=0;i<findU->bank.count && flag==1;i++){
            if(findU->bank.user[i].id == userId){
                temp = findU->bank.user[i];
                // delete by shifting
                for(j=i+1;j<findU->bank.count;j++){
                    findU->bank.user[j-1] = findU->bank.user[j];
                }
                findU->bank.count--;
                flag = 0;
            }
        }
    }
    if(flag==1){
        return false;
    }

    // add user to bank
    if(findB->bank.count < findB->bank.max){
        findB->bank.user[findB->bank.count++] = temp;
    }else{
        findB->bank.count++;
        findB->bank.max++;
        findB->bank.user = realloc(findB->bank.user, sizeof(User)*findB->bank.count);
        findB->bank.user[findB->bank.count-1] = temp;
    }
    return true;
}

// // Create a bool function to transfer user balance/send money to another user when its in the same bank 
// // deduct/add the balance of the user
// //(return true if transfer successful, false if user dont exist / if sender balance exceeds)
bool sendMoney(Node *x, int userIdFrom, int userIdTo, int transferMoney){
  /*	
  	Essential steps:
  	1. Find user
  	2. Find 2nd user
  	3. Deduct balance user, and add 2nd user
  */
  Node *sender;
  int i, flag=1;
  for(sender=x;sender!=NULL;sender=sender->next){
     for(i=0;i<sender->bank.count;i++){
     	if(sender->bank.user[i].id == userIdFrom){
     		sender->bank.user[i].balance -= transferMoney;
     		flag=0;
		 }
	 }
  }
  
  for(sender=x;sender!=NULL;sender=sender->next){
     for(i=0;i<sender->bank.count;i++){
     	if(sender->bank.user[i].id == userIdTo){
     		sender->bank.user[i].balance += transferMoney;
     		flag=0;
		 }
	 }
  }
  
  return (flag==0)?true:false;
}



