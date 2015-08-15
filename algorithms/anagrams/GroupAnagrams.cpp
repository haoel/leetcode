// Source : https://oj.leetcode.com/problems/anagrams/
// Author : Hao Chen
// Date   : 2014-07-18

/********************************************************************************** 
 * 
 * Given an array of strings, group anagrams together.
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * 
 * Note:
 * 
 * For the return value, each inner list's elements must follow the lexicographic order.
 * All inputs will be in lower-case.
 * 
 * Update (2015-08-09):
 * The signature of the function had been updated to return list<list<string>> instead 
 * of list<string>, as suggested here. If you still see your function signature return 
 * a list<string>, please click the reload button  to reset your code definition.
 * 
 **********************************************************************************/

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string> &strs) {
        vector< vector<string> > result;
        map<string, int> m;
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            if (m.find(word)==m.end()){
                vector<string> v;
                v.push_back(strs[i]);
                result.push_back(v);
                m[word] = result.size()-1;
                
            }else{
                result[m[word]].push_back(strs[i]);
            }
        }
        
        for(int i=0; i<result.size(); i++){
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
     
    //using multiset 
    vector< vector<string> > groupAnagrams01(vector<string> &strs) {
        vector< vector<string> > result;
        map<string, multiset<string>> m;
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            m[word].insert(strs[i]);
        }
        
        for(auto item : m){
            vector<string> v(item.second.begin(), item.second.end());
            result.push_back(v);
        }
        return result;
    }


    //NOTICE: the below solution has been depracated as the problem has been updated!
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, int> m;
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            //sort it can easy to check they are anagrams or not
            sort(word.begin(), word.end());  
            if (m.find(word)==m.end()){
                m[word] = i;
            }else{
                if (m[word]>=0){
                    result.push_back(strs[m[word]]);
                    m[word]=-1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};
