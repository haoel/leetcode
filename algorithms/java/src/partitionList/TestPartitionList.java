package partitionList;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 86. Partition List
 * 
 */
public class TestPartitionList {
	@Test
	public void test() {
		PartitionList solution = new PartitionList();
		int[] array = {1, 4, 3, 2, 5, 2};
		ListNode head = ListNode.arrayToList(array);
		ListNode newHead = solution.partition(head, 3);
		Assert.assertTrue(ListNode.listToString(newHead).equals("1,2,2,4,3,5"));
	}
}
