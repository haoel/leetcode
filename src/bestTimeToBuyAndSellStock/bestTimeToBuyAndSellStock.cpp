// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*               
**********************************************************************************/

class Solution {
public:
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
