// Source : https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
// Author : Hao Chen
// Date   : 2021-03-21

/***************************************************************************************************** 
 *
 * You are given three positive integers n, index and maxSum. You want to construct an array nums 
 * (0-indexed) that satisfies the following conditions:
 * 
 * 	nums.length == n
 * 	nums[i] is a positive integer where 0 <= i < n.
 * 	abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
 * 	The sum of all the elements of nums does not exceed maxSum.
 * 	nums[index] is maximized.
 * 
 * Return nums[index] of the constructed array.
 * 
 * Note that abs(x) equals x if x >= 0, and -x otherwise.
 * 
 * Example 1:
 * 
 * Input: n = 4, index = 2,  maxSum = 6
 * Output: 2
 * Explanation: The arrays [1,1,2,1] and [1,2,2,1] satisfy all the conditions. There are no other 
 * valid arrays with a larger value at the given index.
 * 
 * Example 2:
 * 
 * Input: n = 6, index = 1,  maxSum = 10
 * Output: 3
 * 
 * Constraints:
 * 
 * 	1 <= n <= maxSum <= 109
 * 	0 <= index < n
 ******************************************************************************************************/

/*

This problem can be treat as a pyramid which shaped by 1, it looks like below:

        1
      1 1 1
    1 1 1 1 1
  1 1 1 1 1 1 1
So, from the top, for each layer, we need the 1,3,5,7,9.... 2*n-1 ONE(s).

But we need to deal with the edge case - it could be out of the array boundary

For example: index=2, lenght=3, maxSum=18

      1) at first, we put  `1 1 1` on bottom layer - Array[2] = 1

      2) then we start from the top 

                1   <-- the top first layer
            1 1 1   <-- bottom 
            
         now, we have Array[2] is 2

      3) we keep doing tthe 2nd layer - Array[2] = 3
                1      <-- the 1st layer
              1 1 [1]  <-- the 2nd layer, which has 1 out of the boundary
            1 1 1      <-- bottom 
            
         now, we have Array[2] is 3

      4) the 3rd layer  -  Array[2] = 4 
                1         <-- the 1st layer
              1 1 [1]     <-- the 2nd layer, which has 1 out of the boundary
            1 1 1 [1] [1] <-- the 3rd layer, which has 2 out of the boundary
            1 1 1         <-- bottom 
            
         now, we have Array[2] is 4
   		 
      5) Now, the rest layers no need to be cacluated, they all are `3`.
         Since 4), we spent 9 of `1`,  we still have 18 - 9 = 9 of `1`
         So, we can have 9/3 = 3 layer.
         
      6) Finally, the maximum of Array[2] = 4 + 3 = 7
*/

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        // at least, put the bottom layer
        int maxValue = 1;
        maxSum -= n;
        int layer = 1;
        
        int points;
        while ( maxSum > 0 ) {
            // how many 1 we need
            points = (2 * layer - 1);
            
            // how many 1 exceed the right bound
            int right = (index + layer-1) - (n-1);
            if (right > 0)  points -= right;
            // how many 1 exceed the left bound
            int left = (layer - index - 1);
            if (left > 0)  points -= left;
           
            //  points >= n  -  we just need `n` for the rest layers 
            //  maxSum < points -  if we  haven't enough points 
            if (points >= n || maxSum < points) break;
            
            
            maxSum -= points;
            layer++;
            maxValue++;
        }
        // maxSum/n - we just need `n` for the rest layers
        return maxValue += (maxSum/n);
    }
};
