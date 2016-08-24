// Source : https://leetcode.com/problems/ransom-note/
// Author : Hao Chen
// Date   : 2016-08-24

/*************************************************************************************** 
 *
 *  Given  an  arbitrary  ransom  note  string  and  another  string  containing 
 *  letters from  all  the  magazines,  write  a  function  that  will  return  true 
 *  if  the  ransom  
 * note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return 
 *  false.   
 * 
 * Each  letter  in  the  magazine  string  can  only  be  used  once  in  your 
 *  ransom  note.
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 ***************************************************************************************/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(int i=0; i<magazine.size(); i++) {
            m[magazine[i]]++;
        }
        for (int i=0; i<ransomNote.size(); i++) {
            char c = ransomNote[i];
            if (m[c] <=0 ) return false;
            m[c]--;
        }
        return true;
    }
};
