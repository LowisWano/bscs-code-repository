#include "./link-header/linkListQueueHeader.h"
// #include "./array-header/arrayQueueHeader.h"

int main(void){
  Queue Q;
  initQueue(&Q);
  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'C');
  displayQueue(Q);
  
  dequeue(&Q);
  printf("\nafter dequeing: ");
  displayQueue(Q);
  
  printf("\nlets enqueue another element!: ");
  enqueue(&Q, 'D');
  displayQueue(Q);
    
    
  printf("\npeek on the value of front: %c\n", peek(Q));
  return 0;
}
