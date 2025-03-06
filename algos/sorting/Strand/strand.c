#include "../../utilities/general.h" 
#include "../../utilities/test.h" 

void strand_sort_inplace(int arr[], int size);

int main(void) {
    test_sort_w_size(strand_sort_inplace);
    
    return 0;
}

int* strand_sort_helper(int input[], int n) {
    int *result = (int*)malloc(sizeof(int)*n);
    int result_size = 0;
    int orig_size = n;

    while(n > 0) {
        int i, j;

        // Step 1: insertAndDelete() first element of input[] to strand[]
        int strand[n], strand_size = 0;
        strand[strand_size++] = input[0];
        for(j=1; j<n; j++) {
            input[j-1] = input[j];
        }
        n--;

        // Step 2: Traverse through input[] and insertAndDelete() all its elems that are > last elem of strand[]
        for(i=0; i<n;) {
            if(input[i] >= strand[strand_size-1]) {
                strand[strand_size++] = input[i];
                for(j=i+1; j<n; j++) {
                    input[j-1] = input[j];
                }
                n--;
            } else {
                // Remember: Only move pointer when you are not deleting. If not, you will skip over an element.
                i++;
            }
        }

        // Step 3: Perform unionSet() to strand[] and result[]
        int temp[orig_size], temp_size=0;
        for(i=0, j=0; i<strand_size && j<result_size;) {
            if(strand[i] < result[j]) {
                temp[temp_size++] = strand[i++]; 
            } else {
                temp[temp_size++] = result[j++];
            }
        }

        while(i < strand_size && j == result_size) {
            temp[temp_size++] = strand[i++];
        }

        while(j < result_size && i == strand_size) {
            temp[temp_size++] = result[j++];
        }

        for(i=0; i<temp_size; i++) {
            result[i] = temp[i];
        }
        result_size = temp_size;
    }
    
    return result;
}

void strand_sort_inplace(int arr[], int size) {
    if (size <= 1) return;
    
    int *input = (int*)malloc(sizeof(int) * size);
    memcpy(input, arr, sizeof(int) * size);
    
    int *sorted = strand_sort_helper(input, size);
    
    memcpy(arr, sorted, sizeof(int) * size);
    
    free(input);
    free(sorted);
}