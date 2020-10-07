// Source : https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
// Author : Hao Chen
// Date   : 2020-10-07

/***************************************************************************************************** 
 *
 * You are given a string s, a split is called good if you can split s into 2 non-empty strings p and 
 * q where its concatenation is equal to s and the number of distinct letters in p and q are the same.
 * 
 * Return the number of good splits you can make in s.
 * 
 * Example 1:
 * 
 * Input: s = "aacaba"
 * Output: 2
 * Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
 * ("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
 * ("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
 * ("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good 
 * split).
 * ("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good 
 * split).
 * ("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
 * 
 * Example 2:
 * 
 * Input: s = "abcd"
 * Output: 1
 * Explanation: Split the string as follows ("ab", "cd").
 * 
 * Example 3:
 * 
 * Input: s = "aaaaa"
 * Output: 4
 * Explanation: All possible splits are good.
 * 
 * Example 4:
 * 
 * Input: s = "acbadbaada"
 * Output: 2
 * 
 * Constraints:
 * 
 * 	s contains only lowercase English letters.
 * 	1 <= s.length <= 10^5
 ******************************************************************************************************/
class Solution {
public:
    int numSplits(string s) {
        //just walk through the string from left side and right side, 
        //calculate the diffrent letters from both side.
        
        // `ldict` & `rdict` remember the letter occurs or not
        //vector bool is bit data structure
        const int max_chars= 256;
        vector<bool> ldict(max_chars, false), rdict(max_chars, false);
        
        // `lstat` & `rstat` are used to record the different letters.
        // `lstat` is used from left side walk through
        // `rstat` is used from right side walk through 
        int len = s.size();
        vector<int> lstat(len, 0), rstat(len, 0);
        
        int lcnt=0, rcnt=0;
        
        for (int i=0; i<len; i++) {
            char lc = s[i];
            char rc = s[len-i-1];
            
            if (ldict[lc] == false) {
                lcnt++;
                ldict[lc] = true;
            }
            
            if (rdict[rc] == false) {
                rcnt++;
                rdict[rc] = true;
            }
            
            lstat[i] = lcnt;
            rstat[len-i-1] = rcnt;
        }
        
        
        int cnt = 0;
        for (int i=1; i<len; i++){
            if (lstat[i-1] == rstat[i]) {
                cnt++;
            }
        }
        
        return cnt;
        
    }
};
