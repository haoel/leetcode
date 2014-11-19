// Source : https://oj.leetcode.com/problems/pascals-triangle-ii/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Given an index k, return the kth row of the Pascal's triangle.
* 
* For example, given k = 3,
* Return [1,3,3,1].
* 
* Note:
* Could you optimize your algorithm to use only O(k) extra space?
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> v(rowIndex+1, 0);
    v[0]=1;

    for (int i=0; i<rowIndex; i++){
        for(int j=i+1; j>0; j--){
           v[j] += v[j-1];
        } 
    }
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
    int n = 3;
    if (argc>1) {  
        n = atoi(argv[1]);
    }
    printVector(getRow(n)); 
}
