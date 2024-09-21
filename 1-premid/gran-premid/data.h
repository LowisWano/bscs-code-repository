#ifndef DATA_H
#define DATA_H

typedef char String[30];

typedef struct {
    int month;
    int day;
    int year;
} Date;

typedef struct {
    int prodID;
    String prodName;
    int prodQty;
    Date expiry;
    Date manufacture;
} Product;

typedef struct {
    Product prods[100];
    int count;
} ProductList;

Date createDate(int month, int day, int year);
Product createProduct(int prodID, String prodName, int prodQty, Date expiry, Date manufacture);

void displayDate(Date d);
void displayProduct(Product p);

int daysInMonth(int month, int year);
int dateDifference(Date d1, Date d2);

void createAndPopulate(ProductList *prod, int selection, int n);

#endif
