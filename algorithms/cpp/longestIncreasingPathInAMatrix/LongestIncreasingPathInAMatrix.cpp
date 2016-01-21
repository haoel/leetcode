// Source : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author : Hao Chen
// Date   : 2016-01-21

/*************************************************************************************** 
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or down. You 
 * may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not 
 * allowed).
 * 
 * Example 1:
 * 
 * nums = [
 *   [>9, 9, 4],
 *   [>6, 6, 8],
 *   [>2,>1, 1]
 * ]
 * 
 * Return 4
 * 
 * The longest increasing path is [1, 2, 6, 9].
 * 
 * Example 2:
 * 
 * nums = [
 *   [>3,>4,>5],
 *   [ 3, 2,>6],
 *   [ 2, 2, 1]
 * ]
 * 
 * Return 4
 * 
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        int row = matrix.size();
        int col = row ? matrix[0].size() : 0;
        vector<vector<int>> path = vector<vector<int>>(row, vector<int>(col, 0));
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                result = max(result, helper(matrix, path, row, col, r, c));
            }
        }
        return result;
    }
    
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& path, const int row, const int col, int r, int c) {

        if (path[r][c]>0) return path[r][c];
        
        int maxPath = 0;
        
        int tmp = matrix[r][c]; 
        matrix[r][c]=INT_MIN;  
        if (r < row-1 && tmp < matrix[r+1][c]) {
            maxPath = max(maxPath, helper(matrix, path, row, col, r+1, c));
        }
        if (c < col-1 && tmp < matrix[r][c+1]) {
            maxPath = max(maxPath, helper(matrix, path, row, col, r, c+1));
        }
        if (r > 0 && tmp < matrix[r-1][c]) {
            maxPath = max(maxPath, helper(matrix, path, row, col, r-1, c));
        }
        if (c > 0 && tmp < matrix[r][c-1]) {
            maxPath = max(maxPath, helper(matrix, path, row, col, r, c-1));
        }
        matrix[r][c] = tmp;
        path[r][c] = maxPath + 1;
        return path[r][c];
    }
};
