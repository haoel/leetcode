// Source : https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
// Author : Hao Chen
// Date   : 2021-03-31

/***************************************************************************************************** 
 *
 * You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an 
 * integer k.
 * 
 * The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m 
 * and 0 <= j <= b < n (0-indexed).
 * 
 * Find the k^th largest value (1-indexed) of all the coordinates of matrix.
 * 
 * Example 1:
 * 
 * Input: matrix = [[5,2],[1,6]], k = 1
 * Output: 7
 * Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
 * 
 * Example 2:
 * 
 * Input: matrix = [[5,2],[1,6]], k = 2
 * Output: 5
 * Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
 * 
 * Example 3:
 * 
 * Input: matrix = [[5,2],[1,6]], k = 3
 * Output: 4
 * Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
 * 
 * Example 4:
 * 
 * Input: matrix = [[5,2],[1,6]], k = 4
 * Output: 0
 * Explanation: The value of coordinate (1,1) is 5 XOR 2 XOR 1 XOR 6 = 0, which is the 4th largest 
 * value.
 * 
 * Constraints:
 * 
 * 	m == matrix.length
 * 	n == matrix[i].length
 * 	1 <= m, n <= 1000
 * 	0 <= matrix[i][j] <= 10^6
 * 	1 <= k <= m * n
 ******************************************************************************************************/

class Solution {
private:
    void print(vector<vector<int>>& m) {
        int row = m.size();
        int col = m[0].size();
        for (int i=0; i<row; i++) {
            for(int j=0; j<col-1; j++) {
                cout << setw(3) << m[i][j] << ",";
            }
            cout << setw(3) << m[i][col-1] << endl;
        }
        cout << endl;
    }
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> xmatrix(row, vector<int>(col, 0));
        priority_queue<int> minHeap;
        
        xmatrix[0][0] = matrix[0][0];
        minHeap.push(xmatrix[0][0]);
 
        for (int i=1; i<row; i++) {
            xmatrix[i][0] = xmatrix[i-1][0] ^ matrix[i][0];
            minHeap.push(xmatrix[i][0]);
        }
        for (int i=1; i<col; i++) {
            xmatrix[0][i] = xmatrix[0][i-1] ^ matrix[0][i];
            minHeap.push(xmatrix[0][i]);
        }
        
        for (int i=1; i<row; i++) {
            for(int j=1; j<col; j++) {
                xmatrix[i][j] = matrix[i][j] ^ 
                    xmatrix[i-1][j] ^ xmatrix[i][j-1] ^ xmatrix[i-1][j-1];
                minHeap.push(xmatrix[i][j]);
            }
        }
        //print(matrix);
        //print(xmatrix);
        while( k-- > 1) {
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};
