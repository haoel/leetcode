// Source : https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author : Manu Gond
// Date   : 2019-10-06

/***************************************************************************************************** 
* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

* Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

* The order of output does not matter.

* Example 1:

* Input:
   s: "cbaebabacd" p: "abc"

* Output:
  [0, 6]

* Explanation:
  The substring with start index = 0 is "cba", which is an anagram of "abc".
  The substring with start index = 6 is "bac", which is an anagram of "abc".
*Example 2:

* Input:
   s: "abab" p: "ab"

* Output:
   [0, 1, 2]

* Explanation:
* The substring with start index = 0 is "ab", which is an anagram of "ab".
* The substring with start index = 1 is "ba", which is an anagram of "ab".
* The substring with start index = 2 is "ab", which is an anagram of "ab".
 ******************************************************************************************************/
 
 
 class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        vector<int>v1(26);
        if(s.size()<p.size()){
            return result;
        }
        for(int i=0;i<p.size();i++){
            v1[p[i]-97]++;
        }
        for(int i=0;i<=(s.size()-p.size());i++){
            vector<int>v2(26);
            for(int index=i;index<(i+p.size());index++){
                v2[s[index]-97]++;
            }
            if(v1==v2){
                result.push_back(i);
            }        
        }
        return result;
    }
};
