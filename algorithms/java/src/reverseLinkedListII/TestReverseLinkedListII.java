package reverseLinkedListII;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 92. Reverse Linked List II
 */
public class TestReverseLinkedListII {
	@Test
	public void test() {
		ReverseLinkedListII solution = new ReverseLinkedListII();
		int[] array1 = {1, 2, 3, 4, 5, 6, 7};
		ListNode head1 = ListNode.arrayToList(array1);
		ListNode newHead1 = solution.reverseBetween(head1, 3, 5);
		Assert.assertTrue(ListNode.listToString(newHead1).equals(
				"1,2,5,4,3,6,7"));
		int[] array2 = {7, 6, 5, 4, 3, 2, 1};
		ListNode head2 = ListNode.arrayToList(array2);
		ListNode newHead2 = solution.reverseBetween(head2, 1, 7);
		Assert.assertTrue(ListNode.listToString(newHead2).equals(
				"1,2,3,4,5,6,7"));
	}
}
