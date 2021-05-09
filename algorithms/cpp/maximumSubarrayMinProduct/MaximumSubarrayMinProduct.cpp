// Source : https://leetcode.com/problems/maximum-subarray-min-product/
// Author : Hao Chen
// Date   : 2021-05-09

/***************************************************************************************************** 
 *
 * The min-product of an array is equal to the minimum value in the array multiplied by the array's 
 * sum.
 * 
 * 	For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 
 * 10 = 20.
 * 
 * Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. 
 * Since the answer may be large, return it modulo 10^9 + 7.
 * 
 * Note that the min-product should be maximized before performing the modulo operation. Testcases are 
 * generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,2]
 * Output: 14
 * Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
 * 2 * (2+3+2) = 2 * 7 = 14.
 * 
 * Example 2:
 * 
 * Input: nums = [2,3,3,1,2]
 * Output: 18
 * Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
 * 3 * (3+3) = 3 * 6 = 18.
 * 
 * Example 3:
 * 
 * Input: nums = [3,1,5,6,4,2]
 * Output: 60
 * Explanation: The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
 * 4 * (5+6+4) = 4 * 15 = 60.
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 10^5
 * 	1 <= nums[i] <= 10^7
 ******************************************************************************************************/

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        nums.push_back(0); //edge case
        
        //prefix sum
        vector<long> sums(nums.size(), 0);
        // sums[i] = sum (num[0], num[1], num[2], ... num[n-1])
        // sums[m] - sums[n] = sum (num[n], sum[n+1] .... nums[m-1]);  m > n
        for(int i=0; i<nums.size()-1; i++) {
            sums[i+1] = sums[i] + nums[i];
        }
        
        stack<int> s;
        long m = 0;
        for(int i=0; i<nums.size(); i++) {
            while( !s.empty() && nums[s.top()] > nums[i]) {
                int min = nums[s.top()]; s.pop();
                int start = s.empty() ? 0 : s.top() + 1;
                int end = i;
                m = max(m , min * (sums[end] - sums[start]));
                
                // cout << "[";
                // for(int k = start; k < end-1; k++) {
                //    cout << nums[k] << ",";
                // }
                // cout << nums[end-1] << "], " << min << "*" << (sums[end] - sums[start]) 
                //     << "=" << min * (sums[end] - sums[start]) << endl;
                
            }
            // if the num is increasing, then push into stack
            s.push(i);
        }
        //cout << endl;
        return m % 1000000007;
        
    }
};
