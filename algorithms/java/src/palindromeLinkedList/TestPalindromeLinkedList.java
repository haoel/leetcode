package palindromeLinkedList;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 234. Palindrome Linked List
 * 
 */
public class TestPalindromeLinkedList {
	@Test
	public void test() {
		PalindromeLinkedList solution = new PalindromeLinkedList();
		int[] array1 = {1, 2, 3, 4, 3, 2, 1};
		ListNode head1 = ListNode.arrayToList(array1);
		Assert.assertTrue(solution.isPalindrome(head1));
		int[] array2 = {1, 2, 3, 3, 2, 1};
		ListNode head2 = ListNode.arrayToList(array2);
		Assert.assertTrue(solution.isPalindrome(head2));
		int[] array3 = {1, 2, 3, 4, 4, 2, 1};
		ListNode head3 = ListNode.arrayToList(array3);
		Assert.assertTrue(!solution.isPalindrome(head3));
	}
}
