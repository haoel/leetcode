// Source : https://leetcode.com/problems/two-city-scheduling/
// Author : Hao Chen
// Date   : 2019-04-21

/***************************************************************************************************** 
 *
 * There are 2N people a company is planning to interview. The cost of flying the i-th person to city 
 * A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].
 * 
 * Return the minimum cost to fly every person to a city such that exactly N people arrive in each 
 * city.
 * 
 * Example 1:
 * 
 * Input: [[10,20],[30,200],[400,50],[30,20]]
 * Output: 110
 * Explanation: 
 * The first person goes to city A for a cost of 10.
 * The second person goes to city A for a cost of 30.
 * The third person goes to city B for a cost of 50.
 * The fourth person goes to city B for a cost of 20.
 * 
 * The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 * 
 * Note:
 * 
 * 	1 <= costs.length <= 100
 * 	It is guaranteed that costs.length is even.
 * 	1 <= costs[i][0], costs[i][1] <= 1000
 ******************************************************************************************************/


class Solution {
private:
    static int diff(vector<int>& x) {
        return x[1] - x[0];
    }
    static bool cmpfunc(vector<int>& lhs, vector<int>& rhs) {
        return diff(lhs) > diff(rhs);
    }

public:
    // Just simply sort the array by comparing the different cost go to A city and B city
    // then the bigger difference would be in left and right side, and the smaller difference would be in the middle
    // We could simply let the first half go to A city, and the second half go to B city.
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmpfunc);
        int result = 0;
        int len = costs.size();
        for (int i=0; i<len/2; i++) {
            result += (costs[i][0] + costs[len-i-1][1]);
        }
        return result;
    }
};
