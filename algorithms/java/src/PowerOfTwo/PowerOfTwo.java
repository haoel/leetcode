// Source : https://leetcode.com/problems/power-of-two/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 24-04-2022

/***************************************************************************************************** 
 *
 * Given an integer n, return true if it is a power of two. Otherwise, return false.
 * 
 * An integer n is a power of two, if there exists an integer x such that n == 2x.
 *
 * Example 1:
 * 
 * Input: n = 1
 * Output: true
 * Explanation: 2^0 = 1
 * 
 * Example 2:
 *
 * Input: n = 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * Input: n = 3
 * Output: false
 * 
 * Constraints:
 * 
 *  1 <= n <= 2^31 - 1
 * 
 * Explanation of the solution:
 * 
 * After doing the log2(n), if the result have no decimal part, it means that 'n' is a power of two.
 ******************************************************************************************************/

class Solution {
    public boolean isPowerOfTwo(int n) {
        double num =Math.log10(n)/ Math.log10(2);
        if(num % 1 != 0){
            return false;
        }
        return true;
    }
}
