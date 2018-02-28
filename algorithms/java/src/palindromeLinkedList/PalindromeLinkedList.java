// Source : https://leetcode.com/problems/palindrome-linked-list/description/
// Author : Tianming Cao
// Date   : 2018-02-28

/**********************************************************************************
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 **********************************************************************************/
package palindromeLinkedList;

public class PalindromeLinkedList {
	private int lengthOfList(ListNode head) {
		int n = 0;
		while (head != null) {
			n++;
			head = head.next;
		}
		return n;
	}
	private ListNode reverseList(ListNode head) {
		ListNode pre = head;
		ListNode p = pre.next;
		while (p != null) {
			ListNode t = p.next;
			p.next = pre;
			pre = p;
			p = t;
		}
		head.next = null;
		return pre;
	}
	/**
	 * For example, the list is: 1->2->3->3->2->1
	 * 
	 * The algorithm has three steps:
	 * 
	 * 1. Get the length of linked list
	 * 
	 * 2. Reverse right-half, the list become: 1->2->3->1->2->3
	 * 
	 * 3. Use two pointers to judge if the left-half list equals to right-half list or not
	 * 
	 *     p1       p2
	 *     ↓        ↓
	 *     1->2->3->1->2->3
	 * 
	 * Notice: The even/odd of list's length
	 */
	public boolean isPalindrome(ListNode head) {
		int n = lengthOfList(head);
		if (n <= 1) {
			return true;
		}
		int evenFlag = 0;
		if ((n & 1) != 0) {
			evenFlag = 1;
		} else {
			evenFlag = 2;
		}
		int half = n / 2;
		ListNode p1 = head;
		for (int i = 1; i < half; i++) {
			p1 = p1.next;
		}
		ListNode p2 = p1.next;
		if (evenFlag == 1) {
			p2 = p2.next;
		}
		p2 = reverseList(p2);
		p1 = head;
		while (p2 != null) {
			if (p1.val != p2.val) {
				return false;
			}
			p1 = p1.next;
			p2 = p2.next;
		}
		return true;
	}
}
