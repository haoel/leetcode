// Source : https://leetcode.com/problems/reverse-string/
// Author : Hao Chen
// Date   : 2016-05-29

/*************************************************************************************** 
 *
 * Write a function that takes a string as input and returns the string reversed.
 * 
 * Example:
 * Given s = "hello", return "olleh".
 ***************************************************************************************/

class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        for (int i=0; i<len/2; i++) {
           char ch = s[i];
           s[i] = s[len-i-1];
           s[len-i-1] = ch;
        } 
        return s;
    }
};
