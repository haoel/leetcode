// Source : https://leetcode.com/problems/add-digits/
// Author : Timothy Lim
// Date   : 2015-10-1

/********************************************************************************** 

* Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
* For example:
* Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

**********************************************************************************/

class Solution {
public:
    int addDigits(int num) {
        return num - 9*((num-1)/9);
    }



/********************************************************************************** 

* Follow up:
* Could you do it without any loop/recursion in O(1) runtime?

**********************************************************************************/


    int addDigits_O1(int num) {
        while(num > 9) num = num / 10 + num % 10;
        return num;
    }
};
