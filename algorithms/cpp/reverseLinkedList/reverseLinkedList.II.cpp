// Source : https://oj.leetcode.com/problems/reverse-linked-list-ii/
// Author : Hao Chen
// Date   : 2014-07-05

/********************************************************************************** 
* 
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* 
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
* 
* return 1->4->3->2->5->NULL.
* 
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *reverseBetween(ListNode *head, int m, int n) {

    if (head==NULL || m>=n) return head;

    ListNode fake(0);
    fake.next = head;
    ListNode *pBegin=&fake, *pEnd=&fake;

    int distance = n - m ;
    while(pEnd && distance>0){
        pEnd = pEnd->next;
        distance--;
    } 
    while(pBegin && pEnd && m-1>0) {
        pBegin = pBegin->next;
        pEnd = pEnd->next;
        m--;
    }
    if (pBegin==NULL || pEnd==NULL || pEnd->next == NULL){
        return head;
    }
    
    ListNode *p = pBegin->next;
    ListNode *q = pEnd->next->next;
    
    ListNode *pHead = q;
    while(p != q){
        ListNode* node = p->next;
        p->next = pHead;
        pHead = p;
        p = node;
    }
    pBegin->next = pHead;

    return fake.next;
    
}



void printList(ListNode* h)
{
    while(h!=NULL){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int *a, int n)
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

ListNode* createList(int len) {
    int *a = new int[len];
    for(int i=0; i<len; i++){
        a[i] = i+1;
    }
    ListNode* h =  createList(a, len);
    delete[] a;
    return h;
}

int main(int argc, char** argv)
{
    int l=5;
    int  m=2, n=4;
    
    if (argc>1){
        l = atoi(argv[1]);
    }
    if (argc>2) {
        m = atoi(argv[2]);
    }
    if (argc>3) {
        n = atoi(argv[3]);
    }
    
    ListNode* h = createList(l);
    printList( h );
    printList( reverseBetween(h , m, n) );

    
}
