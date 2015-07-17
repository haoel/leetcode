// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
* design an algorithm to find the maximum profit.
*               
**********************************************************************************/

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
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0) return 0;
        int MAX=0, MIN=prices[0];
        for (int i=0; i<prices.size(); i++) {
            MIN = min(MIN, prices[i]);
            MAX = max(MAX, prices[i] - MIN);
        }
        return MAX;
    }
};
