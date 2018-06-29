// Source : https://leetcode.com/problems/backspace-string-compare/description/
// Author : Hao Chen
// Date   : 2018-06-29

/*************************************************************************************** 
 *
 * Given two strings S and T, return if they are equal when both are typed into empty 
 * text editors. # means a backspace character.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * 
 * Note:
 * 
 * 
 * 	1 <= S.length <= 200
 * 	1 <= T.length <= 200
 * 	S and T only contain lowercase letters and '#' characters.
 * 
 * 
 * Follow up:
 * 
 * 
 * 	Can you solve it in O(N) time and O(1) space?
 * 
 * 
 * 
 * 
 ***************************************************************************************/

class Solution {
private:    
    void removeBackspaces(string &s) {
        int i = 0;
        for(int i=0; i<s.size(); i++) {
            if (s[i] == '#') {
                int backSteps = i>0 ? 2 : 1;
                s.erase(i-backSteps + 1, backSteps);
                i -= backSteps;
            } 
        }
    }
    
public:
    bool backspaceCompare(string S, string T) {
        removeBackspaces(S);
        removeBackspaces(T);
        return S == T;
    }
};
