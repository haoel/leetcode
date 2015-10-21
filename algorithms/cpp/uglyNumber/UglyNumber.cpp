// Source : https://leetcode.com/problems/ugly-number/
// Author : Hao Chen
// Date   : 2015-10-21

/*************************************************************************************** 
 *
 * Write a program to check whether a given number is an ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For 
 * example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 * 
 * Note that 1 is typically treated as an ugly number.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 ***************************************************************************************/

class Solution {
public:
    //greeting algorithm
    bool isUgly(int num) {
        if ( num == 0 ) return false;
        if ( num == 1 ) return true;
        //becasue the 2,3,5 are prime numbers, so, we just simply remove each factors 
        //by keeping dividing them one by one 
        while ( num % 2 == 0 ) num /= 2;
        while ( num % 3 == 0 ) num /= 3;
        while ( num % 5 == 0 ) num /= 5;
        
        return num == 1;
    }
};

