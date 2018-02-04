// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Author : Tianming Cao
// Date   : 2018-02-02

/**********************************************************************************
 * Implement the following operations of a stack using queues.

 * Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

 * Do not allocate extra space for another array, 
 * you must do this by modifying the input array in-place with O(1) extra memory.

 * Example:

 * 	Given nums = [1,1,2],

 * 	Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * 	It doesn't matter what you leave beyond the new length.
 * 
 **********************************************************************************/
package removeDuplicatesFromSortedArray;

public class RemoveDuplicatesFromSortedArray {
	public int removeDuplicates(int[] nums) {
		if (nums == null || nums.length == 0) {
			return 0;
		}
		int n = nums.length;
		int len = 0;
		for (int i = 1; i < n; i++) {
			if (nums[i] != nums[len]) {
				nums[len + 1] = nums[i];
				len++;
			}
		}
		return len + 1;
	}
}
