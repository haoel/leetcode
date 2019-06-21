// Source : https://leetcode.com/problems/min-cost-climbing-stairs/
// Author : Hao Chen
// Date   : 2019-02-04

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
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            return minCostClimbingStairs02(cost); 
            return minCostClimbingStairs01(cost); 
        }
        int minCostClimbingStairs01(vector<int>& cost) {
            vector<int> dp(cost.size() , 0);
            dp[0] = cost[0];
            dp[1] = cost[1];
            for (int i=2; i<cost.size(); i++) {
                dp[i] = min( dp[i-1], dp[i-2] ) + cost[i];
            }
            return min(dp[dp.size()-1], dp[dp.size()-2]);
        }

        int minCostClimbingStairs02(vector<int>& cost) {
            int dp1 = cost[0], dp2 = cost[1];
            for (int i=2; i<cost.size(); i++) {
                int dp = min( dp1, dp2 ) + cost[i];
                dp1 = dp2;
                dp2 = dp;
            }
            return min (dp1, dp2);
        }
};
