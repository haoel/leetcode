// Source : https://leetcode.com/problems/largest-merge-of-two-strings/
// Author : Hao Chen
// Date   : 2021-02-11

/***************************************************************************************************** 
 *
 * You are given two strings word1 and word2. You want to construct a string merge in the following 
 * way: while either word1 or word2 are non-empty, choose one of the following options:
 * 
 * 	If word1 is non-empty, append the first character in word1 to merge and delete it from 
 * word1.
 * 
 * 		For example, if word1 = "abc" and merge = "dv", then after choosing this operation, 
 * word1 = "bc" and merge = "dva".
 * 
 * 	If word2 is non-empty, append the first character in word2 to merge and delete it from 
 * word2.
 * 
 * 		For example, if word2 = "abc" and merge = "", then after choosing this operation, 
 * word2 = "bc" and merge = "a".
 * 
 * Return the lexicographically largest merge you can construct.
 * 
 * A string a is lexicographically larger than a string b (of the same length) if in the first 
 * position where a and b differ, a has a character strictly larger than the corresponding character 
 * in b. For example, "abcd" is lexicographically larger than "abcc" because the first position they 
 * differ is at the fourth character, and d is greater than c.
 * 
 * Example 1:
 * 
 * Input: word1 = "cabaa", word2 = "bcaaa"
 * Output: "cbcabaaaaa"
 * Explanation: One way to get the lexicographically largest merge is:
 * - Take from word1: merge = "c", word1 = "abaa", word2 = "bcaaa"
 * - Take from word2: merge = "cb", word1 = "abaa", word2 = "caaa"
 * - Take from word2: merge = "cbc", word1 = "abaa", word2 = "aaa"
 * - Take from word1: merge = "cbca", word1 = "baa", word2 = "aaa"
 * - Take from word1: merge = "cbcab", word1 = "aa", word2 = "aaa"
 * - Append the remaining 5 a's from word1 and word2 at the end of merge.
 * 
 * Example 2:
 * 
 * Input: word1 = "abcabc", word2 = "abdcaba"
 * Output: "abdcabcabcaba"
 * 
 * Constraints:
 * 
 * 	1 <= word1.length, word2.length <= 3000
 * 	word1 and word2 consist only of lowercase English letters.
 ******************************************************************************************************/


class Solution {
private:
    bool string_cmp(string& s1, int p1, string& s2, int p2) {
        for (; p1 < s1.size() && p2 < s2.size() ; p1++, p2++) {
            if (s1[p1] == s2[p2]) continue;
            return s1[p1] > s2[p2];
        }
        return (s1.size() - p1 >  s2.size() - p2);
    }
public:
    string largestMerge(string word1, string word2) {
        int p1 = 0, p2 = 0;
        int len1 = word1.size(), len2 = word2.size();
        string merge(len1+len2, '\0');
        int p = 0;

        while (p1 < len1 && p2 < len2) {
            if ( string_cmp(word1, p1, word2, p2) ){ // take char from `word1`
                merge[p++] = word1[p1++];
            }else{ //take char from `word2`
                merge[p++] = word2[p2++];
            }
        }

        while (p1 < len1) merge[p++] = word1[p1++];
        while (p2 < len2) merge[p++] = word2[p2++];

        return merge;
    }
};
