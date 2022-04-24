// Source : https://leetcode.com/problems/third-maximum-number/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 22-04-2022

/***************************************************************************************************** 
 *
 * Given an integer array nums, return the third distinct maximum number in
 * this array. If the third maximum does not exist, return the maximum number.
 * 
 * Example 1:
 * 
 * Input: nums = [3,2,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2.
 * The third distinct maximum is 1.
 * 
 * Example 2:
 *
 * Input: nums = [1,2]
 * Output: 2
 * Explanation: 
 * The first distinct maximum is 2.
 * The second distinct maximum is 1.
 * The third distinct maximum does not exist, so the maximum (2) is returned instead.
 * 
 * Example 3:
 *
 * Input: nums = [2,2,3,1]
 * Output: 1
 * Explanation: 
 * The first distinct maximum is 3.
 * The second distinct maximum is 2 (both 2's are counted together since they have the same value).
 * The third distinct maximum is 1.
 * 
 * Constraints:
 * 
 *  1 <= nums.length <= 10^4
 *  -2^31 <= nums[i] <= 2^31 - 1
 * 
 * Explanation of the solution:
 * 
 * 1. We establish the three variables to the (Integer.MIN_VALUE - 1)
 * 
 * 2. We analyze the array 'nums' and we update the variables when a bigger number is found
 ******************************************************************************************************/

class Solution {
    public int thirdMax(int[] nums) {
        long max1 = -2147483649L, max2 = -2147483649L, max3 = -2147483649L;
        for(int i : nums){
            if(i>max1){
                if(i> max2){
                    if(i > max3){
                        max1 = max2;
                        max2 = max3;
                        max3 = i;
                    }else if(i!=max3 && i != max2){
                        max1 = max2;
                        max2 = i;
                    }
                }else if(i!=max1 && i!=max2){max1=i;}
            }
        }
        if(max1==-2147483649L){
            return (int)max3;
        }else{
            return (int)max1;
        }
    }
}
