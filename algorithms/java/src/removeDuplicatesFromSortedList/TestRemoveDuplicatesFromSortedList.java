package removeDuplicatesFromSortedList;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 83. Remove Duplicates from Sorted List
 * 
 */
public class TestRemoveDuplicatesFromSortedList {
	@Test
	public void test() {
		RemoveDuplicatesFromSortedList solution = new RemoveDuplicatesFromSortedList();
		int[] array = {1, 1, 2, 3, 3};
		ListNode head = ListNode.arrayToList(array);
		ListNode newHead = solution.deleteDuplicates(head);
		Assert.assertTrue(ListNode.listToString(newHead).equals("1,2,3"));
	}
}
