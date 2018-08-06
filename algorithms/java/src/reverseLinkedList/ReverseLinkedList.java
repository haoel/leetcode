// Source : https://leetcode.com/problems/reverse-linked-list/description/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Reverse a singly linked list.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 **********************************************************************************/
package reverseLinkedList;

public class ReverseLinkedList {

	/**
	 * The iterative solution
	 */
	public ListNode reverseList(ListNode head) {
		if (head == null) {
			return head;
		}
		ListNode p = head;
		ListNode next = p.next;
		while (next != null) {
			ListNode temp = next.next;
			next.next = p;
			p = next;
			next = temp;
		}
		head.next = null;
		return p;
	}
	
	public ListNode reverseListRecursion(ListNode head) {
		if (head == null) {
			return head;
		}
		ListNode newHead = recursion(head);
		head.next = null;
		return newHead;
	}
	/**
	 * The recursive solution
	 */
	public ListNode recursion(ListNode p) {
		if (p.next == null) {
			return p;
		} else {
			ListNode next = p.next;
			ListNode newHead = recursion(next);
			next.next = p;
			return newHead;
		}
	}

}
