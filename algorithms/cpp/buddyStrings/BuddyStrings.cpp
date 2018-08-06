// Source : https://leetcode.com/problems/buddy-strings/description/
// Author : Hao Chen
// Date   : 2018-06-27

/*************************************************************************************** 
 *
 * Given two strings A and B of lowercase letters, return true if and only if we can 
 * swap two letters in A so that the result equals B.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: A = "ab", B = "ba"
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = "ab", B = "ab"
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = "aa", B = "aa"
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = "", B = "aa"
 * Output: false
 * 
 * 
 *  
 * 
 * Note:
 * 
 * 
 * 	0 <= A.length <= 20000
 * 	0 <= B.length <= 20000
 * 	A and B consist only of lowercase letters.
 * 
 * 
 * 
 * 
 * 
 ***************************************************************************************/



class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A.size()<2) return false;
        
        bool bRepeat = false;
        bool map[26] = {false};
        int idx[2], diffCnt=0;
        
        for (int i=0; i<A.size(); i++){
            if (map[A[i]-'a']) { bRepeat = true;}
            map[A[i]-'a']=true;
            if ( A[i] != B[i] ) {
                if (diffCnt>=2) return false;
                idx[diffCnt++] = i;
                
            }
        }
        //if A == B and there has repeated chars , then return true
        if (diffCnt==0 && bRepeat) return true;
        
        return (A[idx[0]] == B[idx[1]] && A[idx[1]] == B[idx[0]]);
        
    }
};
