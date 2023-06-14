// Source : https://leetcode.com/problems/min-cost-climbing-stairs/
// Author : Sunny Lin
// Date   : 2023-06-12

/***************************************************************************************************** 
 *
 * 
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * 
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to 
 * reach the top of the floor, and you can either start from the step with index 0, or the step with 
 * index 1.
 * 
 * Example 1:
 * 
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 * 
 * Example 2:
 * 
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 * 
 * Note:
 * 
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 * 
 ******************************************************************************************************/
#include <vector>
using namespace std;

class Solution {
    public:
        int minCost(int i, vector<int> & cost, vector<int>& dp){
            if(i < 0) return 0;
            if(i  == 0 or i == 1) return cost[i];
            if(dp[i] != NULL) return dp[i];
            dp[i] = cost[i] + min(minCost(i-1, cost, dp), minCost(i-2, cost, dp));
            return dp[i];
        }

        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            vector<int> dp(n);
            return min(minCost(n-1, cost, dp), minCost(n-2, cost, dp));
        }
        
};
