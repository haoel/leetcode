// Source : https://leetcode.com/problems/rotate-array/description/
// Author : Tianming Cao
// Date   : 2018-02-02

/**********************************************************************************
 * Rotate an array of n elements to the right by k steps.
 * 
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 * 
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * 
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * Related problem: Reverse Words in a String II
 * 
 **********************************************************************************/
package rotateArray;
/**********************************************************************************
 *
 * For example, with n = 9 and k = 4, the array is [1,2,3,4,5,6,7,8,9]
 * The train of thought is:
 *  1. Reverse 1-5 to [5,4,3,2,1]
 *  2. Reverse 6-9 to [9,8,7,6]
 *  3. Reverse the entire array [5,4,3,2,1,9,8,7,6] to [6,7,8,9,1,2,3,4,5]
 * It's a liner time and in-place algorithm
 * 
 **********************************************************************************/
public class RotateArray {

	public void rotate(int[] nums, int k) {
		//bounds check
		if (nums == null || nums.length == 0 || k == 0) {
			return;
		}
		int n = nums.length;
		//k may be larger than n
		k = k % n;
		rotateRange(0, n - k - 1, nums);
		rotateRange(n - k, n - 1, nums);
		rotateRange(0, n - 1, nums);
	}
	
	private void rotateRange(int start, int end, int[] array) {
		for (int i = start, j = end; i < j; i++, j--) {
			swap(array, i, j);
		}
	}
	private void swap(int[] array, int i, int j) {
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
	}
	
}
