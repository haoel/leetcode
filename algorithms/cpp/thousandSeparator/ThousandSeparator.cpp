// Source : https://leetcode.com/problems/thousand-separator/
// Author : Hao Chen
// Date   : 2020-10-03

/***************************************************************************************************** 
 *
 * Given an integer n, add a dot (".") as the thousands separator and return it in string format.
 * 
 * Example 1:
 * 
 * Input: n = 987
 * Output: "987"
 * 
 * Example 2:
 * 
 * Input: n = 1234
 * Output: "1.234"
 * 
 * Example 3:
 * 
 * Input: n = 123456789
 * Output: "123.456.789"
 * 
 * Example 4:
 * 
 * Input: n = 0
 * Output: "0"
 * 
 * Constraints:
 * 
 * 	0 <= n < 2^31
 ******************************************************************************************************/

class Solution {
public:
    string thousandSeparator(int n) {
        if (n==0) return "0";
        int cnt=0;
        string result;
        while( n > 0 ){
            int m = n % 10;
            result.insert(result.begin(),   ('0' + m) );
            cnt++;
            n /= 10;
            if (cnt % 3 == 0 && n > 0) {
                result = '.' + result;
            }

        }
        return result;
    }
};
