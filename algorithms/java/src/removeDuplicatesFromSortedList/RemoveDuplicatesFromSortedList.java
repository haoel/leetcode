// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 * 
 **********************************************************************************/
package removeDuplicatesFromSortedList;

public class RemoveDuplicatesFromSortedList {
	public ListNode deleteDuplicates(ListNode head) {
		if (head == null) {
			return null;
		}
		ListNode pre = head;
		while (pre != null) {
			ListNode p = pre;
			while (p != null && p.val == pre.val) {
				p = p.next;
			}
			pre.next = p;
			pre = p;
		}
		return head;
	}
}
