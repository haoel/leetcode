// Source : https://leetcode.com/problems/partition-list/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 * 
 **********************************************************************************/
package partitionList;

public class PartitionList {
	public ListNode partition(ListNode head, int x) {
		if (head == null) {
			return null;
		}
		ListNode leftHead = new ListNode(0);
		ListNode rightHead = new ListNode(0);
		ListNode leftTail = leftHead;
		ListNode rightTail = rightHead;
		ListNode p = head;
		while (p != null) {
			if (p.val < x) {
				leftTail.next = p;
				leftTail = p;
			} else {
				rightTail.next = p;
				rightTail = p;
			}
			p = p.next;
		}
		leftTail.next = rightHead.next;
		rightTail.next = null;
		return leftHead.next;
	}
}
