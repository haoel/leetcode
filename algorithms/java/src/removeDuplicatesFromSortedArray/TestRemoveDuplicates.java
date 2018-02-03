package removeDuplicatesFromSortedArray;

import org.junit.Assert;
import org.junit.Test;

/**
 * Test for 26. Remove Duplicates from Sorted Array
 */
public class TestRemoveDuplicates {
	@Test
	public void test() {
		int[] nums1 = {0, 0, 0, 0, 0, 1, 2, 2, 3, 3, 4, 4};
		RemoveDuplicatesFromSortedArray solution = new RemoveDuplicatesFromSortedArray();
		int len1 = solution.removeDuplicates(nums1);
		Assert.assertTrue(len1 == 5);
		assertSorted(nums1, len1);
		int[] nums2 = {1, 2, 2, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8};
		int len2 = solution.removeDuplicates(nums2);
		Assert.assertTrue(len2 == 8);
		assertSorted(nums2, len2);
	}
	private void assertSorted(int[] array, int len) {
		for (int i = 0; i < len - 1; i++) {
			Assert.assertTrue(array[i] < array[i + 1]);
		}
	}
}
