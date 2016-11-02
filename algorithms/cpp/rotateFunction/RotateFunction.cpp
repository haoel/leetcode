// Source : https://leetcode.com/problems/rotate-function/
// Author : Hao Chen
// Date   : 2016-11-03

/*************************************************************************************** 
 *
 * Given an array of integers A and let n to be its length.
 * 
 * Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we 
 * define a "rotation function" F on A as follow:
 * 
 * F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
 * 
 * Calculate the maximum value of F(0), F(1), ..., F(n-1). 
 * 
 * Note:
 * n is guaranteed to be less than 105.
 * 
 * Example:
 * 
 * A = [4, 3, 2, 6]
 * 
 * F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
 * F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
 * F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
 * F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
 * 
 * So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
 ***************************************************************************************/


// 
// Asumming we have 4 numbers: a, b, c, d, then
//   F(0) = 0a + 1b + 2c + 3d
//   F(1) = 3a + 0b + 1c + 2d
//   F(2) = 2a + 3b + 0c + 1d
//   F(3) = 1a + 2b + 3c + 0d
//
// We can see how F(n) transfrom to F(n+1) 
//   F(0) - F(1) = -3a + b + c + d  
//   F(1) - F(2) = a + -3b + c + d
//   F(2) - F(3) = a + b + -3c + d
//   F(3) - F(0) = a + b + c + -3d
//   
// So, we can tansfrom to the following experssion: 
// 
//   F(1) = F(0) - (a+b+c+d) + 4a  
//   F(2) = F[1] - (a+b+c+d) + 4b
//   F(3) = F[2] - (a+b+c+d) + 4c
// 
// Then, we can see this fomular:
//
//   F(n) = F(n-1) - sum(array) + len(array) * array[n-1]
//   
class Solution {
public:    
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int F = 0;
        for (int i=0; i < A.size(); i++) {
            sum += A[i];
            F += (i * A[i]);
        }
        int maxF = F;
        int len = A.size();
        //cout << "F(0) = " << maxF <<endl;
        for (int i=1; i< len; i++) {
            F = F - sum + len * A[i-1];
            //cout << "F(" << i << ") = " << F << endl;
            maxF = max(maxF, F);
        }
        
        return maxF;
    }
};
