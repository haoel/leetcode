// Source : https://leetcode.com/problems/maximum-average-subarray-i/description/
// Author : Hao Chen
// Date   : 2018-04-19

/*************************************************************************************** 
 *
 * 
 * Given an array consisting of n integers, find the contiguous subarray of given 
 * length k that has the maximum average value. And you need to output the maximum 
 * average value.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: aximum average is (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * Note:
 * 
 * 1 k n 
 * Elements of the given array will be in the range [-10,000, 10,000].
 * 
 ***************************************************************************************/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0; i<k; i++ ) {
            sum += nums[i];
        }
        
        int s = sum;
        for (int i=k; i< nums.size(); i++) {
            s += nums[i];
            s -= nums[i-k];
            
            if (s > sum) {
                sum = s;
            }
        }
        return (double)sum/k;
    }
};

