// Source : https://oj.leetcode.com/problems/search-insert-position/
// Inspired by : http://www.jiuzhang.com/solutions/search-insert-position/
// Author : Lei Cao
// Date   : 2015-10-03

/**********************************************************************************
 *
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 *
 **********************************************************************************/

package searchInsertPosition;

public class searchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        int i = searchInsertI(nums, target);
        int j = searchInsertII(nums, target);
        if (i == j) {
            return i;
        }
        return -1;
    }

    // Find the first position >= target
    private int searchInsertI(int[] nums, int target) {
         if (nums == null || nums.length == 0) {
            return 0;
        }

        int start = 0;
        int end = nums.length - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] >= target) {
            return start;
        }
        if (nums[end] >= target) {
            return end;
        }
        return end + 1;
    }

    // Find the last position < target, return + 1
    // 1,2,3,5,6
    private int searchInsertII(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (target < nums[0]) {
            return 0;
        }

        int start = 0;
        int end = nums.length - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[end] == target) {
            return end;
        } else if (nums[end] < target) {
            return end + 1;
        } else if (nums[start] == target) {
            return start;
        }
        return start + 1;
    }
}
