// Source : https://leetcode.com/problems/count-nice-pairs-in-an-array/
// Author : Hao Chen
// Date   : 2021-04-06

/***************************************************************************************************** 
 *
 * You are given an array nums that consists of non-negative integers. Let us define rev(x) as the 
 * reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of 
 * indices (i, j) is nice if it satisfies all of the following conditions:
 * 
 * 	0 <= i < j < nums.length
 * 	nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
 * 
 * Return the number of nice pairs of indices. Since that number can be too large, return it modulo 
 * 10^9 + 7.
 * 
 * Example 1:
 * 
 * Input: nums = [42,11,1,97]
 * Output: 2
 * Explanation: The two pairs are:
 *  - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 *  - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
 * 
 * Example 2:
 * 
 * Input: nums = [13,10,35,24,76]
 * Output: 4
 * 
 * Constraints:
 * 
 * 	1 <= nums.length <= 10^5
 * 	0 <= nums[i] <= 10^9
 ******************************************************************************************************/

class Solution {
private:
    int rev(int n) {
        int x = 0;
        while(n > 0) {
            x = x*10 + (n % 10);
            n /= 10;
        }
        return x;
    }

public:
    int countNicePairs(vector<int>& nums) {
        return countNicePairs02(nums);
        return countNicePairs01(nums);
    }
    int countNicePairs01(vector<int>& nums) {
        // suppose n' = rev(n) 
        // define:  a + b' == b + a'
        //   then:  a - a' == b - b'
        
        unordered_map<int, int> stat;
        for(auto& n : nums) {
            stat[n-rev(n)]++;
            
        }
        
        //if there are n elements  has same value, 
        // then there are  n*(n-1)/2 unique pairs.
        int result = 0;
        for(auto& [n, cnt] : stat) {
            result  =  (result + cnt * (cnt -1l) / 2)  % 1000000007;
        }
        return result;
    }
    
    int countNicePairs02(vector<int>& nums) {
        // suppose n' = rev(n) 
        // define:  a + b' == b + a'
        //   then:  a - a' == b - b'
        int result = 0;
        unordered_map<int, int> stat;
        for(auto& n : nums) {
            int delta = n-rev(n);
            stat[delta]++;
            result = (result + (stat[delta] - 1l)) % 1000000007 ;
        }
        
        return result ;
    }
};
