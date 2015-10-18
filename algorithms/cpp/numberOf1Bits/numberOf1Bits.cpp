// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : Hao Chen
// Date   : 2015-03-30

/********************************************************************************** 
* 
* Write a function that takes an unsigned integer and returns the number of ’1' bits it has 
* (also known as the Hamming weight).
* 
* For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, 
* so the function should return 3.
* 
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
*               
**********************************************************************************/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(;n>0; n/=2){
            if (n & 0x1) cnt++;
        }
        return cnt;
    }
};
