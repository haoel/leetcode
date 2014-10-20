// Source : https://oj.leetcode.com/problems/rotate-list/
// Author : Hao Chen
// Date   : 2014-06-20

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k<=0){
            return head;
        }
        
        ListNode *p1, *p2=head;
        for(int i=0; i<k; i++){
            if (p2->next!=NULL){
                p2 = p2->next;  
            } else {
                //Shit! the K also rotated!
                p2 = head;
            }
        }
        
        for(p1=head; p2->next!=NULL; p1=p1->next, p2=p2->next);
        
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        
        return head;
            
    }
};
