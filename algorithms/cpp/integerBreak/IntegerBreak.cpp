// Source : https://leetcode.com/problems/integer-break/
// Author : Hao Chen
// Date   : 2016-05-29

/*************************************************************************************** 
 *
 * Given a positive integer n, break it into the sum of at least two positive integers 
 * and maximize the product of those integers. Return the maximum product you can get.
 * 
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 
 * + 4).
 * 
 * Note: you may assume that n is not less than 2.
 * 
 *   There is a simple O(n) solution to this problem.
 *   You may check the breaking results of n ranging from 7 to 10 to discover the 
 * regularities.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 ***************************************************************************************/

class Solution {
public:
    // As the hint said, checking the n with ranging from 7 to 10 to discover the regularities.
    // n = 7,    3*4 = 12
    // n = 8,  3*3*2 = 18
    // n = 9,  3*3*3 = 27
    // n = 10, 3*3*4 = 36
    // n = 11, 3*3*3*2 = 54
    //
    // we can see we can break the number by 3 if it is greater than 4;
    //
    int integerBreak(int n) {
        if ( n == 2 ) return 1;
        if ( n == 3 ) return 2;
        int result = 1;
        while( n > 4 ) {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};

