#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[20];

typedef struct {
    int day, month, year;    
} MyDate;

typedef struct {
    int id;
    String name;
    MyDate exp;
    float price;
} Product;

typedef struct node {
    Product prods;
	struct node *next;
} ProductList;

//Populating the Products
// MyDate createDate(int day, int month, int year);
// Product createProduct(int id, String name, MyDate exp, float price);
// void populateProductList(ProductList **list, Product prods);


void addProductSorted(ProductList **list, Product p); // Add product on a sorted using date difference
ProductList *removeExpiredProducts(ProductList **list, MyDate exp); // Remove expired products and returns the removed products
void removeProduct(ProductList **list, int ndx); // Remove product in a certain index

// 3 helper functions to use in removeExpiredProducts function to determine product expiration
int isLeapYear(int year);
int daysInMonth(int month, int year);
int dateDifference(MyDate d1, MyDate d2);
void displayProductList(ProductList *list);
// ==============================================
int checkIfExpired(MyDate exp, MyDate dateNow){
    int flag=0;
    if(dateNow.year > exp.year){
        return 1;
    }else if(dateNow.year == exp.year){
        if(dateNow.month > exp.month){
            return 1;
        }else if (dateNow.month == exp.month){
            if(dateNow.day > exp.day){
               return 1; 
            }
        }
    }
    return 0;
}
ProductList *removeExpiredProducts(ProductList **list, MyDate exp){
	// deleteAllOccurences, insertSorted
	ProductList *expired = NULL, *temp;
	ProductList **trav;
	// exp = May 5 2024
	// trav = feb 3 2023
	for(trav=list;*trav!=NULL;){
		if(checkIfExpired((*trav)->prods.exp, exp)){
			// deleting
			temp = *trav;
			*trav = (*trav)->next;
			
			// insertFirst
			temp->next = expired;
			expired = temp;
		}else{
			trav=&(*trav)->next;
		}
	}
	
	
	return expired;
}


void main() {
    ProductList *head = NULL;
    /*
        Order should be earliest to latest:
        Japanese Bento - March 21, 2022
        Cake - November, 4, 2023
        Banana - July 16, 2024
        Pineapple - July 24, 2024
        Orange - September 16, 2024
        Apple - January 1, 24, 2025

    */
    Product prod1 = {111111,"Apple",{1,24,2025},50.99};
    Product prod2 = {222222,"Banana",{5,3,2024},32.99};
    Product prod3 = {333333,"Orange",{9,24,2024},33.5};
    Product prod4 = {444444,"Cake",{11,4,2023},999.10};
    Product prod5 = {555555,"Japanese Bento",{3,21,2022},150.63};
    Product prod6 = {666666,"Pineapple",{7,24,2024},10.88};
    
    addProductSorted(&head,prod1);
    addProductSorted(&head,prod2);
    addProductSorted(&head,prod3);
    addProductSorted(&head,prod4);
    addProductSorted(&head,prod5);
    addProductSorted(&head,prod6);
  
    displayProductList(head);
    MyDate exp = {5,4,2024};
    
    ProductList *expired = removeExpiredProducts(&head, exp);
    printf("\nAfter Removing Expired: \n");
    printf("Orig list:\n");
    displayProductList(head);
    printf("Expired list:\n");
    displayProductList(expired);
}

// insertSorted by date difference
void addProductSorted(ProductList **list, Product p){
   
    // earliest to latest by day, month, and year
    /*
        1, 24, 2025
        3, 16, 2025
    */
    ProductList **trav;
    ProductList *temp;
    int flag = 1;
    
    // apple gets inserted first regardless

    // p == Banana - July 16, 2025
    // trav == Apple - January 1, 24, 2025
    for(trav=list;*trav!=NULL && flag;){
        // p = 2025, trav = 2025
        if(p.exp.year < (*trav)->prods.exp.year){
            flag = 0;
        }else if(p.exp.year == (*trav)->prods.exp.year){
            // p = July, trav = July
            if(p.exp.month < (*trav)->prods.exp.month){
                flag = 0;
            }else if(p.exp.month == (*trav)->prods.exp.month){
                // p = 16, trav = 24
                if(p.exp.day < (*trav)->prods.exp.day){     
                    flag = 0;
                }else{
                    trav=&(*trav)->next;
                }
            }else{
                trav=&(*trav)->next;
            }
        }else{
            trav=&(*trav)->next;
        }  
    }
    
    temp = malloc(sizeof(ProductList));
    temp->prods = p;
    temp->next = *trav;
    *trav = temp;
}

void displayProductList(ProductList *list){
    for(;list!=NULL;list=list->next){
        printf("%d %s %d %d %d\n", list->prods.id, list->prods.name, list->prods.exp.day, list->prods.exp.month, list->prods.exp.year);
    }
    printf("\n \n");
}
