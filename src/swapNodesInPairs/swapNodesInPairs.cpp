// Source : https://oj.leetcode.com/problems/swap-nodes-in-pairs/
// Author : Hao Chen
// Date   : 2014-06-22

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
