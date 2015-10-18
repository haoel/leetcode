// Source : https://oj.leetcode.com/problems/climbing-stairs/
// Inspired by : http://www.jiuzhang.com/solutions/climbing-stairs/
// Author : Lei Cao
// Date   : 2015-10-12

/**********************************************************************************
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 *
 **********************************************************************************/

package dynamicProgramming.climbStairs;

public class climbStairs {
    /**
     * @param n: An integer
     * @return: An integer
     */
    public int climbStairs(int n) {
        int[] matrix = new int[n];
        if (n < 3) {
            return n;
        }
        matrix[0] = 1;
        matrix[1] = 2;
        // write your code here
        for (int i = 2; i < matrix.length; i++) {
            matrix[i] = matrix[i-1] + matrix[i-2];
        }
        return matrix[n-1];
    }
}
