#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"
#include "stack.h"


bool addProductBaseOnExpiry(Inventory *i, Product p) {
    // To do code logic here.
    /*
      check if qty does not exceed 100
      transfer node to a temp stack if value of top is more expired than p
      push p then reinsert temp stack
    */
    if(p.prodQty + i->currQty <= 100){
      i->currQty += p.prodQty;

      NodePtr stack = NULL; 
      NodePtr temp = NULL, prod;

      // transfer to temp stack
      while(i->top != NULL && dateDifference(i->top->prod.expiry, p.expiry) > 0){
          temp = stack;
          stack = i->top;
          i->top = i->top->link;
          stack->link = temp;
      }

      // insert
      prod = malloc(sizeof(NodeType));
      prod->prod = p;
      prod->link = i->top;
      i->top = prod;
      
      // reinsert
      while(stack != NULL){
        temp = i->top;
        i->top = stack;
        stack = stack->link;
        i->top->link = temp;
      }
      return true;
    }
    return false;
}

int main() {
    ProductList myProd;
    int numCount, selection;

    printf("Enter sequence or selection: (1-6): ");
    scanf("%d", &selection);
    printf("Enter the number of data: ");
    scanf("%d", &numCount);

    createAndPopulate(&myProd, selection, numCount);

    Inventory myInventory;
    initInventory(&myInventory);

    printf("\nORIGINAL PRODUCT:\n");
    for(int i = 0; i < myProd.count; ++i) {
        displayProduct(myProd.prods[i]);
        printf("\n");
    }

    for(int i = 0; i < myProd.count; ++i) {
        printf("\n[%d.] Adding %s (%d): %s\n", i+1, myProd.prods[i].prodName, myProd.prods[i].prodQty, addProductBaseOnExpiry(&myInventory, myProd.prods[i])? "Success":"Fail");
        visualize(myInventory);
    }

    printf("\nUSING ADD PRODUCT:\n");
    visualize(myInventory);


    return 0;
}




