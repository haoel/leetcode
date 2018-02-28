// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 * 
 **********************************************************************************/
package removeDuplicatesFromSortedListII;

public class RemoveDuplicatesFromSortedListII {
	public ListNode deleteDuplicates(ListNode head) {
		ListNode defaultHead = new ListNode(0);
		defaultHead.next = head;
		ListNode first = defaultHead;
		ListNode pre = head;
		while (pre != null) {
			ListNode p = pre.next;
			if (p == null) {
				break;
			}
			if (p.val == pre.val) {
				while (p != null && p.val == pre.val) {
					p = p.next;
				}
				first.next = p;
				pre = p;
			} else {
				first = pre;
				pre = p;
			}
		}
		return defaultHead.next;
	}
}
