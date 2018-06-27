// Source : https://leetcode.com/problems/mirror-reflection/description/
// Author : Hao Chen
// Date   : 2018-06-27

/*************************************************************************************** 
 *
 * There is a special square room with mirrors on each of the four walls.  Except for 
 * the southwest corner, there are receptors on each of the remaining corners, numbered 
 * 0, 1, and 2.
 * 
 * The square room has walls of length p, and a laser ray from the southwest corner 
 * first meets the east wall at a distance q from the 0th receptor.
 * 
 * Return the number of the receptor that the ray meets first.  (It is guaranteed that 
 * the ray will meet a receptor eventually.)
 * 
 *  
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: p = 2, q = 1
 * Output: 2
 * Explanation: The ray meets receptor 2 the first time it gets reflected back to the 
 * left wall.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 	1 <= p <= 1000
 * 	0 <= q <= p
 * 
 ***************************************************************************************/

/*
 *  Solution 
 *  --------
 *  
 *  We know the following things:
 *  1）every reflection will increase the step of `q`.  
 *  2) when reach the top, the reflection would go down, when reach the bottom the reflection would go up.
 *  
 *  So, we can image if there have two walls, left one and right one, then the reflection can go up instanstly, 
 *
 *   - the reflection points on left wall would be even times of `q`.
 *   - the reflection points on right wall would be odd times of `q`.
 *
 *  And in the right wall, the receptors `#0` would be the times of `2p`.
 *
 *  So, we need find the least common multiple of `p` and `q`, then we can have the answer.    
 */


class Solution {
private:
    //GCD -  greatest common divisor  最大公因数
    int greatestCommonDivisor (int a, int b) {
        if(b) while((a %= b) && (b %= a));
        return a + b;
    }
    //LCM - least common multiple 最小公倍数
    int leastCommonMultiple(int a, int b) {
        return a * b / greatestCommonDivisor(a, b);
    }
public:
    int mirrorReflection(int p, int q) {
        int lcm = leastCommonMultiple(p, q);
        if (lcm % (2*p) == 0 ) return 0;
        
        int nq = lcm / q; 
        
        if (nq % 2 == 0 ) return 2;
        return 1;
    }
};

