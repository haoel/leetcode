// Source : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Author : Hao Chen
// Date   : 2019-01-30

/***************************************************************************************************** 
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
 * 
 * Example 1:
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
 * 
 * Example 2:
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
 * At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which 
 * are higher.
 * 
 * Note:
 * 0 .
 * All elements of each string will have an ASCII value in [97, 122]. 
 ******************************************************************************************************/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // Dynamic Programm - simlar with : Edit Distance
        vector < vector <int> > dp ( s1.size()+1, vector<int>( s2.size()+1, 0) );

        // s1 is row, s2 is column
        for (int i=1; i<=s2.size(); i++) dp[0][i] = dp[0][i-1] + s2[i-1];
        for (int i=1; i<=s1.size(); i++) dp[i][0] = dp[i-1][0] + s1[i-1];

        for (int i=1; i<=s1.size(); i++){
            for (int j=1; j<=s2.size(); j++) {
                if ( s1[i-1] == s2[j-1] ) {
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }

        return dp[s1.size()][s2.size()];

    }
};
