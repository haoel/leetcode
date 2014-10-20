// Source : https://oj.leetcode.com/problems/partition-list/
// Author : Hao Chen
// Date   : 2014-06-21

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
    ListNode fakeHead(0);
    fakeHead.next = head;
    head = &fakeHead;
    
    ListNode *pos = NULL;
    for(ListNode *p = head; p!=NULL && p->next!=NULL; ){
        if (!pos && p->next->val >= x){
            pos = p;
            p=p->next;
            continue;
        }
        if (pos && p->next->val < x){
            ListNode *pNext = p->next;
            p->next = pNext->next;
            pNext->next = pos->next;
            pos->next = pNext;
            pos = pNext;
            continue;
        }
        p=p->next;
    }
    
    return head->next;
}

void printList(ListNode* h)
{
    while(h!=NULL){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

int main()
{
    //int a[] = {1}; int x =2;
    //int a[] = {2,3,1}; int x=2;
    int a[] = {3,1,2}; int x=3;
    ListNode* p = createList(a, sizeof(a)/sizeof(int)); 
    printList(p);
    p = partition(p, x);
    printList(p);

    return 0;
}
