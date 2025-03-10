#include "../../utilities/general.h"
#include "../../utilities/test.h"

// Structure for a bucket node
typedef struct BucketNode {
  int value;
  struct BucketNode* next;
} BucketNode;

BucketNode* createNode(int value);
void insertSorted(BucketNode** head, BucketNode* newNode);
void bucket_sort(int arr[], int n);

int main(void){
  test_sort_w_size(bucket_sort);
  return 0;
}

// Function to create a new node
BucketNode* createNode(int value) {
    BucketNode* newNode = (BucketNode*)malloc(sizeof(BucketNode));
    if (newNode) {
        newNode->value = value;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node in sorted order
void insertSorted(BucketNode** head, BucketNode* newNode) {
    // If list is empty or new node should be placed before head
    if (*head == NULL || (*head)->value >= newNode->value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    // Find the position to insert
    BucketNode* current = *head;
    while (current->next != NULL && current->next->value < newNode->value) {
        current = current->next;
    }
    
    // Insert the node
    newNode->next = current->next;
    current->next = newNode;
}

// Function for Bucket Sort with integers
void bucket_sort(int arr[], int n) {
    // Find the maximum and minimum values
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
        if (arr[i] < min_val) min_val = arr[i];
    }
    
    // Range of values
    int range = max_val - min_val + 1;
    
    // Number of buckets (can be adjusted based on data distribution)
    int num_buckets = (n < range) ? n : range;
    
    // Create buckets
    BucketNode** buckets = (BucketNode**)malloc(num_buckets * sizeof(BucketNode*));
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }
    
    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        // Calculate the bucket index for each element
        int normalized_val = arr[i] - min_val;
        int bucket_idx = (normalized_val * num_buckets) / range;
        
        if (bucket_idx >= num_buckets) bucket_idx = num_buckets - 1;
        
        // Insert element into the appropriate bucket in sorted order
        BucketNode* newNode = createNode(arr[i]);
        insertSorted(&buckets[bucket_idx], newNode);
    }
    
    // Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        BucketNode* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            BucketNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    // Free bucket pointers
    free(buckets);
}