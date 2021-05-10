// Source : https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
// Author : Hao Chen
// Date   : 2021-03-27

/***************************************************************************************************** 
 *
 * You are given two strings, word1 and word2. You want to construct a string in the following manner:
 * 
 * 	Choose some non-empty subsequence subsequence1 from word1.
 * 	Choose some non-empty subsequence subsequence2 from word2.
 * 	Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
 * 
 * Return the length of the longest palindrome that can be constructed in the described manner. If no 
 * palindromes can be constructed, return 0.
 * 
 * A subsequence of a string s is a string that can be made by deleting some (possibly none) 
 * characters from s without changing the order of the remaining characters.
 * 
 * A palindrome is a string that reads the same forward as well as backward.
 * 
 * Example 1:
 * 
 * Input: word1 = "cacb", word2 = "cbba"
 * Output: 5
 * Explanation: Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.
 * 
 * Example 2:
 * 
 * Input: word1 = "ab", word2 = "ab"
 * Output: 3
 * Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.
 * 
 * Example 3:
 * 
 * Input: word1 = "aa", word2 = "bb"
 * Output: 0
 * Explanation: You cannot construct a palindrome from the described method, so return 0.
 * 
 * Constraints:
 * 
 * 	1 <= word1.length, word2.length <= 1000
 * 	word1 and word2 consist of lowercase English letters.
 ******************************************************************************************************/

/*
    // The basic algorthim come from
    // https://leetcode.com/problems/longest-palindromic-subsequence/
    
    int longestPalindromeSubseq(string& s) {
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
*/


class Solution {

public:
    int longestPalindrome(string word1, string word2) {
        
        string s = word1 + word2;
        int n = s.size(); 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int result = 0; 
        for (int start = n-1; start>=0; start--) {
            for (int end = start ; end < n ; end++) {
                if (start == end) {
                    dp[start][end] = 1;
                    continue;
                }
                if (s[start] == s[end]) {
                    dp[start][end] = dp[start+1][end-1] + 2;
                    // <-----------  different -----------> 
                    //only consider when `start` and `end` in different string.
                    if (start < word1.size() && end >= word1.size()){
                        result = max(result, dp[start][end]);
                    }
                    // <-----------  different -----------> 
                }else{
                     dp[start][end] = max (dp[start+1][end], dp[start][end-1]);
                }
                
            }
        }  
        return result;
    }
};
