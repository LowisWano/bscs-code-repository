#include <stdio.h>
#include <limits.h>

#define V 4           // Number of vertices
#define X INT_MAX   // Represent Xinity

void printSolution(int dist[][V]) {
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == X)
                printf("X\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[V][V]) {
  int dist[V][V];
  int i,j,k;

  // copy
  for(i=0;i<V;i++){
    for(j=0;j<V;j++){
      dist[i][j] = graph[i][j];
    }
  }

  // triple for loop
  for(k=0;k<V;k++){
    for(i=0;i<V;i++){
      for(j=0;j<V;j++){
        if(dist[i][k] != X && dist[k][j] != X && dist[i][k] + dist[k][j] < dist[i][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }  
    }
  }


  printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 5, X, 10},
        {X, 0, 3, X},
        {X, X, 0, 1},
        {X, X, X, 0}
    };

    printf("Original graph:\n");
    printSolution(graph);
    printf("\n");

    floydWarshall(graph);

    return 0;
}