// Source : https://leetcode.com/problems/detect-capital/
// Author : Hao Chen
// Date   : 2019-02-04

/***************************************************************************************************** 
 *
 * 
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 * 
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one letter, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 ******************************************************************************************************/
class Solution {
    bool is_lower(char ch) {
        return ch >='a' && ch <='z';
    }
    bool is_upper(char ch) {
        return ch >='A' && ch <='Z';
    }
    bool is_alpha(char ch) {
        return is_lower(ch) || is_upper(ch);
    }
public:
    bool detectCapitalUse(string word) {
        bool all_upper = true, all_lower = true, first = is_upper(word[0]);
        for(int i=1; i<word.size(); i++) {
            if (is_lower(word[i])) all_upper = false;
            if (is_upper(word[i])) all_lower = false;
        }
        return all_lower || first && all_upper; 
    }
};
