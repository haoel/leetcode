// Source : https://leetcode.com/problems/move-zeroes/
// Author : Calinescu Valentin
// Date   : 2015-10-21

/*************************************************************************************** 
 *
 * Given an array nums, write a function to move all 0's to the end of it while 
 * maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should
 * be [1, 3, 12, 0, 0].
 * 
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *               
 ***************************************************************************************/



/* 
 * Solutions
 * =========
 *
 * One solution would be to store the position of the next non-zero element of the array.
 * Every position of the array, starting with position 0, must store this next non-zero
 * element until we can no more do that, case in which we need to add the remaining zeros
 * that we skipped.
 * 
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, poz = 0;
        for(i = 0; i < nums.size() && poz < nums.size(); i++)
        {
                while(nums[poz] == 0)
                    poz++;
                if(poz < nums.size())
                    nums[i] = nums[poz];
                else
                    i--; // we need 0 on position i, but i is increasing one last time
                poz++;
        }
        for(; i < nums.size(); i++)
            nums[i] = 0;
    }
};
