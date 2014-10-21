// Source : https://oj.leetcode.com/problems/rotate-image/
// Author : Hao Chen
// Date   : 2014-06-27

/********************************************************************************** 
* 
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &matrix) {

    int n = matrix.size();

    for( int i=0; i<n/2; i++ ){
        int low=i, high=n-i-1;
        for (int j=low; j<high; j++){
            int tmp;
            tmp = matrix[i][j];
            // left to top 
            matrix[i][j] = matrix[n-j-1][i];
            // bottom to left
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            // right to bottom
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            // top to right
            matrix[j][n-i-1] = tmp;
        }
    }
}

void printMatrix(vector<vector<int> > &matrix) 
{
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        cout << endl;
    }
    cout << endl;
}


int main(int argc, char** argv)
{
    int n = 2;
    if (argc>1){
        n = atoi(argv[1]);
    }
    vector< vector<int> > matrix;
    for (int i=1; i<=n; i++) {
        vector<int> v;
        for(int j=1; j<=n; j++){
            v.push_back( (i-1)*n + j );
        }
        matrix.push_back(v);
    }

    printMatrix(matrix);
    rotate(matrix);
    printMatrix(matrix);

    return 0;
}
