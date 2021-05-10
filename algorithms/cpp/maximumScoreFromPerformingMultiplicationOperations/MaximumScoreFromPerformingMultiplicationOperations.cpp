// Source : https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
// Author : Hao Chen
// Date   : 2021-04-01

/***************************************************************************************************** 
 *
 * You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. 
 * The arrays are 1-indexed.
 * 
 * You begin with a score of 0. You want to perform exactly m operations. On the i^th operation 
 * (1-indexed), you will:
 * 
 * 	Choose one integer x from either the start or the end of the array nums.
 * 	Add multipliers[i] * x to your score.
 * 	Remove x from the array nums.
 * 
 * Return the maximum score after performing m operations.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3], multipliers = [3,2,1]
 * Output: 14
 * Explanation: An optimal solution is as follows:
 * - Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
 * - Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
 * - Choose from the end, [1], adding 1 * 1 = 1 to the score.
 * The total score is 9 + 4 + 1 = 14.
 * 
 * Example 2:
 * 
 * Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
 * Output: 102
 * Explanation: An optimal solution is as follows:
 * - Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
 * - Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
 * - Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
 * - Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
 * - Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
 * The total score is 50 + 15 - 9 + 4 + 42 = 102.
 * 
 * Constraints:
 * 
 * 	n == nums.length
 * 	m == multipliers.length
 * 	1 <= m <= 10^3
 * 	m <= n <= 10^5 
 * 	-1000 <= nums[i], multipliers[i] <= 1000
 ******************************************************************************************************/

const int MAX_SIZE = 1000;
class Solution {
private:
    int cache[MAX_SIZE][MAX_SIZE]; // num of left picked, num of right picked.
    int m, n;
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(cache, -1, sizeof(cache));
        n = nums.size();
        m = multipliers.size();
        return maximumScoreDFS(nums, 0, n-1, multipliers, 0 );
    }
    
    int maximumScoreDFS(vector<int>& nums, int left, int right, 
                        vector<int>& multipliers, int midx) {
        
        if(midx >= m )  return 0;
        
        int nLeft = left; // num of left nums[] picked.
        int nRight = (n-1)-right; // num of right nums[] picked.
        if (cache[nLeft][nRight]!=-1) return cache[nLeft][nRight];
        
        int pickLeft = maximumScoreDFS(nums, left+1, right, multipliers, midx+1) +
            multipliers[midx] * nums[left];
        
        int pickRight = maximumScoreDFS(nums, left, right-1, multipliers, midx+1) +
            multipliers[midx] * nums[right];
        
        cache[nLeft][nRight] = max(pickLeft, pickRight);
        return cache[nLeft][nRight];
    }
};
