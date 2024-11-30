#include <stdio.h>
#include <stdlib.h>

#define MAX_FLIGHTS 100

// Define the structure for flights
typedef struct {
    int source;       // Source city
    int destination;  // Destination city
    int cost;         // Cost of the flight
} Flight;

// Define the structure for subsets (for Union-Find)
typedef struct {
    int parent;  // Parent of the subset
    int rank;    // Rank of the subset
} Subset;

// Function prototypes
int compareFlights(const void *a, const void *b); // Function to compare flights by cost
int find(Subset subsets[], int i);               // Function to find the root of a set
void unionSets(Subset subsets[], int x, int y);  // Function to union two sets
void kruskalMST(Flight flights[], int numFlights, int numCities); // Kruskal's MST algorithm

int main() {
    int numCities, numFlights;
    Flight flights[MAX_FLIGHTS];

    // Input the number of cities and flights
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    printf("Enter the number of flights: ");
    scanf("%d", &numFlights);

    // Input flight data
    for (int i = 0; i < numFlights; i++) {
        printf("Enter source, destination, and cost for flight %d: ", i + 1);
        scanf("%d %d %d", &flights[i].source, &flights[i].destination, &flights[i].cost);
    }

    // Call Kruskal's algorithm to find the MST
    kruskalMST(flights, numFlights, numCities);

    return 0;
}

// Function to compare flights by their cost (used in sorting)
int compareFlights(const void *a, const void *b) {
    // TODO: Implement comparison logic for sorting flights by cost
    Flight *x = (Flight*) a;
    Flight *y = (Flight*) b;
    return x->cost - y->cost;
}

// Function to find the root of a set (with path compression)
int find(Subset subsets[], int i) {
    // TODO: Implement find with path compression
    int x = i;
    for(; x != subsets[x].parent; x = subsets[x].parent){
      printf("x: %d\n", x);
    }
    return x;
}

// Function to union two sets (by rank)
void unionSets(Subset subsets[], int x, int y) {
    // TODO: Implement union by rank
  if(subsets[x].rank > subsets[y].rank){
    subsets[y].parent = x;
  }else if(subsets[x].rank < subsets[y].rank){
    subsets[x].parent = y;
  }else{
    subsets[y].parent = x;
    subsets[x].rank++;
  }
}

// Function to compute the MST using Kruskal's algorithm
void kruskalMST(Flight flights[], int numFlights, int numCities) {
  // TODO: Sort flights by cost
  int i, j;
  for(i=0;i<numFlights-1;i++){
    for(j=0;j<numFlights-1;j++){
      if(compareFlights(&flights[j], &flights[j+1]) > 0){
        Flight temp = flights[j];
        flights[j] = flights[j+1];
        flights[j+1] = temp;
      }
    }
  }

  // TODO: Initialize subsets
  Subset comp[numCities];
  for(i=0;i<numCities;i++){
    Subset v;
    v.parent = i;
    v.rank = 0;
    comp[i] = v;
  }

  // TODO: Iterate through sorted flights and construct the MST
  Flight MST[MAX_FLIGHTS];
  int count = 0;
  int totalCost = 0;

  for(i=0;i<numFlights;i++){
    int x = find(comp, flights[i].source);
    int y = find(comp, flights[i].destination);
    if(x != y){
      unionSets(comp, x, y);
      MST[count++] = flights[i];
      totalCost += flights[i].cost;
    }
  }

  // TODO: Print the MST and total cost
  if(count != numCities-1){
    printf("The graph is not fully connected; MST cannot be formed.\n");
  }else{
    printf("Minimum Spanning Tree:\n");
    for(i=0;i<count;i++){
      printf("Edge: %d - %d, Cost: %d\n", MST[i].source, MST[i].destination, MST[i].cost);
    }
    printf("\nTotal cost of the MST: %d\n", totalCost);
  }
}