// Source : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Author : Hao Chen
// Date   : 2020-10-07

/***************************************************************************************************** 
 *
 * Given two non-negative integers low and high. Return the count of odd numbers between low and high 
 * (inclusive).
 * 
 * Example 1:
 * 
 * Input: low = 3, high = 7
 * Output: 3
 * Explanation: The odd numbers between 3 and 7 are [3,5,7].
 * 
 * Example 2:
 * 
 * Input: low = 8, high = 10
 * Output: 1
 * Explanation: The odd numbers between 8 and 10 are [9].
 * 
 * Constraints:
 * 
 * 	0 <= low <= high <= 10^9
 ******************************************************************************************************/

class Solution {
public:
    int countOdds1(int low, int high) {
        //remove the edge cases, make it as same pattern - both low and high are odd number.
        if  (high % 2 == 0) high--;
        if  (low % 2 == 0 ) low++;
        return (high-low)/2+1;
    }
    int countOdds2(int low, int high) {
        return (high+1)/2 - low/2;
    }
    int countOdds(int low, int high) {
        return countOdds2(low, high);
        return countOdds1(low, high);
    }
};
