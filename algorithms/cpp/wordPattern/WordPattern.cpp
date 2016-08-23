// Source : https://leetcode.com/problems/word-pattern/
// Author : Hao Chen
// Date   : 2015-10-22

/*************************************************************************************** 
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *  Here follow means a full match, such that there is a bijection between a letter in 
 * pattern and a non-empty word in str.
 * 
 * Examples:
 * 
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase 
 * letters separated by a single space.
 * 
 * Credits:Special thanks to @minglotus6 for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/

class Solution {

private::

    vector<string> split(string str, char delimiter) {
        vector<string> internal;
        stringstream ss(str); // Turn the string into a stream.
        string tok;
        
        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }
        
        return internal;
    }

public:
    
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> dict_pattern;
        unordered_map<string, char> dict_string;
        
        int len = pattern.size();
        vector<string> strs = split(str, ' ');
        
        if (len != strs.size()) return false;
        
        for(int i=0; i<len; i++) {
            char& ch = pattern[i];
            string& s = strs[i];
            
            if ( dict_pattern.find(ch) == dict_pattern.end() ) {
                dict_pattern[ch] = s;
            }
            
            if ( dict_string.find(s) == dict_string.end() ) {
                dict_string[s] = ch;
            }
            
            if ( dict_pattern[ch] != s || dict_string[s] != ch ) {
                return false;
            }
            
        }
        return true;
    }
};

