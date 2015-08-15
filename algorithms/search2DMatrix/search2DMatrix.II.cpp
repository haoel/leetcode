// Source : https://leetcode.com/problems/search-a-2d-matrix-ii/
// Author : Hao Chen
// Date   : 2015-08-15

/********************************************************************************** 
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. This 
 * matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * 
 * Given target = 5, return true.
 * Given target = 20, return false.
 *               
 *               
 * 
 *               
 **********************************************************************************/


class Solution {
public:
    
    
    bool binary_search(vector<int> &v, int target) {
        int low = 0;
        int high = v.size()-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if (target == v[mid]) return true;
            if (target < v[mid]) {
                high = mid -1;
            }else {
                low = mid + 1;
            }
        }
        
        return false;
    }
    
    //using binary_search() to search each rows - slow O(n*log(n))
    //the run time is around 840ms for all test case
    bool searchMatrix01(vector<vector<int>>& matrix, int target) {
        for (int i=0; i<matrix.size(); i++){
            if (target < matrix[i][0] ) return false;
            if (binary_search(matrix[i], target))  return true;

        }
        return false;
    }
    
    
    
    
    //start the liner search from top right corner of matrix. - O(m+n)
    //the run time is around 340ms
    bool searchMatrix02(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size()==0) return false;
        int row=0,  col = matrix[0].size() - 1; 
        while (row < matrix.size() && col >=0 ) {
            if (target == matrix[row][col]) return true;
            if (target < matrix[row][col]) {
                col--;
            }else{
                row++;
            }
            
        }
        return false;
    }
    
    //a bit optimization for methed 2 - the run time is 300ms
    bool searchMatrix021(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size()==0) return false;
        int row=0,  col = matrix[0].size() - 1; 
        while (row < matrix.size() && col >=0 ) {
            if (target == matrix[row][col]) return true;
            while ( col>=0 && target < matrix[row][col]) {
                col--;
            }
            while(row < matrix.size() && target > matrix[row][col]){
                row++;
            }
            
        }
        return false;
    }

    //Optimization: using binary search methed to move `low` and `row` 
    //however, the run time is around 830ms
    bool searchMatrix022(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size()==0) return false;
        
        int row=0,  col = matrix[0].size() - 1; 
        
        while (row < matrix.size() && col >=0 ) {
            
            if (target == matrix[row][col]) return true;
            
            if (target < matrix[row][col]) {
                int start=0, end=col;
                while(start <= end){
                    int mid = start + (end - start)/2;
                    if (target == matrix[row][mid]) return true;
                    if (target > matrix[row][mid]) {
                        col = start = mid + 1;
                    }else {
                        col = end = mid - 1;
                    }
                }
                
            }else{
                int start=0, end=row;
                while(start<=end){
                    int mid = start + (end - start)/2;
                    if (target == matrix[mid][col]) return true;
                    if (target > matrix[mid][col]) {
                        row = start = mid + 1;
                    }else{
                        row = end = mid -1;
                    }
                }
            }
            
        }
        return false;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        return searchMatrix022(matrix, target); //840ms ??
        return searchMatrix021(matrix, target); //320ms
        return searchMatrix02(matrix, target); //340ms
        
        return searchMatrix01(matrix, target); // 840ms
    }
};
