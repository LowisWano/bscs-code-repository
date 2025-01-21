#include<stdio.h>
#define V 5
#define INF 999

void printMST(int MST[V][V]) {
    printf("Edge \tWeight\n");
    
    // Only need to check upper triangle of matrix since undirected
    for(int i = 0; i < V; i++) {
        for(int j = i + 1; j < V; j++) {
            if(MST[i][j] != INF) {  // If edge exists
                printf("%d - %d \t%d\n", i, j, MST[i][j]);
            }
        }
    }
}

int checkIfAllVisited(int visited[]){
  int i;
  for(i=0;i<V && visited[i] == 1;i++){}
  return (i==V) ? 1:0;
}

// create a new adjacency matrix and print it
void primMST(int graph[V][V], int start){
  /*
    create and init MST matrix

    create and initialize visited bit vector set

    set starting vertex as visited

    while all vertices have not been visited
      for every visited vertex,
      check each edge whose other vertex is not yet visited, not INF, and smaller than the current min edge
    

    if a min edge is found
      input edge to MST
      add the new connected vertex to the visited set
  */
  int MST[V][V];
  int x,y;
  for(x=0; x<V; x++){
    for(y=0; y<V; y++){
      MST[x][y] = INF;
    }
  }

  int visited[V] = {0};
  visited[start] = 1;

  while(!checkIfAllVisited(visited)){
    int min_weight = INF;
    int from_vertex = INF;
    int to_vertex = INF;

    for(x=0;x<V;x++){
      if(visited[x] == 1){
        for(y=0;y<V;y++){
          if(visited[y] == 0 && graph[x][y] != INF && graph[x][y] < min_weight){
            min_weight = graph[x][y];
            from_vertex = x;
            to_vertex = y;
          }
        }
      }
    }

    if(min_weight != INF){
      MST[from_vertex][to_vertex] = min_weight;
      MST[to_vertex][from_vertex] = min_weight;
      visited[to_vertex] = 1;
    }
  }

  printMST(MST);
}

int main() {
    int graph[V][V] = {
        {INF, 2, INF, 6, INF},
        {2, INF, 3, 8, 5},
        {INF, 3, INF, INF, 7},
        {6, 8, INF, INF, 9},
        {INF, 5, 7, 9, INF}
    };

    // the MST will always be the same no matter what vertex you start
    primMST(graph, 3);
    return 0;
}