// Source : https://leetcode.com/problems/maximal-square/
// Author : Hao Chen
// Date   : 2015-06-12

/********************************************************************************** 
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 4.
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
 *               
 **********************************************************************************/


/*
 *  Dynamic Programming
 *
 *   1) P[0][j] = matrix[0][j] (topmost row);
 *   2) P[i][0] = matrix[i][0] (leftmost column);
 *   3) For i > 0 and j > 0: 
 *       3.1) if matrix[i][j] = 0, P[i][j] = 0; 
 *       3.2) if matrix[i][j] = 1, P[i][j] = min(P[i-1][j], P[i][j-1], P[i-1][j-1]) + 1.
 *
 *   The details of this algorithm has been well described here.
 *   https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
 * 
 *      
 *      Well, this problem desires for the use of dynamic programming. They key to any DP problem is to 
 *      come up with the state equation. In this problem, we define the state to be the maximal size of
 *      the square that can be achieved at point (i, j), denoted as P[i][j]. Remember that we use size
 *      instead of square as the state (square = size^2).
 *      
 *      Now let's try to come up with the formula for P[i][j].
 *      
 *      First, it is obvious that for the topmost row (i = 0) and the leftmost column (j = 0), 
 *      P[i][j] = matrix[i][j].  This is easily understood. Let's suppose that the topmost row 
 *      of matrix is like [1, 0, 0, 1].  Then we can immediately know that the first and last point 
 *      can be a square of size 1 while the two middle points cannot make any square, giving a size of 0. 
 *      Thus, P = [1, 0, 0, 1], which is the same as matrix. The case is similar for the leftmost column. 
 *      Till now, the boundary conditions of this DP problem are solved.
 *      
 *      Let's move to the more general case for P[i][j] in which i > 0 and j > 0. First of all, 
 *      let's see another simple case in which matrix[i][j] = 0. It is obvious that P[i][j] = 0 too. 
 *      Why? Well, since matrix[i][j] = 0, no square will contain matrix[i][j], according to our 
 *      definition of P[i][j], P[i][j] is also 0.
 *      
 *      Now we are almost done. The only unsolved case is matrix[i][j] = 1. Let's see an example.
 *      
 *      Suppose matrix = [[0, 1], [1, 1]], it is obvious that P[0][0] = 0, P[0][1] = P[1][0] = 1, 
 *      what about P[1][1]? Well, to give a square of size larger than 1 in P[1][1], all of its 
 *      three neighbors (left, up, left-up) should be non-zero, right? In this case, the left-up 
 *      neighbor P[0][0] = 0, so P[1][1] can only be 1, which means that it contains the square of itself.
 *      
 *      Now you are near the solution. In fact, P[i][j] = min(P[i-1][j], P[i][j-1], P[i-1][j-1]) + 1 in this case.
 *      
 *      
 */

class Solution {
public:
    inline int min(int x, int y) {
        return x<y? x:y;
    }
    inline int min(int x, int y, int z) {
        return min(x, min(y, z));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row <=0) return 0;
        int col = matrix[0].size();
        
        int maxSize = 0;
        vector<vector<int>> dp(row, vector<int>(col));
        
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++){
                //convert the `char` to `int`
                dp[i][j] = matrix[i][j] -'0';
                //for the first row and first column, or matrix[i][j], dp[i][j] is ZERO
                //so, it's done during the previous conversion
                
                // i>0 && j>0 && matrix[i][j]=='1'
                if (i!=0 && j!=0 & dp[i][j]!=0){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
                
                //tracking the maxSize
                if (dp[i][j] > maxSize ){
                    maxSize = dp[i][j];
                }
            }
        }
        
        return maxSize*maxSize;
    }
};
