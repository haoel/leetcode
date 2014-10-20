// Source : https://oj.leetcode.com/problems/linked-list-cycle/
// Author : Hao Chen
// Date   : 2014-07-03


bool hasCycle(ListNode *head) {
    ListNode* p1;
    ListNode* p2;

    if (head==NULL) return false;
    p1=head;
    p2=head;

    while (p1!=NULL && p2!=NULL){

        p1=p1->next;

        if (p2->next == NULL) return false;

        p2=p2->next->next;

        if (p1==p2) return true;
    }

    return false;

}  
