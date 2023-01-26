package Solution;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 66. Plus One
 */
public class PlusOne {
	@Test
	public void test() {
		Solution solution = new Solution();
		int[] array1 = [4,3,2,1];
		Assert.assertTrue(solution.PlusOne(array1) == [4,3,2,2]);
		int[] array2 = [1,2,3];
		Assert.assertTrue(solution.SingleNumber(array2) == [1,2,4]);
        int[] array3 = [9];
		Assert.assertTrue(solution.SingleNumber(array3) == [1,0]);

	}
}
