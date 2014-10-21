// Source : https://oj.leetcode.com/problems/merge-two-sorted-lists/
// Author : Hao Chen
// Date   : 2014-07-06

/********************************************************************************** 
* 
* Merge two sorted linked lists and return it as a new list. The new list should be 
* made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (random()%2){
            return mergeTwoLists01(l1, l2);
        }
        return mergeTwoLists02(l1, l2);
    }
    
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


    ListNode *mergeTwoLists02(ListNode *l1, ListNode *l2) {
        ListNode *l=NULL, *p=NULL;
        
        while (l1!=NULL && l2!=NULL ){
            ListNode *n=NULL;
            if (l1->val < l2-> val){
                n = l1;
                l1=l1->next;
            }else{
                n = l2;
                l2=l2->next;
            }
            if (l==NULL){
                l = p = n;
            }else{
                p->next = n;
                p = p->next;
            }
        }
        
        ListNode* rest = l1 ? l1 :l2;
        
        l = mergeTheRest(rest, l, p);
       
        
        return l;
    }
private:
    ListNode* mergeTheRest(ListNode* l, ListNode*head, ListNode* tail){
        if (l){
            if (head && tail ){
                tail->next = l;
            }else{
                head = l;
            }
        }
        return head;
    }
};
