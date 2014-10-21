// Source : https://oj.leetcode.com/problems/linked-list-cycle-ii/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
* 
* Follow up:
* Can you solve it without using extra space?
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
    
private:
    ListNode *p1, *p2;
public:
    bool hasCycle(ListNode *head) {
        
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
    
    ListNode *detectCycle(ListNode *head) {
        
        if (hasCycle(head)==false){
            return NULL;
        }
        
        p1 = head;
        
        while (p1!=p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};
