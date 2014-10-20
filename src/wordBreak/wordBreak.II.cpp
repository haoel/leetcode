// Source : https://oj.leetcode.com/problems/word-break-ii/
// Author : Hao Chen
// Date   : 2014-07-03

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

//To avoid time limit error, need to add cache
vector<string> wordBreak(string s, set<string> &dict, map<string, vector<string> >& cache) {

    if (cache.find(s)!=cache.end()){
        return cache[s];
    }

    vector<string> result;

    for(int i=0; i<s.size(); i++){
        string w = s.substr(0,i+1);
        if (dict.find(w)!=dict.end()) {
           if (i==s.size()-1){
                result.push_back(w);
                break;
           }

            vector<string> ret = wordBreak(s.substr(i+1, s.size()-i-1), dict, cache);
            for(int j=0; j<ret.size(); j++){
                result.push_back( w + " " + ret[j] );
            }
        }
    }
    cache[s] = result;
    return result;
    
}


//Time limit error
void wordBreak(string s, set<string> &dict, string str, vector<string>& result) {

    string org_str = str;

    for(int i=0; i<s.size(); i++){
        string w = s.substr(0,i+1);

        if (dict.find(w)!=dict.end()) {
            str = org_str;
            if (str.size()>0){
                str +=" ";
            }
            str = str + w;

            if (i==s.size()-1){
                result.push_back(str);
                return;
            }

            wordBreak(s.substr(i+1, s.size()-i-1), dict, str, result);
        }
    }
}

//Dynamic Programming
vector<string> wordBreak_dp(string s, set<string> &dict) {
    vector< vector<string> > result(s.size());

    for(int i=s.size()-1; i>=0; i--) {
        vector<string> v;
        result[i] = v;
        for(int j=i+1; j<=s.size(); j++) {
            string word = s.substr(i, j-i);
            if (dict.find(word) != dict.end()){
                if (j==s.size()){
                    result[i].push_back(word);
                }else{
                    for(int k=0; k<result[j].size(); k++){
                        result[i].push_back(word + " " + result[j][k]);
                    }
                }
            }
        } 
    }

    return result[0];
}


vector<string> wordBreak(string s, set<string> &dict) {

    vector<string> result;

    switch (random()%3) 
    {
        case 0: 
            {
            cout << "---------Recursive Solution--------" << endl;
            string str;
            wordBreak(s, dict, str, result);
            }
            break;

        case 1:
            {
            cout << "----Memorized Recursive Solution----" << endl;
            map<string, vector<string> > cache;
            result = wordBreak(s, dict,  cache);
            }
            break;

        case 2:
            cout << "----Dynamic Programming Solution----" << endl;
            result =  wordBreak_dp(s, dict);
            break;
    }
    return result;
}

void printVector(vector<string>& v)
{
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<endl;
    }
}

int main()
{
    srand(time(NULL));

    string d[]={"cat", "cats", "and", "sand", "dog"};
    set<string> dict(d, d+5);
    string s = "catsanddog";
    vector<string> v = wordBreak(s, dict);
    printVector(v);     
    
    string d0[]={"apple","app","le","pie"};
    dict.clear();
    dict.insert(d0, d0+4);
    s = "applepie";
    v = wordBreak(s, dict);
    printVector(v);     
    
    string d1[]={"aaaa","aa","a"};
    dict.clear();
    dict.insert(d1, d1+3);
    s = "aaaaaaa";
    v = wordBreak(s, dict);
    printVector(v);     

    string d5[]={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    dict.clear();
    dict.insert(d5, d5+10);
    s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    v = wordBreak(s, dict);
    printVector(v);     

    return 0;
}
