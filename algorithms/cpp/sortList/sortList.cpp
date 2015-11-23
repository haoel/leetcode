// Source : https://oj.leetcode.com/problems/sort-list/
// Author : Hao Chen
// Date   : 2014-07-06

/********************************************************************************** 
* 
* Sort a linked list in O(n log n) time using constant space complexity.
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

ListNode *mergeTwoLists(ListNode* head1, ListNode* head2);

ListNode *sortList(ListNode *head) {
    if (head==NULL || head->next == NULL){
        return head;
    }
    //find the middle place
    ListNode *p1=head, *p2=head->next; 

    while(p2 && p2->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p2 = p1->next;
    p1->next = NULL;
    return mergeTwoLists(sortList(head), sortList(p2));
}


ListNode *mergeTwoLists(ListNode* head1, ListNode* head2){
    ListNode *p1 = head1,  *p2=head2;
    static ListNode dummy(0);

    ListNode *tail = &dummy;

    while(p1 && p2){
        if(p1->val < p2->val){
            tail->next = p1;
            p1 = p1->next;
        }else{
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }
    if (p1) tail->next = p1;
    if (p2) tail->next = p2;

    return dummy.next;
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


int main(int argc, char** argv)
{
    int n = 10;
    if (argc>1){
        n = atoi(argv[1]);
    }
    srand(time(NULL));

    int *a = new int[n];
    for(int i=0; i<n; i++){
        a[i] = random()%n + 1;
    }

    ListNode *p = createList(a, n);
    printList(p);
    printList(sortList(p));

    delete[] a;
    return 0;
}
