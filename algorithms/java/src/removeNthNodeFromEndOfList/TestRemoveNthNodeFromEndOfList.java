package removeNthNodeFromEndOfList;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 19. Remove Nth Node From End of List
 */
public class TestRemoveNthNodeFromEndOfList {
	@Test
	public void test() {
	
		RemoveNthNodeFromEndOfList solution = new RemoveNthNodeFromEndOfList();
		int[] array1 = {1, 2, 3, 4, 5, 6};
		ListNode head1 = ListNode.arrayToList(array1);
		ListNode newHead1 = solution.removeNthFromEnd(head1, 2);
		Assert.assertTrue(ListNode.listToString(newHead1).equals("1,2,3,4,6"));
		int[] array2 = {1, 2, 3, 4, 5, 6};
		ListNode head2 = ListNode.arrayToList(array2);
		ListNode newHead2 = solution.removeNthFromEnd(head2, 6);
		Assert.assertTrue(ListNode.listToString(newHead2).equals("2,3,4,5,6"));
	}
}
