// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Author : Hao Chen
// Date   : 2015-03-31

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete at most k transactions.
* 
* Note:
* You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
* 
* Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
*               
**********************************************************************************/

class Solution {
public:
    /*
     *  dp[i, j]
     *    - `i` represents the number of transactions we've done so far. ( 0 <= i <= k )
     *    - `j` represents the number of days so far. ( 0 <= j <= prices.size() )
     *  
     *  So, we have the initialization as below:
     *
     *  dp[0, j] = 0; // 0 <= j <= prices.size() 
     *  dp[i, 0] = 0; // 0 <= i <= k
     *  
     *  And the iteration logic as below:
     *  
     *  dp[i, j] = max ( 
     *               dp[i, j-1], // same times transactions, but one days before.    
     *               dp[i-1, t] + prices[j] - prices[t+1]  // for all of (0 <= t < j )
     *                                                     // this means find max profit from previous any of days
     *           )
     *  
     */

    int maxProfit(int k, vector<int> &prices) {
        int ndays = prices.size();
        
        // error case
        if (ndays<=1) return 0;
        
        // Edge case
        // ---------
        // if the number of transactions is too many, it means we can make 
        // as many transactions as we can, that brings us the problem back to 
        // Best-Time-To-Buy-And-Sell-Stock-II which can be simply solve in O(n) 
        // by using a greedy approach.
        if(k > ndays/2){
            int sum = 0;
            for (int i=1; i<ndays; i++) {
                sum += max(prices[i] - prices[i-1], 0);
            }
            return sum;
        }
        
        //DP solution - O(kn) complexity 
        vector< vector<int> > dp (k+1, vector<int>( ndays+1, 0));
        
        for(int i=1; i<=k; i++) {
            int t = dp[i-1][0] - prices[0];
            for (int j=1; j <= ndays; j++) {
                dp[i][j] = max(dp[i][j-1], t + prices[j-1]);
                if ( j < ndays ) {
                    t = max(t, dp[i-1][j] - prices[j]);
                }
            }
        }
        
        return dp[k][ndays];
        
    }
};
