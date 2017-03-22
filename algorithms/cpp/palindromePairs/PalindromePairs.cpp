// Source : https://leetcode.com/problems/palindrome-pairs/
// Author : Hao Chen
// Date   : 2017-03-22

/*************************************************************************************** 
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in the given 
 * list, so that the concatenation of the two words, i.e. words[i] + words[j] is a 
 * palindrome.
 * 
 *     Example 1:
 *     Given words = ["bat", "tab", "cat"]
 *     Return [[0, 1], [1, 0]]
 *     The palindromes are ["battab", "tabbat"]
 * 
 *     Example 2:
 *     Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 *     Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 *     The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 *       
 ***************************************************************************************/

class Solution {
public:
    bool isPalindrome(string& str) {
        int left = 0, right = str.size() - 1;
        while( left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        for(int i=0; i<words.size(); i++){
            string w = words[i];
            reverse(w.begin(), w.end());
            dict[w] = i;
        }
        
        
        vector<vector<int>> result;
        
        //egde case: deal with empty string 
        if ( dict.find("") != dict.end() ) {
            for(int i=0; i<words.size(); i++) {
                if ( isPalindrome(words[i]) && dict[""] != i ) {
                    result.push_back( { dict[""], i } );
                }
            }
        }
        
        for(int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                //split the word to 2 parts
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                
                // if the `left` is found, which means there is a words has reversed sequence with it.
                // then we can check the `right` part is Palindrome or not. 
                if ( dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i ) {
                    result.push_back( { i, dict[left] } );
                }
                
                if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i ) {
                    result.push_back( { dict[right], i } );
                }
            }

        }
        
        return result;
    }
    
};

