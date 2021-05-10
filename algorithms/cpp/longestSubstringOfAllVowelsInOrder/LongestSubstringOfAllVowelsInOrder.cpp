// Source : https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
// Author : Hao Chen
// Date   : 2021-04-25

/***************************************************************************************************** 
 *
 * A string is considered beautiful if it satisfies the following conditions:
 * 
 * 	Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
 * 	The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's 
 * before 'i's, etc.).
 * 
 * For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", 
 * and "aaaeeeooo" are not beautiful.
 * 
 * Given a string word consisting of English vowels, return the length of the longest beautiful 
 * substring of word. If no such substring exists, return 0.
 * 
 * A substring is a contiguous sequence of characters in a string.
 * 
 * Example 1:
 * 
 * Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
 * Output: 13
 * Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
 * 
 * Example 2:
 * 
 * Input: word = "aeeeiiiioooauuuaeiou"
 * Output: 5
 * Explanation: The longest beautiful substring in word is "aeiou" of length 5.
 * 
 * Example 3:
 * 
 * Input: word = "a"
 * Output: 0
 * Explanation: There is no beautiful substring, so return 0.
 * 
 * Constraints:
 * 
 * 	1 <= word.length <= 5 * 10^5
 * 	word consists of characters 'a', 'e', 'i', 'o', and 'u'.
 ******************************************************************************************************/

class Solution {
private:
    enum Vowels{
        A = 0,
        E = 1,
        I = 2,
        O = 3,
        U = 4,
        INVAILD = -1,
    };
    
    Vowels isVowels(char c) {
        switch(c) {
            case 'a' : return A;
            case 'e' : return E;
            case 'i' : return I;
            case 'o' : return O;
            case 'u' : return U;
        }
        return INVAILD;
    }
public:
    int longestBeautifulSubstring(string word) {
        word += 'a';
        int len = 0;
        for(int i=0; i<word.size(); i++) {
            if (word[i] != 'a') continue;
            
            int prevIdx = A;
            int j=i;
            for(; j<word.size(); j++) {
                int currIdx = isVowels(word[j]);
                // the current char is same as before.
                if ( currIdx == prevIdx || currIdx == INVAILD) continue;
                // the current char is the next vowel.
                if ( currIdx == prevIdx + 1) { prevIdx++; continue;}
                // the current char is not in order, 
                // and the previous char is the final vowel.
                if ( prevIdx == U ){
                    len = max(len, j-i);
                }
                break;
            }
            i = j-1;
        }
        return len;
        
    }
};
