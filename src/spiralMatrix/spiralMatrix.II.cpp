// Source : https://oj.leetcode.com/problems/spiral-matrix-ii/
// Author : Hao Chen
// Date   : 2014-06-30

/********************************************************************************** 
* 
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
* 
* For example,
* Given n = 3,
* 
* You should return the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 8, 9, 4 ],
*  [ 7, 6, 5 ]
* ]
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generateMatrix(int n, int m);

vector<vector<int> > generateMatrix(int n) {
    return generateMatrix(n, n);
}

vector<vector<int> > generateMatrix(int n, int m) {
    vector< vector <int> > matrix(n);
    if (n<=0) return matrix;
    for(int i=0; i<n; i++){
        vector<int> v(m);
        matrix[i] = v;
    }

    int row=n, col=m;
    int r, c;
    int cnt=1;
    for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
        //top
        for(int i=c; i<col-c; i++){
            matrix[r][i] = cnt++;
        }
        //right
        for(int i=r+1; i<row-r; i++){
            matrix[i][col-c-1] = cnt++;
        }
        //bottom
        for(int i=col-c-2; row-r-1>r && i>=c; i--){
            matrix[row-r-1][i] = cnt++;
        }
        //left
        for(int i=row-r-2; col-c-1>c && i>r; i--){
            matrix[i][c] = cnt++;
        }
        
    }
    return matrix;
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


int main(int argc, char** argv)
{
    int n=3, m=3;
    if (argc>1){
        m = n = atoi(argv[1]);
    }
    if (argc>2){
        m = atoi(argv[2]);
    }
    vector< vector<int> > matrix = generateMatrix(n, m);
    printMatrix(matrix);
    return 0;
}
