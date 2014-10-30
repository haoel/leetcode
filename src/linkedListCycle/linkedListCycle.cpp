// Source : https://oj.leetcode.com/problems/linked-list-cycle/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Given a linked list, determine if it has a cycle in it.
* 
* Follow up:
* Can you solve it without using extra space?
* 
*               
**********************************************************************************/

/*
 * if there is a cycle in the list, then we can use two pointers travers the list.
 *
 * one pointer traverse one step each time, another one traverse two steps each time.
 *
 * so, those two pointers meet together, that means there must be a cycle inside the list.
 */

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
