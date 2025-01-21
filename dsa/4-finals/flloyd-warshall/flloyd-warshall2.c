#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int val;
    struct node *LC;
    struct node *RC;
}*BST;

void insertBST(BST *T, int elem);

void insertBST(BST *T, int elem){
    BST *trav;
    for(trav = T; *trav != NULL;){
        if(elem < (*trav)->val){
            trav = &(*trav)->LC;
        }else{
            trav = &(*trav)->RC;
        }
    }
    
    if(*trav==NULL){
        BST temp = malloc(sizeof(struct node));
        temp->val = elem;
        temp->LC = NULL;
        temp->RC = NULL;
        *trav = temp;
    }
}

void deleteElemBST(BST *T, int elem){
    BST *trav;
    for(trav = T; *trav != NULL && (*trav)->val != elem;){
        if(elem < (*trav)->val){
            trav = &(*trav)->LC;
        }else if(elem > (*trav)->val){
            trav = &(*trav)->RC;
        }
    }
    
    if(*trav!=NULL){
        BST temp;
        // if has two children
        if((*trav)->LC != NULL && (*trav)->RC != NULL){
            // moves 1 step to RC, then continues furthest left
            BST *nearest = &(*trav)->RC;
            
            while((*nearest)->LC!=NULL){
                nearest = &(*nearest)->LC;
            }
            
            (*trav)->val = (*nearest)->val;
            temp = *nearest;
            *nearest = (*nearest)->RC;
        }else{
            temp = *trav;
            *trav = ((*trav)->LC != NULL) ? (*trav)->LC : (*trav)->RC; 
        }
        free(temp);
    }
}

void findKthSmallestElem(BST T, int *count, int k, int *kth){
    if (T == NULL || *count >= k) {
        return;
    }
    
    // Process left subtree
    findKthSmallestElem(T->LC, count, k, kth);
    
    // Process current node
    (*count)++;
    if (*count == k) {
        *kth = T->val;
        return;
    }
    
    // Process right subtree 
    findKthSmallestElem(T->RC, count, k, kth);
}

int minElement(BST T){
    if(T==NULL){
      return -1;
    }
    BST trav;
    for(trav=T; trav->LC!=NULL; trav=trav->LC){}
    printf("%d\n", trav->val);
    return trav->val;
}

int maxElement(BST T){
    if(T==NULL){
      return -1;
    }
    BST trav;
    for(trav=T; trav->RC!=NULL; trav=trav->RC){}
    return trav->val;
}

int main(void){
    BST root = NULL;
    int numNodes=0;
    printf("Enter operations:\n");
    while(1){
        char oper;
        int elem;
        
        scanf(" %c", &oper);
        
        if(oper == 'S'){
            break;
        }
        
        scanf("%d", &elem);
        
        if(oper == '+'){
            numNodes++;
            insertBST(&root, elem);
        }
        
        if(oper == '-'){
            deleteElemBST(&root, elem);
        }
        
        if(oper == '0'){
            printf("Minimum element: %d", minElement(root));
            printf("Maximum element: %d", maxElement(root));
            break;
        }
    }
    
    return 0;
}