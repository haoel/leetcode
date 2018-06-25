// Source : https://leetcode.com/problems/partition-equal-subset-sum/description/
// Author : Hao Chen
// Date   : 2018-06-24

/*************************************************************************************** 
 *
 * Given a non-empty array containing only positive integers, find if the array can be 
 * partitioned into two subsets such that the sum of elements in both subsets is equal.
 * 
 * 
 * Note:
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 ***************************************************************************************/

class Solution {
public:
    //back tracking
    bool canPartitionRecrusion(vector<int>& nums, int half, int index) {
        for (int i=index; i<nums.size(); i++){
            int h = half - nums[i];
            if ( h < 0 ) return false; //cannot found the solution
            if ( h == 0 ) return true; //found the solution
            if ( canPartitionRecrusion(nums, h, i+1) == true ) return true;
        }
        return false;
    }

    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums) sum +=n;
        if ( sum & 1 ) return false; // sum % 2 !=  1
        int half = sum / 2;
        
        //sort the array in descending order
        //so, the DFS could be very fast to find the answer because it's greedy.
        std::sort(nums.begin(), nums.end(), std::greater<int>()); 

        //go to find a path which sum is half
        return canPartitionRecrusion(nums, half, 0);
    }
};
