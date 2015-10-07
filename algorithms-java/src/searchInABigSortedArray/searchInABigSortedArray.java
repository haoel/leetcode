// Source : http://www.lintcode.com/en/problem/search-in-a-big-sorted-array/
// Inspired by : http://www.jiuzhang.com/solutions/search-in-a-big-sorted-array/
// Author : Lei Cao
// Date   : 2015-10-05

/**********************************************************************************
 *
 * Given a big sorted array, find the first index of a target number. Your algorithm should be in O(log k), where k is the first index of the target number.
 *
 * Return -1, if the number doesn't exist in the array.
 *
 * Example
 * Given [1, 3, 6, 9, 21], and target = 3, return 1.
 *
 * Challenge
 * O(log k), k is the first index of the given target number.
 *
 **********************************************************************************/

package searchInABigSortedArray;

/**
 * Created by leicao on 5/10/15.
 */
public class searchInABigSortedArray {
    public int searchBigSortedArray(int[] A, int target) {
        if (A == null || A.length == 0) {
            return -1;
        }

        int start = 0;
        int end = A.length - 1;
        int upperBound = 1;

        // @TODO The logic here needs to be reviewed.
        for (int i = 0; i < Math.sqrt(A.length) + 1; i++) {
            if (upperBound < 0) {
                end = A.length - 1;
                break;
            }
            if (A.length > upperBound && A[upperBound] > target) {
                end = upperBound - 1;
                break;
            }
            upperBound = upperBound * 2;
        }

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                end = mid;
            } else if (A[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (A[start] == target) {
            return start;
        }
        if (A[end] == target) {
            return end;
        }

        return -1;
    }
}
