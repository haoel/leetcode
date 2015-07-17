// Source : https://leetcode.com/problems/power-of-two/
// Author : Hao Chen
// Date   : 2015-07-16

/********************************************************************************** 
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 *               
 *               
 **********************************************************************************/


class Solution {
public:

    // count the number fo bits 1, if it only has one, then return true
    bool isPowerOfTwo01(int n) {
        int cnt = 0; //num of bits 1
        for(; n>0; n>>=1){
            if ( n & 1 ) {
                cnt++;
                if (cnt>1) return false;
            }
        }
        return cnt==1;
    }
    
    //we notice: 2^n - 1 always be 1111111...
    //so, (2^n) & (2^n-1) always be zero
    bool isPowerOfTwo02(int n) {
        return n<=0 ? false : (n & (n-1)) == 0;
    }
    
    bool isPowerOfTwo(int n) {
        if (random()%2){
            return isPowerOfTwo02(n);
        }
        return isPowerOfTwo01(n);
    }
};
