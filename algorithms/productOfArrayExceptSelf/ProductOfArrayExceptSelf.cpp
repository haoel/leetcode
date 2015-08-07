// Source : https://leetcode.com/problems/product-of-array-except-self/
// Author : Hao Chen
// Date   : 2015-07-17

/********************************************************************************** 
 * 
 * Given an array of n integers where n > 1, nums, return an array output such that 
 * output[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * Solve it without division and in O(n).
 * 
 * For example, given [1,2,3,4], return [24,12,8,6].
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not 
 * count as extra space for the purpose of space complexity analysis.)
 *               
 **********************************************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> result(len, 1);
        
        //from the left to right 
        for (int i=1; i<len; i++) {
            result[i] = result[i-1]*nums[i-1];
        }
        //from the right to left
        int factorial = 1;
        for (int i=len-2; i>=0; i--){
            factorial *= nums[i+1];
            result[i] *= factorial;
        }
        return result;
    }
};



