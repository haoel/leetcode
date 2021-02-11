// Source : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Author : Hao Chen
// Date   : 2021-02-11

/***************************************************************************************************** 
 *
 * Given an array nums, return true if the array was originally sorted in non-decreasing order, then 
 * rotated some number of positions (including zero). Otherwise, return false.
 * 
 * There may be duplicates in the original array.
 * 
 * Note: An array A rotated by x positions results in an array B of the same length such that A[i] == 
 * B[(i+x) % A.length], where % is the modulo operation.
 * 
 * Example 1:
 * 
 * Input: nums = [3,4,5,1,2]
 * Output: true
 * Explanation: [1,2,3,4,5] is the original sorted array.
 * You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
 * 
 * Example 2:
 * 
 * Input: nums = [2,1,3,4]
 * Output: false
 * Explanation: There is no sorted array once rotated that can make nums.
 * 
 * Example 3:
 * 
 * Input: nums = [1,2,3]
 * Output: true
 * Explanation: [1,2,3] is the original sorted array.
 * You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 * 
 * Example 4:
 * 
 * Input: nums = [1,1,1]
 * Output: true
 * Explanation: [1,1,1] is the original sorted array.
 * You can rotate any number of positions to make nums.
 * 
 * Example 5:
 * 
 * Input: nums = [2,1]
 * Output: true
 * Explanation: [1,2] is the original sorted array.
 * You can rotate the array by x = 5 positions to begin on the element of value 2: [2,1].
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 100
 * 	1 <= nums[i] <= 100
 ******************************************************************************************************/

class Solution {
public:
    bool check(vector<int>& nums) {
        int len = nums.size();
        
        //deal with the rotated case - the first element is greater than last one
        bool rotate = (nums[0] >= nums[len-1]);
        
        for (int i = 0; i < len-1; i++) {
            if ( nums[i] <= nums[i+1] ) continue;
            
            if (rotate) {
                rotate = false;
                continue;
            }
            return false;
            
        }
        return true;
    }
};
