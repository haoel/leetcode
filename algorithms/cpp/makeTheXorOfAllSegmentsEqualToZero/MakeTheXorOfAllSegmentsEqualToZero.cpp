// Source : https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/
// Author : Hao Chen
// Date   : 2021-03-20

/***************************************************************************************************** 
 *
 * You are given an array nums​​​ and an integer k​​​​​. The XOR of a segment [left, right] where left 
 * <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] 
 * XOR nums[left+1] XOR ... XOR nums[right].
 * 
 * Return the minimum number of elements to change in the array such that the XOR of all segments of 
 * size k​​​​​​ is equal to zero.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,0,3,0], k = 1
 * Output: 3
 * Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].
 * 
 * Example 2:
 * 
 * Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
 * Output: 3
 * Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].
 * 
 * Example 3:
 * 
 * Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
 * Output: 3
 * Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].
 * 
 * Constraints:
 * 
 * 	1 <= k <= nums.length <= 2000
 * 	​​​​​​0 <= nums[i] < 210
 ******************************************************************************************************/

/*
    First K length subarray: 
                            a1^a2^a3^.....^ak=0 ;

    Second K length subarray :
                            a2^a3^a4^....^ak+1=0 ; 

    On combining both : 
                            a1^(a2^a3^....^ak)^(a2^a3^....^ak)^a[k+1] =0 
                            a1^a[k+1]=0
    Therefore it is easy to see that for any i and j : 

                            a[i%k]^a[j%k] = 0 ;
                        ->  a[i%k]=a[j%k] ;

    Hence, a[1] = a[k+1] = a[2k+1] = ...
           a[2] = a[k+2] = a[2k+2] = ...
           a[3] = a[k+3] = a[2k+3] = ...
           .
           .
           .
           a[k] = a[2k] = a[3k] = ...

    So we just need to obtain the first k length subarray and the rest would be determined by it.

*/


class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        
        const int max_value = 1024; //0 <= nums[i] < 2^10
        int n = nums.size();
        
        //freq[i][v] means frequency of the number `v` at `i` position in [0, k-1];
        vector<vector<int>> freq(k, vector<int>(max_value, 0));
        for (int i=0; i<n; i++) {
            freq[i%k][nums[i]]++;
        }
        
        //dp[i][v] means minimum number of changes in first i elements such that the xor value is `v`
        vector<vector<int>> dp(k, vector<int>(max_value, n+1));
        
        //initailization
        int minChanges = n + 1;
        for (int v = 0; v < max_value; v++) {
            int cntOfPos = n / k + (((n % k) > 0) ? 1 : 0);
            dp[0][v] = cntOfPos - freq[0][v];
            minChanges = min(minChanges, dp[0][v]);
        } 
        
        for (int i=1; i<k; i++) {
            // how many i indices exist in the array
            int cntOfPos = n / k + (((n % k) > i) ? 1 : 0);

            //track minimum changes
            int m = n + 1;
            
            //for all of possible values
            for (int v = 0; v < max_value; v++) {

                for (int j = i; j < n; j += k) {
                    int x = v ^ nums[j];
                    dp[i][v] = min( dp[i][v], dp[i-1][x] + cntOfPos - freq[i][nums[j]]);
                }
                //for all of numbers don't occur at index i
                dp[i][v] = min(dp[i][v], minChanges + cntOfPos);

                m = min(m, dp[i][v]);
            }
            minChanges = m;
        }   
        return dp[k-1][0];
    }
    
};
