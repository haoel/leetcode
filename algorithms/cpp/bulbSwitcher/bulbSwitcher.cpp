// Source : https://leetcode.com/problems/bulb-switcher/
// Author : Calinescu Valentin, Hao Chen
// Date   : 2015-12-28

/*************************************************************************************** 
 *
 * There are n bulbs that are initially off. You first turn on all the bulbs. Then, you
 * turn off every second bulb. On the third round, you toggle every third bulb (turning
 * on if it's off or turning off if it's on). For the nth round, you only toggle the
 * last bulb. Find how many bulbs are on after n rounds.
 * 
 * Example:
 * 
 * Given n = 3. 
 * 
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off]. 
 * 
 * So you should return 1, because there is only one bulb is on.
 * 
 ***************************************************************************************/

 /* Solution
  * --------
  *
  * We know, 
  *   - if a bulb can be switched to ON eventually, it must be switched by ODD times
  *   - Otherwise, if a bulb has been switched by EVEN times, it will be OFF eventually.
  * So, 
  *   - If bulb `i` ends up ON if and only if `i` has an ODD numbers of divisors.
  * And we know, 
  *   - the divisors come in pairs. for example: 
  *     12 - [1,12] [2,6] [3,4] [6,2] [12,1] (the 12th bulb would be switched by 1,2,3,4,6,12)
  *   - the pairs means almost all of the numbers are switched by EVEN times.
  *
  * But we have a special case - square numbers
  *   - A square number must have a divisors pair with same number. such as 4 - [2,2], 9 - [3,3]
  *   - So, a square number has a ODD numbers of divisors.
  *
  * At last, we figure out the solution is: 
  *    
  *    Count the number of the squre numbers!! 
  */

class Solution {
public:
    int bulbSwitch(int n) {
        int cnt = 0;
        for (int i=1; i*i<=n; i++) { 
            cnt++;
        }
        return cnt;
    }
};



 /* 
 * Solution 1 - O(1)
 * =========
 *
 * We notice that for every light bulb on position i there will be one toggle for every
 * one of its divisors, given that you toggle all of the multiples of one number. The 
 * total number of toggles is irrelevant, because there are only 2 possible positions(on, 
 * off). We quickly find that 2 toggles cancel each other so given that the start position
 * is always off a light bulb will be in if it has been toggled an odd number of times.
 * The only integers with an odd number of divisors are perfect squares(because the square
 * root only appears once, not like the other divisors that form pairs). The problem comes
 * down to finding the number of perfect squares <= n. That number is the integer part of
 * the square root of n.
 * 
 */
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
