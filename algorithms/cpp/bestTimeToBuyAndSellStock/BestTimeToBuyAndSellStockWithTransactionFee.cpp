// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
// Author : Hao Chen
// Date   : 2019-02-01

/***************************************************************************************************** 
 *
 * Your are given an array of integers prices, for which the i-th element is the price of a given 
 * stock on day i; and a non-negative integer fee representing a transaction fee.
 *
 * You may complete as many transactions as you like, but you need to pay the transaction fee for each 
 * transaction.  You may not buy more than 1 share of a stock at a time (ie. you must sell the stock 
 * share before you buy again.)
 *
 * Return the maximum profit you can make.
 * 
 * Example 1:
 * 
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 *
 * Explanation: The maximum profit can be achieved by:
 * Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] = 4Selling at prices[5] = 9The 
 * total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * Note:
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
 ******************************************************************************************************/



class Solution {
private:
    int max(int x, int y) {
        return x > y ? x: y;
    }
    int max(int x, int y, int z) {
        return max(x, max(y,z));
    }

public:

    int maxProfit(vector<int>& prices, int fee) {
        return maxProfit_dp03(prices, fee); // 100ms
        return maxProfit_dp02(prices, fee); // 100ms
        return maxProfit_dp01(prices, fee); // 2700ms
    }

    // find the [buy-low, sell-high] prices pairs,
    // and remove the unnecessary prices.
    void genPricesPairs(vector<int> &prices, vector< pair<int, int> > &prices_pairs, int fee){

        int low = -1;
        for (int i=0; i<prices.size()-1; i++){
            //meet the valley, then goes up
            if (prices[i] < prices[i+1] && low < 0 ) {
                low = i;
            }
            //meet the peak, then goes down
            if (prices[i] > prices[i+1] && low >= 0) {
                prices_pairs.push_back( make_pair( prices[low], prices[i]) );
                low = -1; // reset the `low` & `high`
            }
        }

        // edge case
        if ( low >= 0 ) {
            prices_pairs.push_back( make_pair( prices[low], prices[prices.size()-1] ) );
        }

    }

    int maxProfit_dp01(vector<int> &prices, int &fee) {

        vector< pair<int, int> > prices_pairs;
        genPricesPairs(prices, prices_pairs, fee);

        vector<int> dp(prices_pairs.size()+1, 0);

        for (int i=0; i<prices_pairs.size(); i++) {
            for ( int j=0; j<=i; j++ ) {
                int profit = prices_pairs[i].second - prices_pairs[j].first - fee;
                // if the profit is negative, skip the transaction
                if ( profit < 0 ) profit = 0;
                dp[i+1] = max ( dp[i+1], dp[j] + profit);
            }
        }

        return dp[dp.size()-1];
    }

    int maxProfit_dp02(vector<int> &prices, int &fee) {

        vector< pair<int, int> > prices_pairs;
        genPricesPairs(prices, prices_pairs, fee);

        if ( prices_pairs.size() < 1 ) return 0;


        // first - represent  the max profit if we buy.
        // second - represent the max profit if we sell.
        vector< pair<int,int> > dp(prices_pairs.size() , make_pair(0,0) );

        //buy profit - if we buy it in day 0, then we got negtive profit.
        dp[0].first = - prices_pairs[0].first;

        //sell profit - if we sell it in day 0, then we have the profits
        //              if the profit is negtive, then won't sell it.
        dp[0].second = max(0, prices_pairs[0].second - prices_pairs[0].first - fee);

        for (int i=1; i<prices_pairs.size(); i++) {
            // BUY - we could have three options
            //   1) hold the stock do nothing.  profit = previous day's buy profit
            //   2) sell & buy. profit = previous sell profit - spent money to buy.
            //   3) fresh buy, give up the pervious buy, just buy it today.
            // find the max profit of these 3 options.

            dp[i].first = max (dp[i-1].first,                          // option 1) do nothing
                               dp[i-1].second - prices_pairs[i].first, // option 2) sell & buy
                               - prices_pairs[i].first );              // option 3) fresh buy

            // SELL - we could have three options
            //   1) hold the stock do nothing. profit = previous day's sell profit
            //   2) sell it. profit = previous day's buy + today's sell.
            //   3) sell previous and sell today. profit = previous's sell + today's sell
            // Find the max profit of these 3 options
            dp[i].second = max(dp[i-1].second,
                               dp[i-1].first + prices_pairs[i].second - fee,
                               dp[i-1].second + prices_pairs[i].second - prices_pairs[i].first - fee );
        }

        return max( dp[dp.size()-1].second, 0 );

    }

    //
    // Actually, by given any day, we can have two status:
    // 1) BUY status - we can have two options at Day X.
    //     i) buy stock - need previous sell status.(you cannot buy if you haven't sold)
    //    ii) do nothing - need previous buy status.
    //
    // 2) SELL status - we can have two options at Day X.
    //     i) sell stock - need previous buy status.(you cannot sell if you haven't bought)
    //    ii) do nothing - keep the previous sell status.
    //
    // For example:
    //
    //    if we have [1,3,2,8,4,9], fee = 2
    //    then we could have the following BUY & SELL status
    //
    //    Day One
    //        1 - BUY: the profit is -1 ,becuase we spent 1 money
    //            SELL: you cannot sell, the profit is 0.
    //    Day Two
    //        3 - BUY : pre-SELL - 3 = -3, but do nothing has max profit pre-BUY: -1
    //            SELL: pre-BUY + 3 -2 = -1+3-2 = 0 , the max profit: 0
    //    Day Three
    //        2 - BUY : pre-SELL - 2 = 0 - 2 = -2, do nothing has max profit: -1
    //            SELL: pre-BUY + 2 -2 = -1 + 2 -2 = -1, do nothing has max profit: 0
    //    Day Four
    //        8 - BUY : pre-SELL - 8 =  0 - 8 = -8, so, just hold, the max buy profit: -1
    //            SELL: pre-BUY + 8 - 2 = -1+8-2 =5, the max profit is 5
    //    Day Five
    //        4 - BUY : pre-SELL - 4 = 5-4 = 1, do nothing profit is -1, so should buy it.
    //                  so, the max buy profit is 1.
    //            SELL: pre-BUY + 4 -2 = -1 + 4 -2= 1, it's has lower profit than previous,
    //                  so, we won't sell, the max sell profit is 5.
    //    Day Six
    //        9 - BUY : pre-SELL - 9 = 5-9= -4, so won't buy, the max buy profit is 1.
    //            SELL: pre-BUY + 9 -2 = 1 + 9 -2 = 8, it's has higher profit. so we sell
    //
    //   Let's use an table
    //
    //            prices =   1,  3,  2,  8,  4,  9
    //    max buy profit =  -1, -1, -1, -1,  1,  5
    //   max sell profit =   0,  0,  0,  5,  5,  8
    //
    //   We can see we keep tracking the max buy and sell profit for everyday.
    //
    //       buy[i] = max( buy[i-1],                // do nothing
    //                     sell[i-1] - prices[i] ); // sell in previous day can buy today
    //
    //       sell[i] = max( sell[i-1],                    // do nothing
    //                      buy[i-1] + prices[i] - fee ); // sell today
    //
    int maxProfit_dp03(vector<int> &prices, int &fee) {
        int buy=-prices[0], sell=0;
        int pre_buy=0, pre_sell=0;

        for(auto price: prices) {
            pre_buy = buy;
            buy = max (sell - price, pre_buy);

            pre_sell = sell;
            sell = max( pre_buy + price - fee, pre_sell);
        }

        return sell;
    }
};
