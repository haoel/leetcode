// Source : https://leetcode.com/problems/remove-linked-list-elements/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 **********************************************************************************/
package removeLinkedListElements;

public class RemoveLinkedListElements {
	public ListNode removeElements(ListNode head, int val) {
		ListNode defaultHead = new ListNode(0);
		defaultHead.next = head;
		ListNode pre = defaultHead;
		ListNode p = head;
		while (p != null) {
			if (p.val == val) {
				pre.next = p.next;
			} else {
				pre = p;
			}
			p = pre.next;
		}
		return defaultHead.next;
	}
}
