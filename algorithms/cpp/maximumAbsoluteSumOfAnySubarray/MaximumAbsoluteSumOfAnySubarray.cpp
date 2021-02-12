// Source : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
// Author : Hao Chen
// Date   : 2021-02-12

/***************************************************************************************************** 
 *
 * You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, 
 * numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
 * 
 * Return the maximum absolute sum of any (possibly empty) subarray of nums.
 * 
 * Note that abs(x) is defined as follows:
 * 
 * 	If x is a negative integer, then abs(x) = -x.
 * 	If x is a non-negative integer, then abs(x) = x.
 * 
 * Example 1:
 * 
 * Input: nums = [1,-3,2,3,-4]
 * Output: 5
 * Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
 * 
 * Example 2:
 * 
 * Input: nums = [2,-5,1,-4,3,-2]
 * Output: 8
 * Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 105
 * 	-104 <= nums[i] <= 104
 ******************************************************************************************************/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        return maxAbsoluteSum02(nums); //56ms
        return maxAbsoluteSum01(nums); //56ms
    }
    
    
    
    int maxAbsoluteSum01(vector<int>& nums) {
        return std::max(maxSumArray(nums), std::abs(minSumArray(nums)) );
    }
    
    //https://en.wikipedia.org/wiki/Maximum_subarray_problem
    int maxSumArray(vector<int>& nums) {
        int max = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0 ) sum = nums[i];
            else sum += nums[i];
            if (max < sum) max = sum;
        }
        return max;
    }
    
    int minSumArray(vector<int>& nums) {
        int min = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum > 0 ) sum = nums[i];
            else sum += nums[i];
            if (min > sum) min = sum;
        }
        return min;
    }
    
    // Becasue maxSumArray() & minSumArray() are two similar,
    // we can merge them together to save one loop
    int maxAbsoluteSum02(vector<int>& nums) {
        int max = nums[0];
        int max_sum = nums[0];
        
        int min = nums[0];
        int min_sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            
            if (max_sum < 0 ) max_sum = nums[i];
            else max_sum += nums[i];
            if (max < max_sum) max = max_sum;
            
            
            if (min_sum > 0 ) min_sum = nums[i];
            else min_sum += nums[i];
            if (min > min_sum) min = min_sum;
            
        }
        
        return std::max(max, abs(min));
    }
    
};
