// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : Hao Chen
// Date   : 2014-06-25

/********************************************************************************** 
* 
* Given a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list.
* 
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
* 
*               
**********************************************************************************/

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) {
    ListNode fake(-1);
    fake.next = head;
    head = &fake;

    ListNode *tail=head;

    bool dup = false;
    for(ListNode *p=head->next;  p && p->next; p=p->next){
        if (dup==false && p->val == p->next->val){
            dup = true;            
            continue;
        }
        if (dup==true && p->val != p->next->val){
            dup = false;
            tail->next = p->next;
            continue;
        }
        if (dup==false){
            tail = p;
        }
    }
    if (dup==true){
        tail->next = NULL;
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
    int a[]={1,1,2,3,3};
    int b[]={1,1,1};
    int c[]={1,2,3};
    int d[]={3};

    printList(deleteDuplicates(createList(a, sizeof(a)/sizeof(int))));
    printList(deleteDuplicates(createList(b, sizeof(b)/sizeof(int))));
    printList(deleteDuplicates(createList(c, sizeof(c)/sizeof(int))));
    printList(deleteDuplicates(createList(d, sizeof(d)/sizeof(int))));
    return 0;
}

