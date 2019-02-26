// Source : https://leetcode.com/problems/minimum-falling-path-sum/
// Author : Hao Chen
// Date   : 2019-01-30

/***************************************************************************************************** 
 *
 * Given a square array of integers A, we want the minimum sum of a falling path through A.
 * 
 * A falling path starts at any element in the first row, and chooses one element from each row.  The 
 * next row's choice must be in a column that is different from the previous row's column by at most 
 * one.
 * 
 * Example 1:
 * 
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: 12
 * Explanation: 
 * The possible falling paths are:
 * 
 * 	[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
 * 	[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
 * 	[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
 * 
 * The falling path with the smallest sum is [1,4,7], so the answer is 12.
 * 
 * Note:
 * 
 * 	1 <= A.length == A[0].length <= 100
 * 	-100 <= A[i][j] <= 100
 ******************************************************************************************************/
class Solution {
private:
    int min(int x, int y) {
        return x < y ? x: y;
    }
    int min( int x, int y, int z) {
        return min(min(x, y),z);
    }
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = INT_MAX;
        
        for (int i=0; i<A.size(); i++) {
            for (int j=0; j<A[i].size(); j++){
                //find the minimal item in previous row, and add it into the current item
                if (i > 0) {
                    if (j == 0 ){
                       A[i][j] += min( A[i-1][j], A[i-1][j+1]); 
                    } else if ( j + 1 == A[i].size()) {
                       A[i][j] += min( A[i-1][j], A[i-1][j-1]); 
                    }else {
                        A[i][j] += min( A[i-1][j], A[i-1][j-1], A[i-1][j+1]);
                    }
                }
                
                if ( i + 1 == A.size() ) {
                    m = min(m, A[i][j]);
                }
            }
        }
        
        return m;
    }
};
