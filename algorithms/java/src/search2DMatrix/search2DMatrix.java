// Source : https://oj.leetcode.com/problems/search-a-2d-matrix/
// Inspired by : http://www.jiuzhang.com/solutions/search-a-2d-matrix/
// Author : Lei Cao
// Date   : 2015-10-03

/**********************************************************************************
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 *
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 *
 * Given target = 3, return true.
 *
 **********************************************************************************/

package search2DMatrix;

public class search2DMatrix {
    int rows = 0;
    int cols = 0;
    int[][] m;
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
            return false;
        }

        m = matrix;
        rows = matrix.length;
        cols = matrix[0].length;

        int start = 0;
        int end = rows * cols - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (getValue(mid) == target) {
                return true;
            } else if (getValue(mid) < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (getValue(start) == target) {
            return true;
        }
        if (getValue(end) == target) {
            return true;
        }
        return false;
    }

    /**
     * Get the value of the 2D matrix from the index
     * @param index
     * @return
     */
    private int getValue(int index) {
        return m[index / cols][index % cols];
    }
}
