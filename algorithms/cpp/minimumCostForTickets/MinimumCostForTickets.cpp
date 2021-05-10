// Source : https://leetcode.com/problems/minimum-cost-for-tickets/
// Author : Hao Chen
// Date   : 2019-01-29

/***************************************************************************************************** 
 *
 * In a country popular for train travel, you have planned some train travelling one year in advance.  
 * The days of the year that you will travel is given as an array days.  Each day is an integer from 1 
 * to 365.
 * 
 * Train tickets are sold in 3 different ways:
 * 
 * 	a 1-day pass is sold for costs[0] dollars;
 * 	a 7-day pass is sold for costs[1] dollars;
 * 	a 30-day pass is sold for costs[2] dollars.
 * 
 * The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 
 * 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.
 * 
 * Return the minimum number of dollars you need to travel every day in the given list of days.
 * 
 * Example 1:
 * 
 * Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output: 11
 * Explanation: 
 * For example, here is one way to buy passes that lets you travel your travel plan:
 * On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 * On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
 * On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 * In total you spent $11 and covered all the days of your travel.
 * 
 * Example 2:
 * 
 * Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output: 17
 * Explanation: 
 * For example, here is one way to buy passes that lets you travel your travel plan:
 * On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
 * On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 * In total you spent $17 and covered all the days of your travel.
 * 
 * Note:
 * 
 * 	1 <= days.length <= 365
 * 	1 <= days[i] <= 365
 * 	days is in strictly increasing order.
 * 	costs.length == 3
 * 	1 <= costs[i] <= 1000
 * 
 ******************************************************************************************************/

class Solution {
private:
    int min(int x, int y){
        return x < y ? x : y;
    }
    int min(int x, int y, int z) {
        return min(min(x, y), z);
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        // Dynamic Programming
        vector<int> dp(days.size()+1, INT_MAX);

        // dp[i] is the minimal cost from Days[0] to Days[i]
        dp[0] = 0;
        dp[1] = min(costs[0], costs[1], costs[2]);

        for (int i = 2; i<= days.size(); i ++) {

            // the currnet day need at least min(1-day, 7days, 30days) from previous.
            int m = dp[i-1] + min(costs[0], costs[1], costs[2]);

            // Seprating the array to two parts.
            //     days[0] -> days[j] -> day[i]
            //
            // calculate the day[i] - day[j] whether can use 7-day pass or 30-day pass
            //
            // Traking the minimal costs, then can have dp[i] minimal cost

            int SevenDays = INT_MAX, ThrityDays = INT_MAX;
            for (int j=i-1; j>0; j--){
                int gaps = days[i-1] - days[j-1];
                if ( gaps < 7 )  {
                    // can use 7-days or 30-days ticket
                    SevenDays  = dp[j-1] + min(costs[1], costs[2]);
                } else if (gaps < 30 ) {
                    //can use 30-days tickets
                    ThrityDays = dp[j-1] + costs[2];
                } else {
                    break;
                }
                m = min(m, SevenDays, ThrityDays);
            }
            if ( dp[i] > m )  dp[i] = m;
        }
        
        return dp[dp.size()-1];    
    }
};
