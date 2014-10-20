// Source : https://oj.leetcode.com/problems/pascals-triangle/
// Author : Hao Chen
// Date   : 2014-06-18

#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > generate(int numRows) 
{
    vector<vector<int> > pascalTriangle;
    for (int i=0; i<numRows; i++){
        vector<int> v;
        if (i==0){
            v.push_back(1);
        } else {
            v.push_back(1);
            for(int j=0; j<pascalTriangle[i-1].size()-1; j++){
                v.push_back(pascalTriangle[i-1][j] + pascalTriangle[i-1][j+1]);
            }
            v.push_back(1);
        }
        pascalTriangle.push_back(v); 
    }
    return pascalTriangle;
}

void printVector(vector< vector<int> > pt)
{
    for(int i=0; i<pt.size(); i++){
        cout << "{ ";
        for(int j=0; j<pt[i].size(); j++){
            cout << pt[i][j] << ", ";
        }
        cout << "} " << endl;
    }
}

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    printVector(generate(n)); 
}
