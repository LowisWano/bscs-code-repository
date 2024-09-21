#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "Data.h"

typedef struct node{
    Product prod;
    struct node *link;
} NodeType, *NodePtr;

typedef struct {
    NodePtr top;
    int currQty;
} Inventory;

void initInventory(Inventory *i);
bool isEmpty(Inventory i);
bool push(Inventory *i, Product p);
bool pop(Inventory *i);
Product peek(Inventory i);
void visualize(Inventory i);

#endif
