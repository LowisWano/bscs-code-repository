/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void displayElements(struct ListNode* L){
    struct ListNode* trav;
    for(trav=L;trav!=NULL;trav=trav->next){
        printf("%d ", trav->val);
    }
}

// this function is probably inefficient
struct ListNode* copyList(struct ListNode* list1){
    int flag;
    struct ListNode *head, *trav1, *travNew;
    for(trav1=list1,flag=0;trav1!=NULL;trav1=trav1->next){
        if(flag==0){
            // copy manually the first element of the linked list (only executes once after flag++)
            head = malloc(sizeof(struct ListNode));
            head->val = trav1->val;
            head->next = NULL;
            travNew = head;
            flag++;
        }else{
            travNew->next = malloc(sizeof(struct ListNode));
            travNew = travNew->next;
            travNew->val = trav1->val;
            travNew->next = NULL;  
        } 
    }
    return head;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // handle scenario if linked list is empty
    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }

    // copy entire list1 to head
    struct ListNode *head = copyList(list1);
    struct ListNode **travH;
    struct ListNode *trav2, *temp;

    // traverse each node of list2 and compare it to each values of head and use insertBehind() to insert the element behind it if it sees a bigger number 
    // we're probably gonna want to use pointer to pointer node

    for(trav2=list2;trav2!=NULL;trav2=trav2->next){
        for(travH=&head;travH!=NULL;travH=&(*travH)->next){
            if(trav2->val<=(*travH)->val){
                // insert behind
                temp = *travH;
                *travH = malloc(sizeof(struct ListNode));
                (*travH)->val = trav2->val;
                (*travH)->next = temp;
                temp=NULL;
                // there is an infinite loop
            }
            printf("%d ", (*travH)->val);
        }
    }

    // display head
    displayElements(head);
    return head;
}
