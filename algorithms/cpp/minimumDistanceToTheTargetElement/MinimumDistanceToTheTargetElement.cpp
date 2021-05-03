// Source : https://leetcode.com/problems/minimum-distance-to-the-target-element/
// Author : Hao Chen
// Date   : 2021-05-03

/***************************************************************************************************** 
 *
 * Given an integer array nums (0-indexed) and two integers target and start, find an index i such 
 * that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.
 * 
 * Return abs(i - start).
 * 
 * It is guaranteed that target exists in nums.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,4,5], target = 5, start = 3
 * Output: 1
 * Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
 * 
 * Example 2:
 * 
 * Input: nums = [1], target = 1, start = 0
 * Output: 0
 * Explanation: nums[0] = 1 is the only value equal to target, so the answer is abs(0 - 0) = 1.
 * 
 * Example 3:
 * 
 * Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
 * Output: 0
 * Explanation: Every value of nums is 1, but nums[0] minimizes abs(i - start), which is abs(0 - 0) = 
 * 0.
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 1000
 * 	1 <= nums[i] <= 10^4
 * 	0 <= start < nums.length
 * 	target is in nums.
 ******************************************************************************************************/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDist = nums.size();
        for(int i=start; i < nums.size(); i++){
            if ( target == nums[i] ) {
                minDist = i - start;
                break;
            } 
        }

        for (int i=start; i>=0; i--) {
            if ( target == nums[i] && start - i <= minDist) {
                minDist = start - i;
                break;
            }
        }
        return minDist;
    }
};
