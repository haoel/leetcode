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
    //     buy[i] = max(buy[i-1],                // do nothing - keep holding
    //                  sell[i-2] - prices[i] )  // sell previous day, buy today
    //                                           // i-1 is cooldown day
    //     sell[i] = max(sell[i-1],              // do nothing 
    //                   buy[i-1] + prices[i] )  // buy previous day, sell today.
    //  
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if ( len < 2 ) return 0;
        
        vector<int> buy(len, 0);
        vector<int> sell(len, 0);
        
        //day 0
        buy[0] = -prices[0];
        sell[0] = 0;
        
        //day 1
        buy[1] = max(buy[0], 0 - prices[1]);
        sell[1] = max(sell[0], buy[0] + prices[1]);
        
        for (int i=2; i<len; i++) {
            buy[i]  = max( buy[i - 1], sell[i - 2] - prices[i]);   
            sell[i] = max(sell[i - 1],  buy[i - 1] + prices[i]);
        }
        
        return sell[len-1];
    }
};
