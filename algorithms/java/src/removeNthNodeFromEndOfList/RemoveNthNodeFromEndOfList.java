// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 *    Given linked list: 1->2->3->4->5, and n = 2.
 * 
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 **********************************************************************************/
package removeNthNodeFromEndOfList;

public class RemoveNthNodeFromEndOfList {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		if (head == null) {
			return null;
		}
		ListNode defaultHead = new ListNode(0);
		defaultHead.next = head;
		ListNode pre = findNth(defaultHead, n + 1);
		pre.next = pre.next.next;
		return defaultHead.next;
	}
	public ListNode findNth(ListNode head, int k) {
		ListNode p2 = head;
		for (int i = 1; i <= k; i++) {
			p2 = p2.next;
		}
		ListNode p = head;
		while (p2 != null) {
			p2 = p2.next;
			p = p.next;
		}
		return p;
	}
}
