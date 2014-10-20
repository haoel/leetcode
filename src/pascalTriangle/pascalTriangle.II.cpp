// Source : https://oj.leetcode.com/problems/pascals-triangle-ii/
// Author : Hao Chen
// Date   : 2014-06-18

#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> v;
    for(int i=0; i<rowIndex; i++){
       if(i==0){
           v.push_back(1);
       }else{
           v.push_back(0);
       }
    }

    for (int i=0; i<rowIndex; i++){
        for(int j=i+1; j>0; j--){
           v[j] += v[j-1];
        } 
    }
    v.push_back(1);
    return v;
    
}

void printVector( vector<int>  pt)
{
    cout << "{ ";
    for(int j=0; j<pt.size(); j++){
        cout << pt[j] << ", ";
    }
    cout << "} " << endl;
}

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    printVector(getRow(n)); 
}
