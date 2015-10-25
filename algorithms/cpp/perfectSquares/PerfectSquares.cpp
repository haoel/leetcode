// Source : https://leetcode.com/problems/perfect-squares/
// Author : Hao Chen
// Date   : 2015-10-25

/*************************************************************************************** 
 *
 * Given a positive integer n, find the least number of perfect square numbers (for 
 * example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 
 * because 13 = 4 + 9.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 ***************************************************************************************/


class Solution {
public:

    int numSquares(int n) {
        return numSquares_dp_opt(n); //12ms
        return numSquares_dp(n); //232ms
    }
    
    /*
     * Dynamic Programming
     * ===================
     *   dp[0] = 0 
     *   dp[1] = dp[0]+1 = 1
     *   dp[2] = dp[1]+1 = 2
     *   dp[3] = dp[2]+1 = 3
     *   dp[4] = min{ dp[4-1*1]+1, dp[4-2*2]+1 } 
     *         = min{ dp[3]+1, dp[0]+1 } 
     *         = 1               
     *   dp[5] = min{ dp[5-1*1]+1, dp[5-2*2]+1 } 
     *         = min{ dp[4]+1, dp[1]+1 } 
     *         = 2
     *   dp[6] = min{ dp[6-1*1]+1, dp[6-2*2]+1 } 
     *         = min{ dp[5]+1, dp[2]+1 } 
     *         = 3
     *   dp[7] = min{ dp[7-1*1]+1, dp[7-2*2]+1 } 
     *         = min{ dp[6]+1, dp[3]+1 } 
     *         = 4
     *   dp[8] = min{ dp[8-1*1]+1, dp[8-2*2]+1 } 
     *         = min{ dp[7]+1, dp[4]+1 } 
     *         = 2
     *   dp[9] = min{ dp[9-1*1]+1, dp[9-2*2]+1, dp[9-3*3] } 
     *         = min{ dp[8]+1, dp[5]+1, dp[0]+1 } 
     *         = 1
     *   dp[10] = min{ dp[10-1*1]+1, dp[10-2*2]+1, dp[10-3*3] } 
     *          = min{ dp[9]+1, dp[6]+1, dp[1]+1 } 
     *          = 2
     *                           ....
     *
     *   So, the dynamic programm formula is
     *   
     *      dp[n] = min{ dp[n - i*i] + 1 },  n - i*i >=0 && i >= 1
     *
     */
    int numSquares_dp(int n) {
        if ( n <=0 ) return 0;
        
        int *dp = new int[n+1];
        dp[0] = 0;
        
        for (int i=1; i<=n; i++ ) {
            int m = n;
            for (int j=1; i-j*j >= 0; j++) {
                m = min (m, dp[i-j*j] + 1);
            }
            dp[i] = m;
        }
    
        return dp[n];
        delete [] dp;
    }
    
    //using cache to optimize the dp algorithm
    int numSquares_dp_opt(int n) {
        if ( n <=0 ) return 0;
        
        static vector<int> dp(1, 0);
        if (dp.size() >= (n+1) ) return dp[n];
        
        for (int i=dp.size(); i<=n; i++ ) {
            int m = n;
            for (int j=1; i-j*j >= 0; j++) {
                m = min (m, dp[i-j*j] + 1);
            }
            dp.push_back(m);
        }
    
        return dp[n];
    }
};

