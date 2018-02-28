package reorderList;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 143. Reorder List
 * 
 */
public class TestReorderList {
	@Test
	public void test() {
		ReorderList solution = new ReorderList();
		int[] array1 = {1, 2, 3, 4, 5, 6};
		ListNode head1 = ListNode.arrayToList(array1);
		solution.reorderList(head1);
		Assert.assertTrue(ListNode.listToString(head1).equals("1,6,2,5,3,4"));
		int[] array2 = {1, 2, 3, 4, 5};
		ListNode head2 = ListNode.arrayToList(array2);
		solution.reorderList(head2);
		Assert.assertTrue(ListNode.listToString(head2).equals("1,5,2,4,3"));
	}
}
