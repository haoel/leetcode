// Source : https://leetcode.com/problems/maximize-score-after-n-operations/submissions/
// Author : Hao Chen
// Date   : 2021-03-23

/***************************************************************************************************** 
 *
 * You are given nums, an array of positive integers of size 2 * n. You must perform n operations on 
 * this array.
 * 
 * In the i^th operation (1-indexed), you will:
 * 
 * 	Choose two elements, x and y.
 * 	Receive a score of i * gcd(x, y).
 * 	Remove x and y from nums.
 * 
 * Return the maximum score you can receive after performing n operations.
 * 
 * The function gcd(x, y) is the greatest common divisor of x and y.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2]
 * Output: 1
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(1, 2)) = 1
 * 
 * Example 2:
 * 
 * Input: nums = [3,4,6,8]
 * Output: 11
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
 * 
 * Example 3:
 * 
 * Input: nums = [1,2,3,4,5,6]
 * Output: 14
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 * 
 * Constraints:
 * 
 * 	1 <= n <= 7
 * 	nums.length == 2 * n
 * 	1 <= nums[i] <= 10^6
 ******************************************************************************************************/

class Solution {
private:
    // Euclidean algorithm
    // https://en.wikipedia.org/wiki/Euclidean_algorithm
    int gcd(int a, int b) {
        while(a != b) {
            if(a > b) a = a - b;
            else b = b - a;
        }
        return a;
    }
    unordered_map<int, int> cache;
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> pair_gcd(n, vector<int>(n, 0) );
        
        for (int i=0; i< n - 1; i++) {
            for (int j=i+1; j < n; j++ ) {
                pair_gcd[i][j] = gcd(nums[i], nums[j]);
            }
        }
        
        // used_mark[] - remember the num has been used.
        return maxScore(pair_gcd, 0, n, n/2);
    }
    
    int maxScore(vector<vector<int>>& pair_gcd, int mask, int n, int step) {
        if (cache.find(mask) != cache.end()) {
            return cache[mask];
        }
        int m = 0;
        
        for (int i=0; i< n - 1; i++) {
            if ( (1<<i) & mask ) continue;
            for (int j=i+1; j < n; j++ ) {
                if ((1<<j) & mask) continue;
                if (step == 1) {
                    return pair_gcd[i][j];
                }
                
                m = max(m, step * pair_gcd[i][j] + 
                        maxScore(pair_gcd, mask | (1<<i) | (1<<j), n, step-1));
                
            }
        }
        
        cache[mask] = m;
        return m;
    }
};
