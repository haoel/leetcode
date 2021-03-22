// Source : https://oj.leetcode.com/problems/merge-sorted-array/
// Author : Harvey Cao
// Date   : 2021-03-22

/********************************************************************************** 
* 21 
* Merge two sorted linked lists and return it as a sorted list. The list should be 
* made by splicing together the nodes of the first two lists.
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    function merge(n1, n2) {
        if (!n1 || !n2) return n1 || n2;
        if (n1.val < n2.val) {
            n1.next = merge(n1.next, n2);
            return n1;
        } else {
            n2.next = merge(n1, n2.next);
            return n2;           
        }
    }
    return merge(l1, l2);
};