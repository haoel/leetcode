// Source : https://leetcode.com/problems/move-zeroes/
// Author : Calinescu Valentin, Hao Chen
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



class Solution {
public:
    /* 
     * Solution (Calinescu Valentin)
     * ==============================
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



    /*
     * Another implemtation which is easy to understand (Hao Chen)
     * ===========================================================
     *
     * We have two pointers to travel the array, assume they named `p1` and `p2`.
     * 
     *   1) `p1` points the tail of current arrays without any ZEROs.
     *   2) `p2` points the head of the rest array which skips the ZEROs.
     * 
     * Then we can just simply move the item from `p2` to `p1`.
     *
     */
    void moveZeroes(vector<int>& nums) {
        int p1=0, p2=0;

        // Find the first ZERO, where is the tail of the array.
        // (Notes: we can simply remove this!)
        for (; nums[p1]!=0 && p1<nums.size(); p1++);
        
        // copy the item from p2 to p1, and skip the ZERO
        for (p2=p1; p2<nums.size(); p2++) {
            if ( nums[p2] == 0 ) continue;
            nums[p1++] = nums[p2]; 
        }    
        
        //set ZERO for rest items 
        while ( p1<nums.size() ) nums[p1++] = 0;
    }

};
