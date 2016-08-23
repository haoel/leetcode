// Source : https://leetcode.com/problems/first-unique-character-in-a-string/
// Author : Hao Chen
// Date   : 2016-08-23

/*************************************************************************************** 
 *
 * Given a string, find the first non-repeating character in it and return it's index. 
 * If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * Note: You may assume the string contain only lowercase letters.
 ***************************************************************************************/

class Solution {
public:
    int firstUniqChar(string s) {
        //As the question mentioned, there only have lower case chars, 
        //so the MAX_CHAR can be defined as 26, but I want this algorithm be more general for all ASCII
        #define MAX_CHAR 256
        #define NOT_FOUND  -1
        #define DUPLICATION -2
        
        // initlize all chars status to NOT_FOUND
        int pos_map[MAX_CHAR];
        memset(pos_map, NOT_FOUND,sizeof(pos_map));
        
        // if it is the first time to find, set the status to its postion
        // if it is the second time to find, set the status to duplication
        // if it has already duplicated, do nothing 
        for (int i=0; i<s.size(); i++){
            if ( pos_map[s[i]] >= 0 ) {
                pos_map[s[i]] = DUPLICATION;
            }else if ( pos_map[s[i]] == NOT_FOUND ) {
                pos_map[s[i]] = i;
            }
        }
        
        // find the lowest postion
        int pos = INT_MAX;
        for (auto item : pos_map) {
            cout << item << ",";
            if (item >= 0 && item < pos) {
                pos = item;
            }
        }
        return pos == INT_MAX ? -1 : pos;
    }
};
