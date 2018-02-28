package rotateList;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 61. Rotate List
 *
 */
public class TestRotateList {
@Test
public void test(){
	RotateList solution =new RotateList();
	int[] array1={1,2,3,4,5};
	ListNode head1=ListNode.arrayToList(array1);
	ListNode newHead1=solution.rotateRight(head1, 2);
	Assert.assertTrue(ListNode.listToString(newHead1).equals("4,5,1,2,3"));
	int[] array2={1,2,3,4,5,6};
	ListNode head2=ListNode.arrayToList(array2);
	ListNode newHead2=solution.rotateRight(head2, 22);
	Assert.assertTrue(ListNode.listToString(newHead2).equals("3,4,5,6,1,2"));
}
}
