// Source : https://leetcode.com/problems/burst-balloons/
// Author : Hao Chen
// Date   : 2016-01-17

/*************************************************************************************** 
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 *     number on it represented by array nums.
 * 
 *     You are asked to burst all the balloons. If the you burst
 *     balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left
 *     and right are adjacent indices of i. After the burst, the left and right
 *     then becomes adjacent.
 * 
 *     Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 *     Note: 
 *     (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can 
 * not burst them.
 *     (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 *     Example:
 * 
 *     Given [3, 1, 5, 8]
 * 
 *     Return 167
 * 
 *     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 *    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/



class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //remove all of zero item
        nums.erase(remove_if(nums.begin(), nums.end(), [](int n){return n==0;}), nums.end());
        
        //add 1 for head and tail
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        int n = nums.size();
        vector< vector<int> > matrix(n, vector<int>(n,0));
        
        return maxCoins_DP(nums, matrix);
        return maxCoins_DC(nums, matrix, 0, n-1);
    }
    
    
    //Divide and Conquer
    //
    //  If we seprate the array to two part, left part and right part.
    //
    //  Then, we will find in this problem the left and right become adjacent 
    //  and have effects on the maxCoins in the future.
    //
    //  So, if we think reversely, if the balloon i is the last balloon of all to burst, 
    //  the left and right section now has well defined boundary and do not affect each other! 
    //  Therefore we can do either recursive method with memoization
    //
    int maxCoins_DC(vector<int>& nums, vector<vector<int>>& matrix, int low, int high) {
        if (low + 1 == high) return 0;
        if (matrix[low][high] > 0) return matrix[low][high];
        int result = 0;
        for (int i = low + 1; i < high; ++i){
            result = max(result,  nums[low] * nums[i] * nums[high] 
                                    + maxCoins_DC(nums, matrix, low, i) 
                                    + maxCoins_DC(nums, matrix, i, high));
        }
        matrix[low][high] = result;
        return result;
    }
    
    //Dynamic Programming
    // 
    //  using the same idea of above 
    //
    int maxCoins_DP(vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        for (int k = 2; k < n; ++k) {
            for (int low = 0; low < n - k; low++){
                int high = low + k;
                for (int i = low + 1; i < high; ++i)
                    dp[low][high] = max( dp[low][high],
                         nums[low] * nums[i] * nums[high] + dp[low][i] + dp[i][high]);
            }
        }
        return dp[0][n - 1];
    }
    
private:
    void printVector(vector<int>& nums) {
        cout << "nums: ";
        for (auto n: nums) {
            cout << n << ' ';
        }
        cout << '\n';
    }
};
