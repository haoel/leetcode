// Source : https://leetcode.com/problems/reverse-linked-list-ii/description/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 * 
 **********************************************************************************/
package reverseLinkedListII;

public class ReverseLinkedListII {
	public ListNode reverseBetween(ListNode head, int m, int n) {
		// Assume that the list is:[1,2,3,4,5,6,7] m=3 n=5
		if (head == null || m == n) {
			// bounds check
			return head;
		}
		// We'd better create a default head due to m may equals 1
		ListNode defaultHead = new ListNode(0);
		defaultHead.next = head;
		int index = 1;
		ListNode pre = defaultHead;
		while (index < m) {
			pre = pre.next;
			index++;
		}
		// pre is 2, first is 3
		ListNode first = pre.next;
		ListNode p = first;
		ListNode next = p.next;
		while (index < n) {
			ListNode t = next.next;
			next.next = p;
			p = next;
			next = t;
			index++;
		}
		// next is 6
		first.next = next;
		pre.next = p;
		return defaultHead.next;
	}
}
