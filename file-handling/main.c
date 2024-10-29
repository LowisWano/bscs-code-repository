#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
  int priority;
  char direction[20];
  char lane[20];
  int time;
}Traffic;

typedef struct{
  Traffic Elem[MAX];
  int last;
}Heap;

/*
  Priority Levels:
  1 - Vehicles Straight Main
  2 - Vehicles Left Main
  3 - Vehicles Right Main
  4 - Vehicles Straight Diversion
  5 - Vehicles Left Diversion
  6 - Vehicles Right Diversion
  7 - Pedestrian Main
  8 - Pedestrian Diversion
*/

// helper functions
Traffic createTraffic(int p, char *direction, char *lane, int time);
void displayTraffic(Traffic t);

// data functions
void initTrafficData(Traffic list[], int count);
void insertTrafficDataMinHeap(Heap *H);

// POT operations
void initHeap(Heap *H);
void insert(Heap *H, Traffic t);
void preorder(Heap H, int node);
void deleteMin(Heap *H, int node);

int main(void){
  Traffic list[6];
  Heap H;
  initHeap(&H);

  list[0] = createTraffic(3, "right", "main", 50);
  list[1] = createTraffic(5, "left", "diversion", 40);
  list[2] = createTraffic(1, "straight", "main", 60);
  list[3] = createTraffic(6, "right", "diversion", 30);
  list[4] = createTraffic(3, "right", "main", 20);
  list[5] = createTraffic(7, "pedestrian", "main", 10);

  initTrafficData(list, 6);	
  insertTrafficDataMinHeap(&H);
  preorder(H, 0);

  return 0;
}

void preorder(Heap H, int node){
  if(node <= H.last){
    printf("prio: %-10d - %s %s\n", H.Elem[node].priority, H.Elem[node].direction, H.Elem[node].lane);
    preorder(H, (node*2)+1);
    preorder(H, (node*2)+2);
  }
}

// insert by priority, min is highest. Parent should always be lesser value than child
void insert(Heap *H, Traffic t){
  if(H->last < MAX){
    // insert
    H->Elem[++H->last] = t;

    // shift parent and child if POT is not observed
    Traffic temp;
    int child = H->last;
    int parent = (child-1)/2;
    while(H->Elem[child].priority < H->Elem[parent].priority){
      temp = H->Elem[child];
      H->Elem[child] = H->Elem[parent];
      H->Elem[parent] = temp;
    }
  }
}

void insertTrafficDataMinHeap(Heap *H){
  FILE *fp;
  fp = fopen("scenarios.dat", "rb");  //read
  if(fp != NULL){
    Traffic t;
    while(fread(&t, sizeof(Traffic), 1, fp)){
      insert(H, t);
    }
	}
  fclose(fp);
}

void initTrafficData(Traffic list[], int count){
  FILE *fp;
  fp = fopen("scenarios.dat", "wb");  //write

  if(fp != NULL){
  	fwrite(list, sizeof(Traffic), 6, fp);
	}
  fclose(fp);
}

void initHeap(Heap *H){
  int i;
  for(i-0;i<MAX;i++){
      H->Elem[i].priority = -1;
  }
  H->last = -1;
}

void displayTraffic(Traffic p){
	printf("%-20s %s\n", p.direction, p.lane);
}

Traffic createTraffic(int pri, char *direction, char *lane, int t){
  Traffic p;
  strcpy(p.direction, direction);
  strcpy(p.lane, lane);
  p.priority = pri;
  p.time = t;
  return p;
}