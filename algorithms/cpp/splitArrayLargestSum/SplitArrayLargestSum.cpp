// Source : https://leetcode.com/problems/split-array-largest-sum/
// Author : Hao Chen
// Date   : 2016-11-13

/*************************************************************************************** 
 *
 * Given an array which consists of non-negative integers and an integer m, you can 
 * split the array into m non-empty continuous subarrays. Write an algorithm to 
 * minimize the largest sum among these m subarrays.
 * 
 * Note:
 * Given m satisfies the following constraint: 1 ≤ m ≤  length(nums) ≤ 14,000.
 * 
 * Examples: 
 * 
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 * 
 * Output:
 * 18
 * 
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 ***************************************************************************************/

class Solution {
public:
    // Idea
    //   1) The max of the result is the sum of the whole array.
    //   2) The min of the result is the max num among the array.
    //   3) Then, we use Binary Search to find the resullt between the `min` and  the `max`
    
    int splitArray(vector<int>& nums, int m) {
        int min = 0, max = 0;
        for (int n : nums) {
            min = std::max(min, n);
            max += n;
        }
        while (min < max) {
            int mid = min + (max - min) / 2;
            if (hasSmallerSum(nums, m, mid)) max = mid;
            else min = mid + 1;
        }
        return min;
    }
    
    
    // Using a specific `sum` to check wheter we can get `smaller sum`
    // The idea here as below:
    //   find all of possible `sub array` whose sum greater than `sum`
    //   1) if the number of `sub array` >  m, whcih means the actual result is greater than `sum`
    //   2) if the number of `sub array` <= m, whcih means we can have `smaller sum`
    //
    bool hasSmallerSum(vector<int>& nums, int m, int sum) {
        int cnt = 1, curSum = 0;
        for (int n : nums) {
            curSum += n;
            if (curSum > sum) {
                curSum = n;
                cnt++;
                if (cnt > m) return false;
            }
        }
        return true;
    }
};
