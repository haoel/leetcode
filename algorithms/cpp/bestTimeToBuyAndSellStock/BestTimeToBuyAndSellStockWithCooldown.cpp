// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Author : Hao Chen
// Date   : 2019-02-01

/***************************************************************************************************** 
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 * (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 * 
 * 	You may not engage in multiple transactions at the same time (ie, you must sell the stock 
 * before you buy again).
 * 	After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * 
 * Example:
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 ******************************************************************************************************/

class Solution {
public:
    //
    //Define 
    //
    //  - buy[i] as the max profit when you buy the stock at day i. 
    //  - sell[i] as the max profit when you sell the stock at day i. 
    //
    // Therefore set buy[0] = -prices[0], because spend the money, the profit is -prices[0].
    // Also set sell[0] = 0, that you do nothing in the first day.
    //
    // So,
    //
    //   sell[i] = max ( buy[i-1] + prices[i],
    //                   sell[i-1] - prices[i-1] + prices[i] );
    //
    //   - buy[i-1]+prices[i] represents buy the stock on day i-1 and sell it on day i; 
    //   - sell[i-1]-prices[i-1]+prices[i] represents you didn't sell the stock on day i-1 
    //     but sell it on day i (bought stock back and sell it on day i).
    //
    //
    //  buy[i] = max ( sell[i-2] - prices[i], 
    //                 buy[i-1] + prices[i-1] - prices[i] );
    //
    //  - sell[i-2]-prices[i] means sold the stock on day i-2 and buy it on day i 
    //    (day i-1 is cooldown). 
    //  - buy[i-1]+prices[i-1]-prices[i] means you didn't buy the stock on day i-1 
    //    but buy it on day i.
    //

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if ( len < 2 ) return 0;
        vector<int> buy(len, 0);
        vector<int> sell(len, 0);
        
        buy[0] = -prices[0];
        
        int profit = 0;
        
        for (int i=1; i<len; i++) {
            sell[i] = max ( buy[i-1] + prices[i],
                            sell[i-1] - prices[i-1] + prices[i] );
            profit = max(profit, sell[i]);
            if ( i == 1) {
                buy[i] = buy[0] + prices[0] - prices[1];
            } else {
                buy[i] = max ( sell[i-2] - prices[i],
                               buy[i-1] + prices[i-1] - prices[i] );
            }
            
        }
        
        return profit;
    }
};
