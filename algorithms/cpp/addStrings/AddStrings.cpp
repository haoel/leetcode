// Source : https://leetcode.com/problems/add-strings/
// Author : Hao Chen
// Date   : 2016-11-12

/*************************************************************************************** 
 *
 * Given two non-negative numbers num1 and num2 represented as string, return the sum 
 * of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is 
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer 
 * directly.
 ***************************************************************************************/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string& longstr  = ( num1.size() >= num2.size() ? num1 : num2 );
        string& shortstr = ( num1.size() <  num2.size() ? num1 : num2 );
        
        int longlen = longstr.size();
        int shortlen = shortstr.size();
        
        char carry = 0;
        int i, j;
        
        string result;
        for (i = longlen-1, j=shortlen-1; i>=0; i--, j--) {
            int add = 0;
            if (j>=0) {
                add = longstr[i] + shortstr[j] - 2 * '0' + carry;
            }else{
                add = longstr[i] - '0' + carry;
            }
            carry = add/10;
            result = char('0' + add % 10) + result;
        }
        
        if (carry) {
            result = '1' + result;
        }
        return result;
    }
};
