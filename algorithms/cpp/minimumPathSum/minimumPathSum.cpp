// Source : https://oj.leetcode.com/problems/minimum-path-sum/
// Author : Hao Chen
// Date   : 2014-06-21

/***************************************************************************************************** 
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
 * which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1&rarr;3&rarr;1&rarr;1&rarr;1 minimizes the sum.
 * 
 ******************************************************************************************************/

#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (i==0 && j==0) continue;
            else if (i==0) grid[0][j] += grid[0][j-1];
            else if (j==0) grid[i][0] += grid[i-1][j];
            else grid[i][j] += min( grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[grid.size()-1][grid[0].size()-1];
}

int main()
{
    int a[6][2]={{7,2},{6,6},{8,6},{8,7},{5,0},{6,0}};
    vector< vector<int> > grid;
    for(int i=0; i<6; i++){
        vector<int> v;
        for(int j=0; j<2; j++){
            v.push_back(a[i][j]);
        }
        grid.push_back(v);
    }

    cout << "minPathSum=" << minPathSum(grid) << endl;

    return 0;
}

