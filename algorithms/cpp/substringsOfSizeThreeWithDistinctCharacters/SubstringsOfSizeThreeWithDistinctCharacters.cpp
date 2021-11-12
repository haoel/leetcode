// Source : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/submissions/
// Author : Hao Chen
// Date   : 2021-11-12

/***************************************************************************************************** 
 *
 * A string is good if there are no repeated characters.
 * 
 * Given a string s, return the number of good substrings of length three in s.
 * 
 * Note that if there are multiple occurrences of the same substring, every occurrence should be 
 * counted.
 * 
 * A substring is a contiguous sequence of characters in a string.
 * 
 * Example 1:
 * 
 * Input: s = "xyzzaz"
 * Output: 1
 * Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
 * The only good substring of length 3 is "xyz".
 * 
 * Example 2:
 * 
 * Input: s = "aababcabc"
 * Output: 4
 * Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
 * The good substrings are "abc", "bca", "cab", and "abc".
 * 
 * Constraints:
 * 
 * 	1 <= s.length <= 100
 * 	s consists of lowercase English letters.
 ******************************************************************************************************/

class Solution {
public:
    int countGoodSubstrings(string s) {
        char exist[26] = {0};
        
        int cnt = 0, c = 0;
        
        
        for (int i = 0; i<s.size(); i++){
            char ch = s[i] - 'a';
            
            if (i > 2) {
                char ch = s[i-3]-'a';
                exist[ch]--;
                if ( exist[ch] == 0 ) c--;
            }
            
            exist[ch]++;
            if (exist[ch] == 1 ) {
                c++;
            }
            
            if ( c == 3 ){
                cnt++;
            }
            

        }
        
        return cnt;
    }
};
