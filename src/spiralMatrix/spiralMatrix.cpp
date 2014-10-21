// Source : https://oj.leetcode.com/problems/spiral-matrix/
// Author : Hao Chen
// Date   : 2014-06-30

/********************************************************************************** 
* 
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
* 
* For example,
* Given the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* 
* You should return [1,2,3,6,9,8,7,4,5].
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector <int> v;
    int row = matrix.size();
    if (row<=0) return v;
    int col = matrix[0].size();
    if (col<=0) return v;
    int r, c;
    for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
        //top
        for(int i=c; i<col-c; i++){
            v.push_back(matrix[r][i]);
        }
        //right
        for(int i=r+1; i<row-r; i++){
            v.push_back(matrix[i][col-c-1]);
        }
        //bottom
        for(int i=col-c-2; row-r-1>r && i>=c; i--){
            v.push_back(matrix[row-r-1][i]);
        }
        //left
        for(int i=row-r-2; col-c-1>c && i>r; i--){
            v.push_back(matrix[i][c]);
        }
        
    }
    return v;
}


void printArray(vector<int> v)
{
    cout << "[";
    for(int j=0; j<v.size(); j++) {
        printf(" %02d", v[j]);
    }
    cout << "]" << endl;;
}

void printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        printArray(vv[i]);
    }
    cout << endl;
}

vector< vector<int> > createMatrix(int n, int m)
{
    vector< vector<int> > vv;
    int cnt = 1;
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<m; j++){
            v.push_back(cnt++);
        }
        vv.push_back(v);
    }
    return vv;
}

int main(int argc, char** argv)
{
    int n=3, m=3;
    if (argc>2){
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    vector< vector<int> > matrix = createMatrix(n, m);
    printMatrix(matrix);
    vector<int> v = spiralOrder(matrix);
    printArray(v);
    return 0;
}
