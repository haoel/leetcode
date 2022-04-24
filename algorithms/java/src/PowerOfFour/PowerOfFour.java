// Source : https://leetcode.com/problems/power-of-four/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 24-04-2022

/***************************************************************************************************** 
 *
 * Given an integer n, return true if it is a power of four. Otherwise, return false.
 * 
 * An integer n is a power of four, if there exists an integer x such that n == 4x.
 *
 * Example 1:
 * 
 * Input: n = 16
 * Output: true
 * 
 * Example 2:
 *
 * Input: n = 5
 * Output: false
 * 
 * Example 3:
 * 
 * Input: n = 1
 * Output: true
 * 
 * Constraints:
 * 
 *  -2^31 <= n <= 2^31 - 1
 * 
 * Explanation of the solution:
 * 
 * After doing the log4(n), if the result have no decimal part, it means that 'n' is a power of four.
 ******************************************************************************************************/

class Solution {
    public boolean isPowerOfFour(int n) {
        double num = Math.log10(n) / Math.log10(4);
        if(num % 1 != 0) {
            return false;
        }
        return true;
    }
}
