// Source : https://leetcode.com/problems/reorder-list/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You must do this in-place without altering the nodes' values.
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 * 
 **********************************************************************************/
package reorderList;

public class ReorderList {
	private int lenOfList(ListNode head) {
		int n = 0;
		while (head != null) {
			n++;
			head = head.next;
		}
		return n;
	}
	private ListNode reverseList(ListNode head) {
		ListNode pre = head;
		ListNode p = head.next;
		while (p != null) {
			ListNode t = p.next;
			p.next = pre;
			pre = p;
			p = t;
		}
		head.next = null;
		return pre;
	}
	public void reorderList(ListNode head) {
		if (head == null || head.next == null) {
			return;
		}
		int n = lenOfList(head);
		int half = (n + 1) >>> 1;
		ListNode pre = head;
		for (int index = 1; index < half; index++) {
			pre = pre.next;
		}
		ListNode rightHead = pre.next;
		// reverse right-half
		ListNode right = reverseList(rightHead);
		pre.next = null;
		ListNode left = head;
		// use two pointers, like merge sort
		while (right != null) {
			ListNode p1 = left.next;
			ListNode p2 = right.next;
			left.next = right;
			right.next = p1;
			left = p1;
			right = p2;
		}
	}
}
