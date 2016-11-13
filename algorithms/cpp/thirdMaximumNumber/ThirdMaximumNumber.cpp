// Source : https://leetcode.com/problems/third-maximum-number/
// Author : Hao Chen
// Date   : 2016-11-12

/*************************************************************************************** 
 *
 * Given a non-empty array of integers, return the third maximum number in this array. 
 * If it does not exist, return the maximum number. The time complexity must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is returned 
 * instead.
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum distinct 
 * number.
 * Both numbers with value 2 are both considered as second maximum.
 ***************************************************************************************/

class Solution {
public:
    int nMax(vector<int>& nums, int n) {
        set<int> topN;
        for(auto num : nums) {
            topN.insert(num);
            if (topN.size() > n) topN.erase(topN.begin());
        }
        return (topN.size() >= n) ? *(topN.begin()) : *(topN.rbegin());
    }
    int thirdMax(vector<int>& nums) {
        return nMax(nums, 3);
    }
};
