package removeDuplicatesFromSortedListII;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 82. Remove Duplicates from Sorted List II
 *
 */
public class TestRemoveDuplicatesFromSortedListII {
	@Test
	public void test() {
		RemoveDuplicatesFromSortedListII solution = new RemoveDuplicatesFromSortedListII();
		int[] array1 = {1, 2, 3, 3, 4, 4, 5};
		ListNode head1 = ListNode.arrayToList(array1);
		ListNode newHead1 = solution.deleteDuplicates(head1);
		Assert.assertTrue(ListNode.listToString(newHead1).equals("1,2,5"));
		int[] array2 = {1, 1, 1, 2, 3};
		ListNode head2 = ListNode.arrayToList(array2);
		ListNode newHead2 = solution.deleteDuplicates(head2);
		Assert.assertTrue(ListNode.listToString(newHead2).equals("2,3"));
	}
}
