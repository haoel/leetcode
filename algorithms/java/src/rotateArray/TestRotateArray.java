package rotateArray;

import java.util.Arrays;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 189. Rotate Array
 *
 */
public class TestRotateArray {
	@Test
	public void test() {
		RotateArray solution = new RotateArray();
		int[] array1 = {1, 2, 3, 4, 5, 6, 7};
		int k1 = 24;
		solution.rotate(array1, k1);
		int[] expectArray1 = {5, 6, 7, 1, 2, 3, 4};
		Assert.assertTrue(Arrays.equals(array1, expectArray1));
		int[] array2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		int k2 = 4;
		solution.rotate(array2, k2);
		int[] expectArray2 = {6, 7, 8, 9, 1, 2, 3, 4, 5};
		Assert.assertTrue(Arrays.equals(array2, expectArray2));
	}
}
