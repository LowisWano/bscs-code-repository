#include "./bitwise.h"

int findThirdBit(int x){
  return ((x & 4) == 4) ? 1:0;
}

int findNBit(int x, int n){
  int mask = 1 << (n-1);
  return ((x & mask) == mask) ? 1:0;
}

void displayBitPattern(int x){
  unsigned int mask = 1 << ((sizeof(x)*8)-1);
  while(mask!=0){
    printf("%d ", (x & mask)? 1:0);
    mask = mask >> 1;
  }
  printf("\n");
}
