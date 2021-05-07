// Source : https://leetcode.com/problems/maximum-erasure-value/
// Author : Hao Chen
// Date   : 2021-05-07

/***************************************************************************************************** 
 *
 * You are given an array of positive integers nums and want to erase a subarray containing unique 
 * elements. The score you get by erasing the subarray is equal to the sum of its elements.
 * 
 * Return the maximum score you can get by erasing exactly one subarray.
 * 
 * An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if 
 * it is equal to a[l],a[l+1],...,a[r] for some (l,r).
 * 
 * Example 1:
 * 
 * Input: nums = [4,2,4,5,6]
 * Output: 17
 * Explanation: The optimal subarray here is [2,4,5,6].
 * 
 * Example 2:
 * 
 * Input: nums = [5,2,1,2,5,2,1,2,5]
 * Output: 8
 * Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 10^5
 * 	1 <= nums[i] <= 10^4
 ******************************************************************************************************/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //unordered_map<int, int> pos;
        const int NIL = -1;
        int pos[10001];
        memset(pos, NIL, sizeof(pos));
        
        int start=0;
        int max_sum =0, sum = 0;
 
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            // if find duplicated number
            if ( pos[n] != NIL) {
                max_sum = max(max_sum, sum);
                //remove the previous numbers until to duplicatied position 
                for(;start <= pos[n]; start++){
                    sum -= nums[start];
                    pos[nums[start]] = NIL;
                }
            }
            sum += n;
            pos[n] = i;
        }
        max_sum = max( max_sum , sum );
        return max_sum;
    }
};
