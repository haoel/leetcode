// Source : https://leetcode.com/problems/maximum-score-of-a-good-subarray/
// Author : Hao Chen
// Date   : 2021-03-19

/***************************************************************************************************** 
 *
 * You are given an array of integers nums (0-indexed) and an integer k.
 * 
 * The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A 
 * good subarray is a subarray where i <= k <= j.
 * 
 * Return the maximum possible score of a good subarray.
 * 
 * Example 1:
 * 
 * Input: nums = [1,4,3,7,4,5], k = 3
 * Output: 15
 * Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
 * 
 * Example 2:
 * 
 * Input: nums = [5,5,4,5,4,1,1,1], k = 0
 * Output: 20
 * Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 105
 * 	1 <= nums[i] <= 2 * 104
 * 	0 <= k < nums.length
 ******************************************************************************************************/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int score = nums[k];
        int m = score;
        int left = k, right = k;
        int l = left, r = right;
        while (left>0 || right < nums.size()-1){
            
            if ( left > 0 && right < nums.size()-1 ) {
                if (nums[left-1] > nums[right+1]) {
                    left--;
                } else if (nums[left-1] < nums[right+1]) {
                    right++;
                } else {
                    left--;right++;
                }
            }else if ( left <= 0 ) {
                right++;
            }else if ( right >= nums.size() -1 ) { 
                left--;
            }else {
                break;
            }
            
            m = min(m, min( nums[left], nums[right]));
            int s = m * (right - left + 1);
            if ( s > score) {
                score = s;
                l = left;  r = right;
            }
        }
        
        //cout << "[" << l << "," << r << "] = " << score << endl;
        
        return score;
    }
};
