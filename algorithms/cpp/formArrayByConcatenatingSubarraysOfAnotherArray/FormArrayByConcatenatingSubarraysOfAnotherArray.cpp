// Source : https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
// Author : Hao Chen
// Date   : 2021-03-27

/***************************************************************************************************** 
 *
 * You are given a 2D integer array groups of length n. You are also given an integer array nums.
 * 
 * You are asked if you can choose n disjoint subarrays from the array nums such that the i^th 
 * subarray is equal to groups[i] (0-indexed), and if i > 0, the (i-1)^th subarray appears before the 
 * i^th subarray in nums (i.e. the subarrays must be in the same order as groups).
 * 
 * Return true if you can do this task, and false otherwise.
 * 
 * Note that the subarrays are disjoint if and only if there is no index k such that nums[k] belongs 
 * to more than one subarray. A subarray is a contiguous sequence of elements within an array.
 * 
 * Example 1:
 * 
 * Input: groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
 * Output: true
 * Explanation: You can choose the 0^th subarray as [1,-1,0,1,-1,-1,3,-2,0] and the 1^st one as 
 * [1,-1,0,1,-1,-1,3,-2,0].
 * These subarrays are disjoint as they share no common nums[k] element.
 * 
 * Example 2:
 * 
 * Input: groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
 * Output: false
 * Explanation: Note that choosing the subarrays [1,2,3,4,10,-2] and [1,2,3,4,10,-2] is incorrect 
 * because they are not in the same order as in groups.
 * [10,-2] must come before [1,2,3,4].
 * 
 * Example 3:
 * 
 * Input: groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
 * Output: false
 * Explanation: Note that choosing the subarrays [7,7,1,2,3,4,7,7] and [7,7,1,2,3,4,7,7] is invalid 
 * because they are not disjoint.
 * They share a common elements nums[4] (0-indexed).
 * 
 * Constraints:
 * 
 * 	groups.length == n
 * 	1 <= n <= 10^3
 * 	1 <= groups[i].length, sum(groups[i].length) <= 10^3
 * 	1 <= nums.length <= 10^3
 * 	-10^7 <= groups[i][j], nums[k] <= 10^7
 ******************************************************************************************************/

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        
        //constructing an length array
        //  lens[0] = len(groups[0]) + len(groups[1]) + ... len(groups[n])
        //  lens[1] = len(groups[1]) + len(groups[2]) + ... len(groups[n])
        //  lens[2] = len(groups[2]) + len(groups[3]) + ... len(groups[n])
        //  lens[n] = len(groups[n])
        //so that, we can quickly know whether there still has enough room to match rest groups
        vector<int> lens(groups.size());
        int total_len=0;
        for(int i=groups.size()-1; i >=0; i--) {
            total_len += groups[i].size();
            lens[i] = total_len;
        }
        
        // index i - loop for groups[]
        // index j - loop for nums[]
        int i = 0, j = 0; 
        while ( i < groups.size() && j < nums.size() ) {
            //if the rest room is not enought to match, return false;
            if (nums.size() - j < lens[i]) return false;
            
            //if the first char is not matched, check the next.
            if ( nums[j] != groups[i][0]) {
                j++;
                continue;
            }
            
            //if the first char is matched, then check the groups[i]
            bool match = true;
            for(int k=0; k<groups[i].size(); k++) {
                if ( nums[j+k] != groups[i][k]) {
                    match=false;
                    break;
                }
            }
            
            // if the groups[i] is matched, then go to next group
            if (match) {
                j += groups[i].size();
                i++;
            }else{
                j++;  
            }
        }
        
        return i == groups.size();
    }
};
