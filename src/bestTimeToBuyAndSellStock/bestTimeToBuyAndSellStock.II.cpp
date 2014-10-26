// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete as many transactions 
* as you like (ie, buy one and sell one share of the stock multiple times). However, 
* you may not engage in multiple transactions at the same time (ie, you must sell the 
* stock before you buy again).
*               
**********************************************************************************/

class Solution {
public:
    //
    // find all of ranges: which start a valley with the nearest peak after
    // add their delta together 
    //
    int maxProfit(vector<int> &prices) {
        int max=0, begin=0, end=0;
        bool up=false, down=false;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > prices[i-1] && up==false){ // goes up
                begin = i-1;
                up = true;
                down = false;
            }
            
            if (prices[i] < prices[i-1] && down==false) { // goes down
                end = i-1;
                down = true;
                up = false;
                max += (prices[end] - prices[begin]);
            }
        }
        // edge case 
        if (begin < prices.size() && up==true){
            end = prices.size() - 1;
            max += (prices[end] - prices[begin]);
        }
        
        return max;
    }
};
