// Source : https://oj.leetcode.com/problems/pascals-triangle/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Given numRows, generate the first numRows of Pascal's triangle.
* 
* For example, given numRows = 5,
* Return
* 
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
* 
*               
**********************************************************************************/

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

void printTriangle(vector< vector<int> > pt)
{
	cout << "[" << endl;
    for(int i=0; i<pt.size(); i++){
    	for(int space=(pt.size()-i-1); space>=0; space--){
    		cout << " ";
    	}
        cout << "[";
        for(int j=0; j<pt[i].size(); j++){
            cout << pt[i][j];
            if(j<pt[i].size()-1){
            	cout << ",";
            }
        }
        cout << "]";
        if(i<pt.size()-1){
        	cout << ",";
        }
        cout << endl;
    }
    cout << "]" << endl;
}

int main(int argc, char** argv)
{
    int n = 3;
    if (argc>1) {
        n = atoi(argv[1]);
    }
    printTriangle(generate(n)); 
}
