// Source : https://leetcode.com/problems/palindrome-linked-list/
// Author : Hao Chen
// Date   : 2015-07-17

/********************************************************************************** 
 * 
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    ListNode* findMiddle(ListNode* head) {
        ListNode *p1=head, *p2=head;
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    
    ListNode* reverseLink(ListNode* head) {
        ListNode* p=NULL;
        
        while (head) {
            ListNode* q = head->next;
            head->next = p;
            p = head;
            head = q;
        }
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* pMid = findMiddle(head);
        ListNode* pRev = reverseLink(pMid); 
        for(;head!=pMid; head=head->next, pRev=pRev->next) {
            if (head->val != pRev->val) {
                return false;
            }
        }
        return true;
    }
};


