package swapNodesInPairs;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 24. Swap Nodes in Pairs
 *
 */
public class TestSwapNodeInPairs {
@Test
public void test(){
	SwapNodesInPairs solution=new SwapNodesInPairs();
	int[] array1={1,2,3,4,5,6};
	ListNode head1=ListNode.arrayToList(array1);
	ListNode newHead1=solution.swapPairs(head1);
	Assert.assertTrue(ListNode.listToString(newHead1).equals("2,1,4,3,6,5"));
	int[] array2={1,2,3,4,5,6,7};
	ListNode head2=ListNode.arrayToList(array2);
	ListNode newHead2=solution.swapPairs(head2);
	Assert.assertTrue(ListNode.listToString(newHead2).equals("2,1,4,3,6,5,7"));
}
}
