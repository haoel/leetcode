// Source : https://oj.leetcode.com/problems/permutations/
// Author : Hao Chen
// Date   : 2014-06-21

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

/*
{ 1 2 3 }
{ 2 1 3 }
{ 3 2 1 }
{ 1 3 2 }
{ 2 3 1 }
{ 3 1 2 }
*/

vector<vector<int> > permute(vector<int> &num) {
    
    vector<vector<int> > vv;
    vv.push_back(num);

    if (num.size() <2){
        return vv;
    }
        
    int pos=0;
    while(pos<num.size()-1){
        int size = vv.size();
        for(int i=0; i<size; i++){
            //take each number to the first
            for (int j=pos+1; j<vv[i].size(); j++) {
                vector<int> v = vv[i];
                int t = v[j]; 
                v[j] = v[pos];
                v[pos] = t;
                vv.push_back(v);
            }
        }
        pos++;
    }
    return vv;
}

int main(int argc, char** argv)
{
    int n = 3;
    if (argc>1){
       n = atoi(argv[1]); 
    }

    vector<int> v;
    for (int i=0; i<n; i++) {
        v.push_back(i+1);
    }
    vector<vector<int> > vv;
    vv = permute(v);
    
    for(int i=0; i<vv.size(); i++) {
        cout << "{ ";
        for(int j=0; j<vv[i].size(); j++){
            cout << vv[i][j] << " ";
        }
        cout << "}" <<endl;
    }

    return 0;
}
