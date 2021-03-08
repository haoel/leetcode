// Source : https://leetcode.com/problems/longest-nice-substring/
// Author : Hao Chen
// Date   : 2021-03-08

/***************************************************************************************************** 
 *
 * A string s is nice if, for every letter of the alphabet that s contains, it appears both in 
 * uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' 
 * appear. However, "abA" is not because 'b' appears, but 'B' does not.
 * 
 * Given a string s, return the longest substring of s that is nice. If there are multiple, return the 
 * substring of the earliest occurrence. If there are none, return an empty string.
 * 
 * Example 1:
 * 
 * Input: s = "YazaAay"
 * Output: "aAa"
 * Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 
 * 'A' and 'a' appear.
 * "aAa" is the longest nice substring.
 * 
 * Example 2:
 * 
 * Input: s = "Bb"
 * Output: "Bb"
 * Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
 * 
 * Example 3:
 * 
 * Input: s = "c"
 * Output: ""
 * Explanation: There are no nice substrings.
 * 
 * Example 4:
 * 
 * Input: s = "dDzeE"
 * Output: "dD"
 * Explanation: Both "dD" and "eE" are the longest nice substrings.
 * As there are multiple longest nice substrings, return "dD" since it occurs earlier.
 * 
 * Constraints:
 * 
 * 	1 <= s.length <= 100
 * 	s consists of uppercase and lowercase English letters.
 ******************************************************************************************************/

class Solution {
    inline int getCharIndex(char c) {
        return  (c >='A' && c <='Z') ? c - 'A' : c - 'a';
    }
    inline int getCaseIndex(char c) {
         return (c >='A' && c <='Z') ? 1 : 0;
    }
public:
    string longestNiceSubstring(string s) {
        vector<bitset<26>> check(2);
        int start = 0, len = 0;
        for (int i = 0; i < s.size() -1; i++){
            for (int j = i+1; j < s.size(); j++) {
                
                check[0] = check[1] = 0;
                for (int x=i; x<=j; x++){
                    int i = getCaseIndex(s[x]);
                    int j = getCharIndex(s[x]);
                    check[i][j] = true;
                }
                
                if ( (check[0] ^ check[1]) == 0 ) {
                    if ( j - i + 1 > len ){
                        start = i;
                        len = j-i+1;
                    }
                }
            }
        }
        
        return s.substr(start, len);
    }
};
