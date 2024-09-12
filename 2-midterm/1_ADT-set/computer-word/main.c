#include "./bitwise.h"

int main(void){

  SET x = 0;

  //prints 0
  // printf("17: %d\n", findThirdBit(17));

  // // prints 1
  // printf("21: %d\n", findThirdBit(21));

  // //prints 0
  // printf("21: %d\n", findNBit(21, 2));
  
  // // prints 1
  // printf("21: %d\n", findNBit(21, 3));

  // printf("display binary of 21: \n");
  // displayBitPattern(21);

  insertElem(&x, 5);
  displayBitPattern(x);
  return 0;
}