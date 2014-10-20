// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author : Hao Chen
// Date   : 2014-08-22


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()<=1) return 0;
        
        int n = prices.size();
        
        vector<int> forward(n);
        forward[0] = 0;
        int lowestBuyInPrice = prices[0];
        for(int i=1; i<n; i++){
            forward[i] = max(forward[i-1], prices[i] - lowestBuyInPrice);
            lowestBuyInPrice = min(lowestBuyInPrice, prices[i]);
        }
        
        vector<int> backward(n);
        backward[n-1] = 0;
        int highestSellOutPrice = prices[n-1];
        for(int i=n-2; i>=0; i--){
            backward[i] = max(backward[i+1], highestSellOutPrice - prices[i]);
            highestSellOutPrice = max(highestSellOutPrice, prices[i]);
        }
        
        int max_profit = 0;
        for(int i=0; i<n; i++){
            max_profit = max(max_profit, forward[i]+backward[i]);
        }
        
        return max_profit;
    }
};
