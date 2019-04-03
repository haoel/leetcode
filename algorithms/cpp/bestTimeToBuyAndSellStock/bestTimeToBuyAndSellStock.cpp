// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Hao Chen
// Date   : 2014-06-18

/***************************************************************************************************** 
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of 
 * the stock), design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * Example 2:
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 ******************************************************************************************************/

class Solution {
public:
    //
    // This solution is O(1) space dynamic programming 
    //
    // We can make sure the max profit at least be ZERO. So,
    //    1) we have two pointers (begin & end ) 
    //    2) if prices[end] - prices[begin] >  0, then move the "end" pointer to next
    //    3) if prices[end] - prices[begin] <= 0, then move the "begin" pointer to current posstion.
    //    4) tracking the max profit
    //
    // Notes:
    //    Some people think find the highest-price & lowest-price, this is wrong. 
    //    Because the highest-price must be after lowest-price
    //
    int maxProfit(vector<int> &prices) {
        
        int max=0, begin=0, end=0, delta=0;
        
        for (int i=0; i<prices.size(); i++) {
            
            end = i;
            
            delta = prices[end] - prices[begin];
            
            if (delta <= 0){
                begin = i;
            }
            
            if ( delta > max ){
                max = delta;
            }
            
        }
        
        return max;
        
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for (auto p : prices) {
    	    // Keep tracking the previous lowest price
            buy = min (buy, p);
	    // Keep tacking the current max profit
            profit = max(profit, p - buy);
        }
        return profit;
    }
};
