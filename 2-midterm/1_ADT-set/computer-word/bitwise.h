#ifndef BITWISE_H
#define BITWISE_H

#include<stdio.h>
#include<stdlib.h>

typedef unsigned int SET;
int findThirdBit(SET x);
int findNBit(SET x, int n);
void displayBitPattern(SET x);
void insertElem(SET *x, int elem);
/*
<< - MULTIPLY
ex: 45 << 1 == 90

>> - DIVIDE
90 >> 1 == 45
 */

#endif