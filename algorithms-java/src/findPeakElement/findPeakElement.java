// Source : https://oj.leetcode.com/problems/find-peak-element/
// Inspired by : http://www.jiuzhang.com/solutions/find-peak-element/
// Author : Lei Cao
// Date   : 2014-10-05

/**********************************************************************************
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 * click to show spoilers.
 *
 * Note:
 * Your solution should be in logarithmic complexity.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *
 **********************************************************************************/

package findPeakElement;

public class findPeakElement {
    public int findPeakElement(int[] nums) {
        if (nums.length == 0) {
            return Integer.MIN_VALUE;
        }

        int start = 0;
        int end = nums.length - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid - 1] < nums[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] > nums[end]) {
            return start;
        } else {
            return end;
        }
    }
}
