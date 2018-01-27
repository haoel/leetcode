package searchA2DMatrixII;

import org.junit.Assert;
import org.junit.Test;
/**
 * Test for 240. Search a 2D Matrix II
 */
public class Test_240 {
	@Test
	public void test() {
		SearchA2DMatrixII solution = new SearchA2DMatrixII();
		int[][] matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
				{3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
		int target = 5;
		Assert.assertTrue(solution.searchMatrix(matrix, target));
		target = 20;
		Assert.assertTrue(!solution.searchMatrix(matrix, target));
	}
}
