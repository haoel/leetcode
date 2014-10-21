// Source : https://oj.leetcode.com/problems/word-break/
// Author : Hao Chen
// Date   : 2014-07-01

/********************************************************************************** 
* 
* Given a string s and a dictionary of words dict, determine if s can be segmented 
* into a space-separated sequence of one or more dictionary words.
* 
* For example, given
* s = "leetcode",
* dict = ["leet", "code"].
* 
* Return true because "leetcode" can be segmented as "leet code".
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool wordBreak(string s, set<string> &dict) {

    vector<bool> v(s.size(),false);

    for(int i=0; i<s.size(); i++){
        string w = s.substr(0,i+1);
        v[i] = (dict.find(w)!=dict.end());

        if (v[i]) continue;

        for(int j=0; j<i; j++){
            if (v[j]==true){
                w = s.substr(j+1, i-j);
                v[i] = (dict.find(w)!=dict.end());
                if (v[i]) break;
            }
        }
    }
    return v.size() ? v[v.size()-1] : false;
}


int main()
{
    string s; 
    set<string> dict;

    s = "a";
    dict.insert("a");
    cout << wordBreak(s, dict) << endl;
    
    dict.clear();
    s = "dogs";
    string d[]={"dog","s","gs"};
    dict.insert(d, d+3);
    cout << wordBreak(s, dict) << endl;

    return 0;
}
