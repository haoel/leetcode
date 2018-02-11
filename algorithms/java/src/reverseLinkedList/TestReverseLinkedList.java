package reverseLinkedList;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 206. Reverse Linked List
 */
public class TestReverseLinkedList {
	@Test
	public void test(){
		ReverseLinkedList solution=new ReverseLinkedList();
		int[] array1={1,2,3,4,5,6};
		ListNode head1=ListNode.arrayToList(array1);
		ListNode newHead1=solution.reverseList(head1);
		Assert.assertTrue(ListNode.listToString(newHead1).equals("6,5,4,3,2,1"));
		int[] array2={6,5,4,3,2,1};
		ListNode head2=ListNode.arrayToList(array2);
		ListNode newHead2=solution.reverseListRecursion(head2);
		Assert.assertTrue(ListNode.listToString(newHead2).equals("1,2,3,4,5,6"));
	}
}
