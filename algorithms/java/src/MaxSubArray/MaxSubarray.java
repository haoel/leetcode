// Source : https://leetcode.com/problems/maximum-subarray/
// Author : Ikshit Agrawal
// Date   : 2020-10-04
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Example 1:
		Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
		Output: 6
		Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
		Input: nums = [1]
		Output: 1
*/
class Solution {
    public int maxSubArray(int[] nums) {
     int max1=nums[0],cur=0;
        for(int i :nums)
        {
            if(cur<0)
                cur=0;
            cur+=i;
            max1=Math.max(max1,cur);
        }
        return max1;
    }
}
