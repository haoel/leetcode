// Source : https://leetcode.com/problems/house-robber-ii/
// Author : Hao Chen
// Date   : 2015-06-10

/********************************************************************************** 
 * 
 * Note: This is an extension of House Robber.
 * 
 * After robbing those houses on that street, the thief has found himself a new place 
 * for his thievery so that he will not get too much attention. This time, all houses 
 * at this place are arranged in a circle. That means the first house is the neighbor 
 * of the last one. Meanwhile, the security system for these houses remain the same as
 * for those in the previous street. 
 * 
 * Given a list of non-negative integers representing the amount of money of each house, 
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
 *               
 **********************************************************************************/


class Solution {
public:
    int orginal_rob(vector<int> &money, int start, int end) {
        int n2=0; 
        int n1=0; 
        
        for (int i=start; i<end; i++){
            int current = max(n1, n2 + money[i]);
            n2 = n1;
            n1 = current;
        }
        return n1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        switch (n) {
            case 0:
                return 0;
            case 1:
                return nums[0];
            case 2:
                return max(nums[0], nums[1]);
            default:
                /*
                 * the idea is we cannot rob[0] and rob[n-1] at same time
                 * so, we rob [0 .. n-2] or [1 .. n-1], can return the maxinum one.
                 */
                int m1 = orginal_rob(nums, 0, n-1);
                int m2 = orginal_rob(nums, 1, n);
                
                return max(m1, m2);
        }
    }
};
