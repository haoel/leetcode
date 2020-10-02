// Source : https://leetcode.com/problems/target-sum/
// Author : Bhavesh Mandhan
// Date   : 2020-10-21


/**********************************************************************************
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
 * Now you have 2 symbols + and -. For each integer, you should choose one from + and - 
 * as its new symbol.
 *
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 *
 * 	For example, given array nums is [1, 1, 1, 1, 1], S is 3.
 *
 * 	There are 5 ways to assign symbols to make the sum of nums be target 3.
 *
 * 	-1+1+1+1+1 = 3
 * 	+1-1+1+1+1 = 3
 * 	+1+1-1+1+1 = 3
 * 	+1+1+1-1+1 = 3
 * 	+1+1+1+1-1 = 3

***********************************************************************************/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long int i,j,n,tot=0,sum,zero=0;
        n = nums.size();
        for(i=0;i<n;i++){
            tot+=nums[i];
            if(nums[i]==0){
                zero++;
            }
        }
        if((S+tot)%2!=0 || S>tot){
            return 0;
        }
        sum = (S+tot)/2;
        int dp[n+1][sum+1];
        for(i=1;i<=sum;i++){
            dp[0][i]= 0;
        }
        for(i=0;i<=n;i++){
            dp[i][0]= 1;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=sum;j++){
                if(nums[i-1]==0 || nums[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        return pow(2,zero)*dp[n][sum];
    }
};
