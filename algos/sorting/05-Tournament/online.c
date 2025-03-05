#include "../../utilities/general.h" 
#include "../../utilities/test.h" 


// Tournament sort function declaration
void tournament_sort(int arr[], int n);

int main(void) {
    // Use the test framework to test your implementation
    test_sort_w_size(tournament_sort);
    
    return 0;
}

// Implement your tournament sort algorithm here
void tournament_sort(int arr[], int n) {
    // Your implementation will go here
    
    // Tournament sort works by:
    // 1. Building a tournament (complete binary tree)
    // 2. Finding the winner (minimum/maximum element)
    // 3. Remove the winner and rebuild the tournament
    // 4. Repeat until all elements are sorted
    
}