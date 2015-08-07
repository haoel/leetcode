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
    if (head==NULL || head->next==NULL) return false;
    ListNode* fast=head;
    ListNode* slow=head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != NULL && fast->next != NULL && fast != slow);
    return fast == slow? true : false;
} 
