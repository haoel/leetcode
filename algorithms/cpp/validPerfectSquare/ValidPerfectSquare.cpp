// Source : https://leetcode.com/problems/valid-perfect-square/description/
// Author : Hao Chen
// Date   : 2018-06-26

/*************************************************************************************** 
 *
 * Given a positive integer num, write a function which returns True if num is a 
 * perfect square else False.
 * 
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * 
 * Input: 16
 * Returns: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 14
 * Returns: False
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/
class Solution {
public:
    // time limited error for  the MAX_INT.
    bool isPerfectSquare1(int num) {
        //binary searching...
        int left = 0, right = num;
        
        while (left <= right) {
            //cout << left << "," << right << endl;
            int mid = left + (right - left)/2;
            int n = mid * mid;
            if ( n == num) return true;
            if ( n < num ) left = mid + 1;
            else right = mid - 1;
        }
        
        return false; 
        
    }
    
    // the stupid way is best & fast.
    bool isPerfectSquare2(int num) {
        for (int i=1; i <= num/i ; i++ ) {
            if ( i*i == num) return true;
        }
        
        return false;
    }
    
    
    bool isPerfectSquare(int num) {
        return isPerfectSquare2(num);
        return isPerfectSquare1(num);
    }
    
};
