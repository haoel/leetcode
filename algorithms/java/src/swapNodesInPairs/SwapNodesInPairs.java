// Source : https://leetcode.com/problems/swap-nodes-in-pairs/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Your algorithm should use only constant space. 
 * You may not modify the values in the list, only nodes itself can be changed.
 * 
 **********************************************************************************/
package swapNodesInPairs;

public class SwapNodesInPairs {
	public ListNode swapPairs(ListNode head) {
		if (head == null) {
			return head;
		}
		ListNode defaultHead = new ListNode(0);
		defaultHead.next = head;
		ListNode pre = defaultHead;
		ListNode p1 = defaultHead.next;
		ListNode p2 = p1.next;
		ListNode next = null;
		while (p2 != null) {
			next = p2.next;
			p2.next = p1;
			p1.next = next;
			pre.next = p2;
			pre = p1;
			p1 = next;
			if (p1 == null) {
				break;
			}
			p2 = p1.next;
		}
		return defaultHead.next;
	}
}
