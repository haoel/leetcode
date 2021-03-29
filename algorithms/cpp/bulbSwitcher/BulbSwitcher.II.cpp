// Source : https://leetcode.com/problems/bulb-switcher-ii/
// Author : Hao Chen
// Date   : 2021-03-29

/***************************************************************************************************** 
 *
 * There is a room with n lights which are turned on initially and 4 buttons on the wall. After 
 * performing exactly m unknown operations towards buttons, you need to return how many different 
 * kinds of status of the n lights could be.
 * 
 * Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given 
 * below:
 * 
 * 	Flip all the lights.
 * 	Flip lights with even numbers.
 * 	Flip lights with odd numbers.
 * 	Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
 * 
 * Example 1:
 * 
 * Input: n = 1, m = 1.
 * Output: 2
 * Explanation: Status can be: [on], [off]
 * 
 * Example 2:
 * 
 * Input: n = 2, m = 1.
 * Output: 3
 * Explanation: Status can be: [on, off], [off, on], [off, off]
 * 
 * Example 3:
 * 
 * Input: n = 3, m = 1.
 * Output: 4
 * Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
 * 
 * Note: n and m both fit in range [0, 1000].
 ******************************************************************************************************/

/*

We have 4 operations:

    1) Flip all the lights.
    2) Flip lights with even numbers.
    3) Flip lights with odd numbers.
    4) Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...

if we do 1) + 2), it's same as 3)
if we do 1) + 3), it's same as 2)
if we do 2) + 3), it's same as 1)
if we do 1) + 2) + 3), it's same as do nothing

So, we can manaully calculate how many different state we could have:

  m = 1, then 1), 2), 3), 4)   
  
  m = 2, then 1)+2), 1)+3), 1)+4), 2)+3), 2)+4), 3)+4) and  1)+1) => inital state
  
  m = 3, then 1), 2), 3), 4), 1)+4), 2+4), 3)+4),  and  1)+2)+3) => inital state

notice: 

    if m == 1,  we could only have 4 states at most.
    if m == 2,  we could only have 7 states at most. (no the 4) state) 
    if  m > 2,  we could only have 8 states at most. (has the 4) state)

But for some edge cases, we need to take care specially. For example:

 - m = 0 or n = 0, only 1 state.
 - n = 1, then 2 states.
 - n = 2, then it could have 3(when m=1), or 4 states (whem m>1)
 - n > 2 && m = 1, then it only could have 4 states.

*/

class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0 || n == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return m == 1? 3:4;
        if (m == 1) return 4;
        return m==2 ? 7 :8;
        
    }
};
