// Source : https://leetcode.com/problems/patching-array/
// Author : Hao Chen
// Date   : 2016-03-01

/*************************************************************************************** 
 *
 * Given a sorted positive integer array nums and an integer n, add/patch elements to 
 * the array such that any number in range [1, n] inclusive can be formed by the sum of 
 * some elements in the array. Return the minimum number of patches required.
 * 
 * Example 1:
 * nums = [1, 3], n = 6
 * Return 1.
 * 
 * Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
 * Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], 
 * [1,2,3].
 * Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
 * So we only need 1 patch.
 * 
 * Example 2:
 * nums = [1, 5, 10], n = 20
 * Return 2.
 * The two patches can be [2, 4].
 * 
 * Example 3:
 * nums = [1, 2, 2], n = 5
 * Return 0.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        return minPatches_02(nums, n);
        return minPatches_01(nums, n);
    }
    
    
    // Greedy Algorithm
    // (Assume the array is sorted already)
    //
    //   Let do some observation at first,
    //
    //     1) if we have [1,2] then we can cover 1, 2, 3
    //     2) if we have [1,2,3] then we can cover 1,2,3,4,5,6
    //     So, it looks we can simply add all of nums together, then we can find out max number we can reach.
    //
    //     3) if we have [1,2,5], we can see 
    //       3.1) [1,2] can cover 1,2,3, but we cannot reach 4, 
    //       3.2) then we patch 4, then we have [1,2,4] which can cover 1,2,3(1+2),4,5(1+4),6(2+4), 7(1+2+4)
    //       3.3) we can see [1,2,4] can reach to 7 - sum all of them
    //       3.4) then [1,2,4,5], we can reach to 12 - 1,2,3,4,5,6,7,8(1+2+5),9(4+5),10(1+4+5), 11(2+4+5), 12(1+2+4+5)
    //   
    //   So, we can have figure out our solution
    //
    //      0) considering the `n` we need to cover.
    //      1) maintain a variable we are trying to patch, suppose named `try_patch`
    //      2) if `try_patch` >= nums[i] then, we just keep add the current array item, 
    //         and set the `try_patch` to the next patch candidate number -  `sum+1`
    //      3) if `try_patch` < nums[i], which means we need to patch.
    //
    int minPatches_01(vector<int>& nums, int n) {
        long covered = 0; //avoid integer overflow
        int patch_cnt = 0;
        int i = 0;
        while (i<nums.size() ){
            // set the `try_patch` is the next number which we cannot cover
            int try_patch = covered + 1;
            // if the `try_patch` can cover the current item, then just sum it, 
            // then we can have the max number we can cover so far 
            if ( try_patch >= nums[i])  {
                covered += nums[i];  
                i++;
            } else { // if the `try_patch` cannot cover the current item, then we find the number we need to patch
                patch_cnt++;
                //cout << "patch " << try_patch << endl;
                covered = covered + try_patch;
            } 
            
            if (covered >=n) break;
        }
        //for the case - [1], 7
        //the above while-loop just process all of the numbers in the array, 
        //but we might not reach the goal, so, we need keep patching.
        while (covered < n) {
            int try_patch = covered + 1;
            patch_cnt++;
            //cout << "patch " << try_patch << endl;
            covered = covered + try_patch;
        }
        return patch_cnt;
    }
    
    
    //The following solution just re-organizes the solution above, and make it shorter 
    int minPatches_02(vector<int>& nums, int n) {
        long covered = 0;
        int patch_cnt = 0;
        int i = 0;
        while ( covered < n){
            if (i<nums.size() && nums[i] <= covered + 1) {
                covered += nums[i++];
            }else{
                //cout << "patch " << covered + 1 << endl;
                covered = 2 * covered + 1;
                patch_cnt++;
            }
        }
        return patch_cnt;
    }
};
