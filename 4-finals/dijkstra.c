#include<stdio.h>
#define MAX 6
#define X 999

// typedef struct{
//   char label;
//   int weight;
// }Node;

typedef int Matrix[MAX][MAX];

int findMinDistance(int dist[], int visited[]);
void Djikstra(Matrix M, int start);

int main(void){

  Matrix Graph[MAX][MAX] = {
    {0, 2, X, 8, X, X},
    {2, 0, X, 5, 6, X},
    {X, X, 0, X, 9, 3},
    {8, 5, X, 0, 3, 2},
    {X, 6, 9, 3, 0, 1},
    {X, X, 3, 2, 1, 0},
  };
}

void Djikstra(Matrix M, int start){
  /*
    1. create a dist array list that stores the shortest paths from start to a node
    2. create a visited set using bit vector
    3. populate dist with adjacent node values
    4. find the smallest unvisited node
    5. Mark current node as visited
    6. Update dist values 
  */
  int dist[MAX];
  int visited[MAX] = {0};

  // initializes dist
  int i;
  for(i=0;i<MAX;i++){
    dist[i] = X;
  }
  dist[start] = 0;

  
}

int findMinDistance(int dist[], int visited[]){
  int i;
  int smallest, smallestVal = X;
  for(i=0;i<MAX;i++){
    if(dist[i] <= smallestVal && visited[i] == 0){
      smallest = i;
      smallestVal = dist[i];
    }
  }
  return smallest;
}