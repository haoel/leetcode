// Source : https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 24-04-2022

/***************************************************************************************************** 
 *
 * Given an integer number n, return the difference between the product 
 * of its digits and the sum of its digits.
 * 
 * Example 1:
 * 
 * Input: n = 234
 * Output: 15 
 * Explanation:
 * Product of digits = 2 * 3 * 4 = 24 
 * Sum of digits = 2 + 3 + 4 = 9 
 * Result = 24 - 9 = 15
 * 
 * Example 2:
 *
 * Input: n = 4421
 * Output: 21
 * Explanation: 
 * Product of digits = 4 * 4 * 2 * 1 = 32 
 * Sum of digits = 4 + 4 + 2 + 1 = 11 
 * Result = 32 - 11 = 21
 * 
 * Constraints:
 * 
 *  1 <= n <= 10^5
 * 
 * Explanation of the solution:
 * 
 * 1. We analyze the String 'ns' char by char and we add and multiply both vatiables (product and sum) each time.
 * 
 * 2. We return the subtraction of it.
 ******************************************************************************************************/

class Solution {
    public int subtractProductAndSum(int n) {
        int prod = 1, sum = 0,act;
        String ns = String.valueOf(n);
        for(int i = 0; i < ns.length(); i++){
            act = Integer.parseInt(String.valueOf(ns.charAt(i)));
            prod *= act;
            sum += act;
        }
        return prod-sum;
    }
}
