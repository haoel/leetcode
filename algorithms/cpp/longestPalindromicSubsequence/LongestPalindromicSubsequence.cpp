// Source : https://leetcode.com/problems/longest-palindromic-subsequence/
// Author : Hao Chen
// Date   : 2021-03-27

/***************************************************************************************************** 
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * 
 * A subsequence is a sequence that can be derived from another sequence by deleting some or no 
 * elements without changing the order of the remaining elements.
 * 
 * Example 1:
 * 
 * Input: s = "bbbab"
 * Output: 4
 * Explanation: One possible longest palindromic subsequence is "bbbb".
 * 
 * Example 2:
 * 
 * Input: s = "cbbd"
 * Output: 2
 * Explanation: One possible longest palindromic subsequence is "bb".
 * 
 * Constraints:
 * 
 * 	1 <= s.length <= 1000
 * 	s consists only of lowercase English letters.
 ******************************************************************************************************/

/*

   supposed s = "abbcba"
   
   we can have a matrix, 
  
   - dp[start, end] is the longest from s[start] to s[end]
  
   - if (start == end) dp[statr, end] = 1, it means every char can be palindromic
  
            a b b c b a
         a  1 0 0 0 0 0  
         b  0 1 0 0 0 0 
         b  0 0 1 0 0 0
         c  0 0 0 1 0 0
         b  0 0 0 0 1 0
         a  0 0 0 0 0 1 
  
  
  
  calculating from the bottom to up. (Note: only care about the top-right trangle)
  
            a  b  b  c  b  a
         a  1  1  2  2  3 [5]  <--  a == a , so "abbcba" comes from "bbcb" + 2 
         b  0  1 [2] 2  3  3   <--  b == b , so "bb" comes from "" + 2
         b  0  0  1  1 [3] 3   <--  b == b , so "bcb" comes from "c" + 2 
         c  0  0  0  1  1 [1]  <--  c != a , so "cba" comes from max("cb", "a") 
         b  0  0  0  0  1 [1]  <--  b != a , so "ba" comes from max ("b", "a")
         a  0  0  0  0  0  1 
         
  So, we can have the following formular:
  
       s[start] != s[end]  ==> dp[start, end] = max (dp[start+1, end], dp[start, end-1]);
       s[start] == s[end]  ==> dp[start, end] = dp[start+1, end-1] + 2;

*/


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(); 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int start = n-1; start>=0; start--) {
            for (int end = start ; end < n ; end++) {
                if (start == end) {
                    dp[start][end] = 1;
                    continue;
                }
                if (s[start] == s[end]) {
                    dp[start][end] = dp[start+1][end-1] + 2;
                }else{
                     dp[start][end] = max (dp[start+1][end], dp[start][end-1]);
                }
                
            }
        }
        return dp[0][n-1];
    }
};
