// Source : https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Inspired by : http://www.jiuzhang.com/solutions/find-minimum-in-rotated-sorted-array/
// Author : Lei Cao
// Date   : 2014-10-05

/**********************************************************************************
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 **********************************************************************************/

package findMinimumInRotatedSortedArray;

public class findMinimumInRotatedSortedArray {
    public int findMin(int[] num) {
        if (num == null || num.length == 0) {
            return Integer.MIN_VALUE;
        }

        int start = 0;
        int end = num.length - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (num[start] < num[end]) {
                end = mid;
            } else if (num[start] < num[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (num[start] < num[end]) {
            return num[start];
        } else {
            return num[end];
        }
    }
}
