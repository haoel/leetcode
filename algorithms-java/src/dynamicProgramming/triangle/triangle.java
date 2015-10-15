// Source : https://oj.leetcode.com/problems/triangle/
// Inspired by : http://www.jiuzhang.com/solutions/triangle/
// Author : Lei Cao
// Date   : 2015-10-12

/**********************************************************************************
 *
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 *
 *
 **********************************************************************************/

package dynamicProgramming.triangle;

import java.util.List;

/**
 * Created by leicao on 12/10/15.
 */
public class triangle {
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    public int minimumTotal1(List<List<Integer>> triangle) {
        if (triangle == null) {
            return 0;
        }
        int rows = triangle.size();
        int[][] matrix = new int[rows][rows];
        matrix[0][0] = triangle.get(0).get(0);
        for (int i = 1; i < rows; i++) {
            matrix[i][0] = triangle.get(i).get(0) + matrix[i-1][0];
        }

        for (int i = 1; i < rows; i++) {
            matrix[i][i] = triangle.get(i).get(i) + matrix[i - 1][i - 1];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < i; j++) {
                matrix[i][j] = Math.min(matrix[i-1][j-1], matrix[i-1][j]) + triangle.get(i).get(j);
            }
        }
        int minimum = matrix[rows - 1][0];
        for (int i = 1; i < rows; i++) {
            if (matrix[rows - 1][i] < minimum) {
                minimum = matrix[rows - 1][i];
            }
        }
        return minimum;
    }

    public int minimumTotal2(int[][] triangle) {
        if (triangle == null) {
            return 0;
        }
        int rows = triangle.length;
        int[][] matrix = new int[rows][rows];
        matrix[0][0] = triangle[0][0];
        for (int i = 1; i < rows; i++) {
            matrix[i][0] = triangle[i][0] + matrix[i-1][0];
        }

        for (int i = 1; i < rows; i++) {
            matrix[i][i] = triangle[i][i] + matrix[i - 1][i - 1];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < i; j++) {
                matrix[i][j] = Math.min(matrix[i-1][j-1], matrix[i-1][j]) + triangle[i][j];
            }
        }
        int minimum = matrix[rows - 1][0];
        for (int i = 1; i < rows; i++) {
            if (matrix[rows - 1][i] < minimum) {
                minimum = matrix[rows - 1][i];
            }
        }
        return minimum;
    }
}
