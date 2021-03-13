// Source : https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
// Author : Hao Chen
// Date   : 2021-03-13

/***************************************************************************************************** 
 *
 * Given an integer n, return true if it is possible to represent n as the sum of distinct powers of 
 * three. Otherwise, return false.
 * 
 * An integer y is a power of three if there exists an integer x such that y == 3x.
 * 
 * Example 1:
 * 
 * Input: n = 12
 * Output: true
 * Explanation: 12 = 31 + 32
 * 
 * Example 2:
 * 
 * Input: n = 91
 * Output: true
 * Explanation: 91 = 30 + 32 + 34
 * 
 * Example 3:
 * 
 * Input: n = 21
 * Output: false
 * 
 * Constraints:
 * 
 * 	1 <= n <= 107
 ******************************************************************************************************/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        return checkPowersOfThree_Base3(n);
        return checkPowersOfThree_DFS(n, 1);
    }
    
    bool checkPowersOfThree_DFS(int n, int p) { 
        if (n == p ) return true;
        if (n < p ) return false;
        
        return (checkPowersOfThree_DFS(n-p, p*3) || checkPowersOfThree_DFS(n, p*3));
    }
    /*
     * convert base-10 number to base-3 number
     * for example: 
     *    12 ->  110 = 1*3^2 + 1*3^1 + 0*3^0
     *    16 ->  121 = 1*3^2 + 2*3^1 + 1*3^0
     *    21 ->  210 = 2*3^2 + 1*3^1 + 0*3^0
     *    
     *    91 -> 1011 = 1*3^4 + 0*3^2 + 1*3^1 + 1*3^0
     *    
     * so, we can see, if a base3 number only has 1 or 0, then it's valid.
     * if `2` appeas, then it's invalid.
     */
    bool checkPowersOfThree_Base3(int n) { 
        for (; n>0; n/=3) {
            if (n%3 == 2) return false;
        }
        return true;
    }
};
