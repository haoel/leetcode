// Source : https://leetcode.com/problems/coin-change-2/
// Author : Hao Chen
// Date   : 2019-03-18

/***************************************************************************************************** 
 *
 * You are given coins of different denominations and a total amount of money. Write a function to 
 * compute the number of combinations that make up that amount. You may assume that you have infinite 
 * number of each kind of coin.
 * 
 * Example 1:
 * 
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * Example 2:
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * Example 3:
 * 
 * Input: amount = 10, coins = [10] 
 * Output: 1
 * 
 * Note:
 * 
 * You can assume that
 * 
 * 	0 <= amount <= 5000
 * 	1 <= coin <= 5000
 * 	the number of coins is less than 500
 * 	the answer is guaranteed to fit into signed 32-bit integer
 * 
 ******************************************************************************************************/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return change_dp(amount, coins);
        return change_recursive(amount, coins); // Time Limit Error
    }
    
    
    int change_recursive(int amount, vector<int>& coins) {
        int result = 0;
        change_recursive_helper(amount, coins, 0, result);
        return result;
    }
    
    // the `idx` is used for remove the duplicated solutions.
    void change_recursive_helper(int amount, vector<int>& coins, int idx, int& result) {
        if (amount == 0) { 
            result++; 
            return;
        }
    
        for ( int i = idx; i < coins.size(); i++ ) {
            if (amount < coins[i]) continue;
            change_recursive_helper(amount - coins[i], coins, i, result);
        }
        return;
    }
    
    int change_dp(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int i=0; i<coins.size(); i++) {
            for(int n=1; n<=amount; n++) {
                if (n >= coins[i]) {
                    dp[n] += dp[n-coins[i]];
                }
            }
        }

        return dp[amount];
    }
};

