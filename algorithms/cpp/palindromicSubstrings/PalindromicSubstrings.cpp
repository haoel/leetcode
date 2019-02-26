// Source : https://leetcode.com/problems/palindromic-substrings/
// Author : Hao Chen
// Date   : 2019-01-30

/***************************************************************************************************** 
 *
 * 
 * Given a string, your task is to count how many palindromic substrings in this string.
 * 
 * The substrings with different start indexes or end indexes are counted as different substrings even 
 * they consist of same characters. 
 * 
 * Example 1:
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * Example 2:
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * Note:
 * 
 * The input string length won't exceed 1000.
 * 
 ******************************************************************************************************/
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        if (len<=1) return len;
        
        vector< vector<bool> > dp(len, vector<bool>(len, false));
        
        int cnt = 0;
        for( int i=len-1; i>=0; i--) {
            for (int j=i; j<=len-1; j++) {              
                if ( i == j  || ( s[i] == s[j] && ( j-i<2 || dp[i+1][j-1]) ) ) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
                                  
        return cnt;       
        
    }
};
