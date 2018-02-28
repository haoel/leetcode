package removeLinkedListElements;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 203. Remove Linked List Elements
 */
public class TestRemoveLinkedListElements {
	@Test
	public void test() {
		RemoveLinkedListElements solution = new RemoveLinkedListElements();
		int[] array1 = {1, 2, 6, 3, 4, 5, 6};
		ListNode head1 = ListNode.arrayToList(array1);
		ListNode newHead1 = solution.removeElements(head1, 1);
		Assert.assertTrue(ListNode.listToString(newHead1).equals("2,6,3,4,5,6"));
		int[] array2 = {1, 2, 6, 3, 4, 5, 6};
		ListNode head2 = ListNode.arrayToList(array2);
		ListNode newHead2 = solution.removeElements(head2, 6);
		Assert.assertTrue(ListNode.listToString(newHead2).equals("1,2,3,4,5"));
	}
}
