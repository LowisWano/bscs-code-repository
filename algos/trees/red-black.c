#include <stdio.h>
#include <stdlib.h>

// Define colors
#define RED 0
#define BLACK 1

// Node structure
typedef struct RBNode {
    int key;
    int color;
    struct RBNode *left, *right, *parent;
} RBNode;

// Tree structure
typedef struct {
    RBNode *root;
    RBNode *NIL;  // Sentinel node
} RBTree;

// Create a new node
RBNode* createNode(int key) {
    RBNode *newNode = (RBNode*)malloc(sizeof(RBNode));
    newNode->key = key;
    newNode->color = RED;  // New nodes are red by default
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Initialize a red-black tree
RBTree* createRBTree() {
    RBTree *tree = (RBTree*)malloc(sizeof(RBTree));
    tree->NIL = (RBNode*)malloc(sizeof(RBNode));
    tree->NIL->color = BLACK;
    tree->NIL->left = NULL;
    tree->NIL->right = NULL;
    tree->NIL->parent = NULL;
    tree->root = tree->NIL;
    return tree;
}

// Left rotation
void leftRotate(RBTree *tree, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    
    if (y->left != tree->NIL)
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (x->parent == tree->NIL)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}

// Right rotation
void rightRotate(RBTree *tree, RBNode *y) {
    RBNode *x = y->left;
    y->left = x->right;
    
    if (x->right != tree->NIL)
        x->right->parent = y;
    
    x->parent = y->parent;
    
    if (y->parent == tree->NIL)
        tree->root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    
    x->right = y;
    y->parent = x;
}

// Fix the tree after insertion
void insertFixup(RBTree *tree, RBNode *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode *y = z->parent->parent->right;
            
            // Case 1: Uncle is red
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                // Case 2: Uncle is black and z is a right child
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                
                // Case 3: Uncle is black and z is a left child
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            // Same as above with "left" and "right" exchanged
            RBNode *y = z->parent->parent->left;
            
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
        
        if (z == tree->root)
            break;
    }
    
    tree->root->color = BLACK;
}

// Insert a node into the tree
void insert(RBTree *tree, int key) {
    RBNode *z = createNode(key);
    RBNode *y = tree->NIL;
    RBNode *x = tree->root;
    
    // Find position to insert
    while (x != tree->NIL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    
    z->parent = y;
    
    if (y == tree->NIL)
        tree->root = z;  // Tree was empty
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    
    z->left = tree->NIL;
    z->right = tree->NIL;
    z->color = RED;
    
    insertFixup(tree, z);
}

// Search for a key
RBNode* search(RBTree *tree, int key) {
    RBNode *current = tree->root;
    
    while (current != tree->NIL && key != current->key) {
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    
    return current;
}

// In-order traversal
void inOrder(RBTree *tree, RBNode *node) {
    if (node != tree->NIL) {
        inOrder(tree, node->left);
        printf("%d (%s) ", node->key, node->color == RED ? "RED" : "BLACK");
        inOrder(tree, node->right);
    }
}

// Free memory
void freeRBTree(RBTree *tree, RBNode *node) {
    if (node != tree->NIL) {
        freeRBTree(tree, node->left);
        freeRBTree(tree, node->right);
        free(node);
    }
}

// Main function for testing
int main() {
    RBTree *tree = createRBTree();
    
    // Insert some values
    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
    insert(tree, 15);
    insert(tree, 5);
    
    printf("In-order traversal: ");
    inOrder(tree, tree->root);
    printf("\n");
    
    // Clean up
    freeRBTree(tree, tree->root);
    free(tree->NIL);
    free(tree);
    
    return 0;
}