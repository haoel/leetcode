// Source : https://leetcode.com/problems/power-of-three/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 24-04-2022

/***************************************************************************************************** 
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return false.
 * 
 * An integer n is a power of three, if there exists an integer x such that n == 3x.
 *
 * Example 1:
 * 
 * Input: n = 27
 * Output: true
 * 
 * Example 2:
 *
 * Input: n = 0
 * Output: false
 * 
 * Example 3:
 * 
 * Input: n = 9
 * Output: true
 * 
 * Constraints:
 * 
 *  -2^31 <= n <= 2^31 - 1
 * 
 * Explanation of the solution:
 * 
 * After doing the log3(n), if the result have no decimal part, it means that 'n' is a power of three.
 ******************************************************************************************************/

class Solution {
    public boolean isPowerOfThree(int n) {
        double num = Math.log10(n) / Math.log10(3);
        if(num % 1 != 0){
            return false;
        }
        return true;
    }
}
