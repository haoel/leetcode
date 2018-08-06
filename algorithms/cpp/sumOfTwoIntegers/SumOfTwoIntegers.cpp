// Source : https://leetcode.com/problems/sum-of-two-integers/description/
// Author : Hao Chen
// Date   : 2018-06-25

/*************************************************************************************** 
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use the 
 * operator + and -.
 * 
 * Example:
 * Given a = 1 and b = 2, return 3.
 * 
 * 
 * Credits:Special thanks to @fujiaozhu for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

class Solution {
public:
    int getSum(int x, int y) {
        // Iterate till there is no carry  
        while (y != 0) {
            // carry now contains common 
            //set bits of x and y
            int carry = x & y;  

            // Sum of bits of x and y where at 
            //least one of the bits is not set
            x = x ^ y; 

            // Carry is shifted by one so that adding
            // it to x gives the required sum
            y = carry << 1;
        }
        return x;
    }
};

