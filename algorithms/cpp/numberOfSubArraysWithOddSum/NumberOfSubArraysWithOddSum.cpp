// Source : https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
// Author : Hao Chen
// Date   : 2020-10-07

/***************************************************************************************************** 
 *
 * Given an array of integers arr. Return the number of sub-arrays with odd sum.
 * 
 * As the answer may grow large, the answer must be computed modulo 10^9 + 7.
 * 
 * Example 1:
 * 
 * Input: arr = [1,3,5]
 * Output: 4
 * Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
 * All sub-arrays sum are [1,4,9,3,8,5].
 * Odd sums are [1,9,3,5] so the answer is 4.
 * 
 * Example 2:
 * 
 * Input: arr = [2,4,6]
 * Output: 0
 * Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
 * All sub-arrays sum are [2,6,12,4,10,6].
 * All sub-arrays have even sum and the answer is 0.
 * 
 * Example 3:
 * 
 * Input: arr = [1,2,3,4,5,6,7]
 * Output: 16
 * 
 * Example 4:
 * 
 * Input: arr = [100,100,99,99]
 * Output: 4
 * 
 * Example 5:
 * 
 * Input: arr = [7]
 * Output: 1
 * 
 * Constraints:
 * 
 * 	1 <= arr.length <= 10^5
 * 	1 <= arr[i] <= 100
 ******************************************************************************************************/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        //Walk through the array, and calculate the current sum
        //if current sum is odd, then all of the sum are evil previously are valid sub-array
        //if current sum is evil, then all of the sum are odd previously are valid sub-array
        int odd_sum_cnt=0, evil_sum_cnt=0;
        int sum = 0;
        long long result=0;
        for (auto a : arr) {
            sum += a;
            if (sum % 2 == 0) {
                evil_sum_cnt++;
                result += odd_sum_cnt;
            }else {
                odd_sum_cnt++;
                result += evil_sum_cnt + 1;
            }
        }

        return result % 1000000007;

    }
};
