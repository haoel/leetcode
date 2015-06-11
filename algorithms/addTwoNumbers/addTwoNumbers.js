/****
 * Solution of https://leetcode.com/problems/add-two-numbers/
 * @author: Jerry Zou
 * @date: 2015.6.4
 **/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var current = new ListNode(0), //root
        result = current,
        carry = 0,
        val;

    while (l1 !== null || l2 !== null || carry) {
        val = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
        if (val >= 10) {
            val -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        current.next = new ListNode(val);
        l1 = l1 && l1.next;
        l2 = l2 && l2.next;
        current = current.next;
    }

    return result.next;
};