/****
 * Solution of https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @author: Jerry Zou
 * @date: 2015.6.4
 **/

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var current = 0,
        buyDay = 0,
        sellDay = 0,
        max = 0;
    
    while (current < prices.length) {
        if (prices[sellDay] < prices[current]) {
            sellDay = current;
        } else if (prices[buyDay] > prices[current]) {
            buyDay = current;
            sellDay = current;
        }
        if (prices[sellDay] - prices[buyDay] > max) {
            max = prices[sellDay] - prices[buyDay];
        }
        current++;
    }

    return max;
};