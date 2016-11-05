// Source : https://leetcode.com/problems/nth-digit/
// Author : Hao Chen
// Date   : 2016-11-05

/*************************************************************************************** 
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
 * 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n 31).
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which 
 * is part of the number 10.
 ***************************************************************************************/


#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        
        // We can see the following pattern:
        //
        // 1, 2, .... 9 : there are 9 * 1 digits.
        // 10, 11, ..., 99: there are 90 * 2 digits. 
        // 101, 102, 103, ..., 999:  there are 900 * 3.
        // ...
        
        
        //we can count the digits with the above pattern
        long digits_cnt = 0;
        long digits_cnt_prev = 0;
        int base = 0;
        for ( ; digits_cnt < n; base++) {
            digits_cnt_prev = digits_cnt;
            digits_cnt = digits_cnt +  9 * pow(10 , base) * ( base + 1 );
        }
        
        
        // Now, we got `digits_cnt_prev`, `digits_cnt` and `base`
        //
        //   For examples: 
        //      n = 20;    digits_cnt_prev = 9,            digits_cnt = 9+90*2 = 189,         base = 2;
        //      n = 500;   digits_cnt_prev = 9+90*2 = 189, digits_cnt = 9+90*2+900*3 = 2889,  base = 3;
        //      n = 2000;  digits_cnt_prev = 9+90*2 = 189, digits_cnt = 9+90*2+900*3 = 2889,  base = 3;
        //
        // It means, we found the range where the number it is
        //     n = 20,  the number located in the range 10 -- 99
        //     n = 500, the number located in the range 100 - 999
        //
        // and we can use `digits_cnt_prev` to know the previous rangs produce how many digits.
        //     n = 20, the previous ranges produce 9 digits, so there needs 20-9 = 11 digits in [10 - 99]
        //     n = 500, the previous ranges produce 189 digits, so there needs 500-189 = 311 digits in [100-999]
        // 
        // the `base` told us in current ranges, each number can have how many digits.
        // then we can locate the target number.
        //     n = 20, 
        //       (n - digits_cnt_prev) / base = (20 - 9 ) / 2 = 5, so, [10 - 14] produces 10 digits (ZERO-based),
        //       now, we have 1 digits left, it is the first digit of the target number 15.
        //
        //     n = 500, 
        //       (n - digits_cnt_prev) / base = (500 - 189) / 3 = 103, so, [100 - 202] produces 309 digits(ZERO-based).
        //       now, we have (500 - 189 - 309) = 2 digits left, it is the second digit of the target number 203.
        //
        // We can write the code now... 
        //
        int target = pow(10, base-1) + (n - digits_cnt_prev) / base - 1;
        int left = n - digits_cnt_prev - (n - digits_cnt_prev) / base * base;
        
        //cout << "target = " << target <<  ", left = " << left << endl;
        
        //no digits left
        if ( left == 0 ) return (target) % 10;
        
        //still have some digits left, it should be in next number.
        target++;
        return int( target / pow(10, base - left) ) % 10;
    }
};
