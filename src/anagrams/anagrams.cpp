// Source : https://oj.leetcode.com/problems/anagrams/
// Author : Hao Chen
// Date   : 2014-07-18

/********************************************************************************** 
* 
* Given an array of strings, return all groups of strings that are anagrams.
* 
* Note: All inputs will be in lower-case.
*               
**********************************************************************************/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, string> m;
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            if (m.find(word)==m.end()){
                m[word] = strs[i];
            }else{
                if (m[word]!="#"){
                    result.push_back(m[word]);
                    m[word]="#";
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};
