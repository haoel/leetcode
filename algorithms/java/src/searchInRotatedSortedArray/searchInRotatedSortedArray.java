// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
// Inspired by : http://www.jiuzhang.com/solutions/search-in-rotated-sorted-array/
// Author : Lei Cao
// Date   : 2015-10-03

/**********************************************************************************
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 **********************************************************************************/

package searchInRotatedSortedArray;

public class searchInRotatedSortedArray {
    /**
     * start [....1....] rotated pivot [....2...] end
     * @param nums
     * @param target
     * @return
     */
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return -1;
        }

        int start = 0;
        int end = nums.length - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[start] <= nums[mid]) { // in higher part
                if (nums[start] <= target && target <= nums[mid]) { // target within the start and mid.
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                if (nums[mid] <= target && target <= nums[nums.length -1]) { // target within the mid and the end
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }

        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        return -1;
    }
}
