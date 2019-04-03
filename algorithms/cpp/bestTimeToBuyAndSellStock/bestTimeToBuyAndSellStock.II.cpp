// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : Hao Chen
// Date   : 2014-06-18

/***************************************************************************************************** 
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 * (i.e., buy one and sell one share of the stock multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock 
 * before you buy again).
 * 
 * Example 1:
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *              engaging multiple transactions at the same time. You must sell before buying again.
 * 
 * Example 3:
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 ******************************************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit02(prices);
        return maxProfit01(prices);
    }
    // Solution 1 
    // find all of ranges: which start a valley with the nearest peak after
    // add their delta together 
    //
    int maxProfit01(vector<int> &prices) {

        int max = 0;
        int low = -1;
	int len = prices.size();
        for (int i=0; i < len - 1; i++){
            //meet the valley, then goes up
            if (prices[i] < prices[i+1] && low < 0 ) {
                low = i;
            }
            //meet the peak, then goes down
            if (prices[i] > prices[i+1] && low >= 0) {
                max += ( prices[i] - prices[low] ) ;
                low = -1; // reset the `low`
            }
        }

        // edge case
        if ( low >= 0 ) {
            max += ( prices[prices.size()-1] - prices[low] );
        }

        return max;
    }

    // Solution 2 
    // if we find we can earn money, we just sell
    int maxProfit02(vector<int>& prices) {
        int profit = 0 ;
        for(int i=1; i< prices.size(); i++) {
            profit += max(0, prices[i] - prices[i-1]);
        }
        return profit;
    }
};
