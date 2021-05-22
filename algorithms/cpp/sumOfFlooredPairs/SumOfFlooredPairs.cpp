// Source : https://leetcode.com/problems/sum-of-floored-pairs/
// Author : Hao Chen
// Date   : 2021-05-22

/***************************************************************************************************** 
 *
 * Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 
 * <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * The floor() function returns the integer part of the division.
 * 
 * Example 1:
 * 
 * Input: nums = [2,5,9]
 * Output: 10
 * Explanation:
 * floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
 * floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
 * floor(5 / 2) = 2
 * floor(9 / 2) = 4
 * floor(9 / 5) = 1
 * We calculate the floor of the division for every pair of indices in the array then sum them up.
 * 
 * Example 2:
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 49
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 10^5
 * 	1 <= nums[i] <= 10^5
 ******************************************************************************************************/

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const int MAX_NUM = 100001;
        int cnt[MAX_NUM] = {0};
        int maxn = 0;
        for(auto& n : nums) {
            cnt[n]++;
            maxn = max(maxn, n);
        }
        
        vector<vector<int>> stats;
        for(int i=1; i<MAX_NUM; i++) {
            if (cnt[i] > 0) {
                stats.push_back({i, cnt[i]});
            }
            cnt[i] += cnt[i-1];
        }
        
        const int MOD = 1e9+7;
        int result = 0;
        for(int i=0; i < stats.size(); i++) {
            int n = stats[i][0];
            int c = stats[i][1];

            for(int x=2; x <= maxn/n+1; x++) {
                int pre = (x-1) * n - 1; 
                int cur = min( x * n - 1, MAX_NUM-1);
                result = (result + (cnt[cur] - cnt[pre]) * long(x-1) * c) % MOD;      
            }
        }
        return result;
    }
};
