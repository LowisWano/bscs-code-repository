#include "./functions.h"

int main(void){
  AdjacencyMatrix graph = {
    {X, 2, X, 8, X, X},
    {2, X, X, 5, 6, X},
    {X, X, X, X, 9, 3},
    {8, 5, X, X, 3, 2},
    {X, 6, 9, 3, X, 1},
    {X, X, 3, 2, 1, X},
  };

  bfs(graph, 0);

  return 0;
}