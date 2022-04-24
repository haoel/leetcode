// Source : https://leetcode.com/problems/sign-of-the-product-of-an-array/
// Author : Diego Ruiz Piqueras (Pikeras72)
// Date   : 24-04-2022

/***************************************************************************************************** 
 *
 * There is a function signFunc(x) that returns:
 * 1 if x is positive.
 * -1 if x is negative.
 * 0 if x is equal to 0.
 * 
 * You are given an integer array nums. Let product be the product of all values in the array nums.
 * 
 * Return signFunc(product).
 * 
 * Example 1:
 * 
 * Input: nums = [-1,-2,-3,-4,3,2,1]
 * Output: 1
 * Explanation: The product of all values in the array is 144, and signFunc(144) = 1
 * 
 * Example 2:
 *
 * Input: nums = [1,5,0,2,-3]
 * Output: 0
 * Explanation: The product of all values in the array is 0, and signFunc(0) = 0
 * 
 * Example 3:
 *
 * Input: nums = [-1,1,-1,1,-1]
 * Output: -1
 * Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
 * 
 * Constraints:
 * 
 *  1 <= nums.length <= 1000
 *  -100 <= nums[i] <= 100
 * 
 * Explanation of the solution:
 * 
 * 1. We analyze all the numbers in 'nums', if we encounter a 0, we return 0.
 * 
 * 2. If we find a negative number we add 1 to de counter 'cnt', once we have finished analyzing,
 *    we return -1 if there is an odd number of '-' symbols. Otherwise we return 1.
 ******************************************************************************************************/

class Solution {
   public int arraySign(int[] nums) {
       String num = "";
       int cnt = 0;
       for(int i : nums){
           if(i == 0){
               return 0;
           }else if(i < 0){
               cnt++;
           }
       }
       if(cnt % 2 == 0){return 1;}else{return -1;}
    }
}
