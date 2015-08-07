// Source : https://oj.leetcode.com/problems/merge-k-sorted-lists/
// Author : Hao Chen
// Date   : 2014-07-06

/********************************************************************************** 
* 
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode* head1, ListNode* head2);
ListNode *mergeTwoLists01(ListNode* head1, ListNode* head2);
ListNode *mergeTwoLists02(ListNode* head1, ListNode* head2);

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *p, *p1, *p2;
    while(lists.size()>1){
        p1 = lists.back();    
        lists.pop_back();
        p2 = lists.back();    
        lists.pop_back();
        p = mergeTwoLists(p1, p2);
        lists.insert(lists.begin(), p);
    }
    return lists.size()==1 ? lists[0] : NULL;

    /* the following method is not fast enough! */
    /*
    ListNode* pHead = NULL;
    for (int i=0; i<lists.size(); i++){
        pHead = mergeTwoLists(pHead, lists[i]);
    }
    return pHead;
    */
}

static int n=0;
ListNode *mergeTwoLists(ListNode* head1, ListNode* head2){
    if (n){
        //cout << "------ method 01 ------" <<endl;
        return mergeTwoLists01(head1, head2);
    }
    //cout << "------ method 02 ------" <<endl;
    return mergeTwoLists02(head1, head2);
}
/*======================================================================*/
/*                            Method One                                */
/*======================================================================*/

//#define INT_MAX   2147483647
//#define INT_MIN   (-INT_MAX - 1)

ListNode *mergeTwoLists01(ListNode* head1, ListNode* head2){
    ListNode *p1 = head1,  *p2=head2;
    static ListNode dummy(0);

    dummy.next = p1;
    ListNode *prev = &dummy;

    while(p1 && p2){
        if(p1->val < p2->val){
            prev = p1;
            p1 = p1->next;
        }else{
            prev->next = p2;
            p2 = p2->next;
            prev = prev->next;
            prev->next = p1;
        }
    }
    if (p2){
        prev->next = p2;
    }

    return dummy.next;
}

/*======================================================================*/
/*                            Method Two                                */
/*======================================================================*/


void TakeOutNode(ListNode*& head, ListNode*& tail, ListNode*& p);

ListNode *mergeTwoLists02(ListNode* head1, ListNode* head2) {
    ListNode *p1 = head1,  *p2=head2;

    ListNode *pHead = NULL, *pTail=NULL;
    while(p1 && p2){
        if(p1->val < p2->val){
            TakeOutNode(pHead, pTail, p1);
        }else{
            TakeOutNode(pHead, pTail, p2);
        }
    }

    ListNode *p=NULL;
    if (p1){
        p = p1;
    }else if (p2){
        p = p2;
    }
    if (pHead==NULL){
        return p;
    }
    pTail->next = p;
    return pHead;
}

void TakeOutNode(ListNode*& head, ListNode*& tail, ListNode*& p){
    ListNode *pNext = p->next;
    if (head==NULL){
        head = tail = p;
    }else{
        tail->next = p;
        tail = p;
    }
    p->next = NULL;
    p = pNext;
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


int main(int argc, char**argv)
{
    srand(time(0));
    if (argc>1){
        n = atoi(argv[1]) % 2;
    }

    int a[] = {1,3,5,6,7,10};
    int b[] = {0,4,6,8,9,11,20,30,40};
    ListNode* p1 = createList(a, sizeof(a)/sizeof(int));
    ListNode* p2 = createList(b, sizeof(b)/sizeof(int));

    printList( mergeTwoLists(p1,p2) );
    //mergeTwoLists(p1,p2) ;


    vector<ListNode*> v;
    for(int i=0; i<10240; i++) {
        v.push_back(new ListNode(random()%100));
    }
    printList( mergeKLists(v) );
    //mergeKLists(v);


    cout << "method " << n+1 << endl;
    return 0;
}
