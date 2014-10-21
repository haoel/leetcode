// Source : https://oj.leetcode.com/problems/count-and-say/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* The count-and-say sequence is the sequence of integers beginning as follows:
* 1, 11, 21, 1211, 111221, ...
* 
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* 
* Given an integer n, generate the nth sequence.
* 
* Note: The sequence of integers will be represented as a string.
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string vecToStr(vector<int> v) {
    stringstream ss;
    for (int i=0; i<v.size(); i++) {
        ss << v[i]; 
    }
    return ss.str();
}

vector<int> getNext(vector<int>& v) {
    int cnt=0;
    int val=0;
    vector<int> ret;
    for(int i=0; i<v.size(); i++){
        if (i==0){
            val = v[i];
            cnt = 1;
            continue;
        }
        if (v[i] == val){
            cnt++;
        }else{
            ret.push_back(cnt); 
            ret.push_back(val); 
            val = v[i];
            cnt = 1;
        }
    }
    if (cnt>0 && val>0){
        ret.push_back(cnt); 
        ret.push_back(val); 
    }
    return ret;
}
    

string countAndSay(int n) {
    if (n<=0) return "";
    if (n==1) return "1";

    string s;
    vector<int> v;
    v.push_back(1);
    for(int i=2; i<=n; i++){
       v = getNext(v);
       //s = s + ", " +vecToStr(v);
    }
    s = vecToStr(v);
    return s;
}


int main(int argc, char** argv)
{
    int n = 4;
    if (argc>1){
        n = atoi(argv[1]);
    }
    cout << countAndSay(n) << endl;
    
    return 0;
}
