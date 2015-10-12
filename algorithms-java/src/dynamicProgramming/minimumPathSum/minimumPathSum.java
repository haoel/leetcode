// Source : https://oj.leetcode.com/problems/minimum-path-sum/
// Inspired by : http://www.jiuzhang.com/solutions/minimum-path-sum/
// Author : Lei Cao
// Date   : 2015-10-12

/**********************************************************************************
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to
 * bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 **********************************************************************************/

package dynamicProgramming.minimumPathSum;

public class minimumPathSum {
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    public int minPathSum(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        int[][] matrix = new int[m][n];

        matrix[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            matrix[i][0] = grid[i][0] + matrix[i-1][0];
        }

        for (int i = 1; i < n; i++) {
            matrix[0][i] = grid[0][i] + matrix[0][i-1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = grid[i][j] + Math.min(matrix[i-1][j], matrix[i][j-1]);
            }
        }

        return matrix[m-1][n-1];
    }
}
