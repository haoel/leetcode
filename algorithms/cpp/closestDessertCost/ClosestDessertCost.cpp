// Source : https://leetcode.com/problems/closest-dessert-cost/
// Author : Hao Chen
// Date   : 2021-03-14

/***************************************************************************************************** 
 *
 * You would like to make dessert and are preparing to buy the ingredients. You have n ice cream base 
 * flavors and m types of toppings to choose from. You must follow these rules when making your 
 * dessert:
 * 
 * 	There must be exactly one ice cream base.
 * 	You can add one or more types of topping or have no toppings at all.
 * 	There are at most two of each type of topping.
 * 
 * You are given three inputs:
 * 
 * 	baseCosts, an integer array of length n, where each baseCosts[i] represents the price of 
 * the ith ice cream base flavor.
 * 	toppingCosts, an integer array of length m, where each toppingCosts[i] is the price of one 
 * of the ith topping.
 * 	target, an integer representing your target price for dessert.
 * 
 * You want to make a dessert with a total cost as close to target as possible.
 * 
 * Return the closest possible cost of the dessert to target. If there are multiple, return the lower 
 * one.
 * 
 * Example 1:
 * 
 * Input: baseCosts = [1,7], toppingCosts = [3,4], target = 10
 * Output: 10
 * Explanation: Consider the following combination (all 0-indexed):
 * - Choose base 1: cost 7
 * - Take 1 of topping 0: cost 1 x 3 = 3
 * - Take 0 of topping 1: cost 0 x 4 = 0
 * Total: 7 + 3 + 0 = 10.
 * 
 * Example 2:
 * 
 * Input: baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
 * Output: 17
 * Explanation: Consider the following combination (all 0-indexed):
 * - Choose base 1: cost 3
 * - Take 1 of topping 0: cost 1 x 4 = 4
 * - Take 2 of topping 1: cost 2 x 5 = 10
 * - Take 0 of topping 2: cost 0 x 100 = 0
 * Total: 3 + 4 + 10 + 0 = 17. You cannot make a dessert with a total cost of 18.
 * 
 * Example 3:
 * 
 * Input: baseCosts = [3,10], toppingCosts = [2,5], target = 9
 * Output: 8
 * Explanation: It is possible to make desserts with cost 8 and 10. Return 8 as it is the lower cost.
 * 
 * Example 4:
 * 
 * Input: baseCosts = [10], toppingCosts = [1], target = 1
 * Output: 10
 * Explanation: Notice that you don't have to have any toppings, but you must have exactly one base.
 * 
 * Constraints:
 * 
 * 	n == baseCosts.length
 * 	m == toppingCosts.length
 * 	1 <= n, m <= 10
 * 	1 <= baseCosts[i], toppingCosts[i] <= 104
 * 	1 <= target <= 104
 ******************************************************************************************************/

class Solution {
private:
    int abs_min (int x, int y, int z) {
        return  abs_min(x, abs_min(y, z));
    }
    // compare the absolute value and return the min one
    // if their absolute value are equal, return the positive one.
    int abs_min(int x, int y) {
        int ax = abs(x);
        int ay = abs(y);
        if (ax == ay) return max(x, y);
        return ax < ay ? x : y;
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {

        int min_gap = INT_MAX;
        for (auto& base : baseCosts) {
            int gap = closetToppingCost(toppingCosts, target - base, 0);
            min_gap = abs_min(min_gap, gap);
        }
        
        return target - min_gap;
    }
    
    int closetToppingCost(vector<int>& costs, int target, int idx ){
    
        if (idx >= costs.size()) return target;

        // three options: not slect, select once & select twice
        int select_none  = closetToppingCost(costs, target, idx+1);
        int select_once  = closetToppingCost(costs, target - costs[idx], idx+1);
        int select_twice = closetToppingCost(costs, target - 2*costs[idx], idx+1);
        
        return abs_min(select_none, select_once, select_twice);
    }
    
};
