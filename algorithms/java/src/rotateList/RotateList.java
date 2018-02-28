// Source : https://leetcode.com/problems/rotate-list/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * 
 * Example:
 * 
 *  Given 1->2->3->4->5->NULL and k = 2,
 * 
 *  return 4->5->1->2->3->NULL.
 * 
 **********************************************************************************/
package rotateList;

public class RotateList {
	private int lengthOfList(ListNode head) {
		int n = 0;
		while (head != null) {
			n++;
			head = head.next;
		}
		return n;
	}
	private ListNode getNth(ListNode head, int k) {
		ListNode p = head;
		for (int index = 1; index < k; index++) {
			p = p.next;
		}
		return p;
	}
	private ListNode getLast(ListNode head) {
		while (head.next != null) {
			head = head.next;
		}
		return head;
	}
	public ListNode rotateRight(ListNode head, int k) {
		int n = lengthOfList(head);
		if (n <= 1) {
			return head;
		}
		// k may be greater than the length of list
		k = k % n;
		if (k == 0) {
			return head;
		}
		ListNode p1 = getNth(head, n - k);
		ListNode p2 = p1.next;
		ListNode last = getLast(p2);
		p1.next = null;
		last.next = head;
		return p2;
	}
}
