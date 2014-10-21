// Source : https://oj.leetcode.com/problems/swap-nodes-in-pairs/
// Author : Hao Chen
// Date   : 2014-06-22

/********************************************************************************** 
* 
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
* 
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    Solution(){
        srand(time(NULL));
    }
    ListNode *swapPairs(ListNode *head) {
        if(random()%2){
            return swapPairs1(head);
        }
        return swapPairs2(head);
    }
    ListNode *swapPairs1(ListNode *head) {
        for (ListNode *p = head; p && p->next; p = p->next->next) {
            int n = p->val;
            p->val = p->next->val;
            p->next->val = n;
        }
        return head;
    }
    
    ListNode *swapPairs2(ListNode *head) {
        ListNode *h = NULL;
        for (ListNode *p = head; p && p->next; p = p->next) {
            ListNode *n = p->next;
            p->next = n->next;
            n->next = p;
            if (h){
                h->next = n;
            }
            h=p;
            
            if (head == p){
                head = n;
            }
        }
        
        return head;
    }
};
