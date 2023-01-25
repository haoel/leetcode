package Solution;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 58. Length of Last Word
 */
public class TestLengthOfLastWord {
	@Test
	public void test() {
		Solution solution = new Solution();
		int[] array1 = [2,2,1];
		Assert.assertTrue(solution.SingleNumber(array1) == 1);
		int[] array2 = [4,1,2,1,2];
		Assert.assertTrue(solution.SingleNumber(array2) == 4);
        int[] array3 = [1];
		Assert.assertTrue(solution.SingleNumber(array3) == 1);

	}
}
