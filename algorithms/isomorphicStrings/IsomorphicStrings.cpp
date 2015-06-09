// Source : https://leetcode.com/problems/isomorphic-strings/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while preserving 
 * the order of characters. No two characters may map to the same character but a character
 *  may map to itself.
 * 
 * For example,
 *
 *     Given "egg", "add", return true.
 *     
 *     Given "foo", "bar", return false.
 *     
 *     Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 *               
 **********************************************************************************/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size()!=t.size()) return false;
        
        const int MAXCHAR = 256;
        char maps[MAXCHAR]={0}, mapt[MAXCHAR]={0};
        //memset(maps, 0, sizeof(maps));
        //memset(mapt, 0, sizeof(mapt));
        
        for(int i=0; i<s.size(); i++){
            if(maps[s[i]] == 0 && mapt[t[i]] == 0){
                maps[s[i]] = t[i];
                mapt[t[i]] = s[i];
                continue;
            }
            if(maps[s[i]] == t[i] && mapt[t[i]] == s[i]) {
                continue;
            }
            return false;
        }
        return true;
    }
};
